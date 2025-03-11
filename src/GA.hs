module GA (initializePopulation, gaIterate) where 

import System.Random (newStdGen, randomRs)
import Data.List.Split (chunksOf)
import Heuristics (simiulatedBinary, gaussianMutate, tournamentSelection)
import Benchmark (sphere)
import Helpers (beta, randomNumbers, normalNoise)

initializePopulation :: Int -> Int -> IO ([[Double]])
initializePopulation numIndividual chromosome  = do
  gen <- newStdGen
  let population = take (numIndividual * chromosome) (randomRs (-1, 1) gen :: [Double])
  return $ chunksOf chromosome population

-- population -> fitness function -> fitnesses
evaluate :: [[Double]] -> ([Double] -> Double) -> [Double]
evaluate population f = map f population

gaIterate :: Int -> [[Double]] -> Int -> Int -> Double -> IO ()
gaIterate iter population elites selectionSize distributionIndex
  | iter == 10000 = do
    putStrLn $ "Terminated after " ++ show iter ++ " iterations."
    -- print $ evaluate population sphere
  | iter `mod` 100 == 0 = do
    putStrLn $ "Iteration " ++ show iter
    -- print $ evaluate population sphere
    print $ length $ evaluate population sphere
    print $ minimum $ evaluate population sphere
    let populationSize = length population
    beta_ <- beta distributionIndex
    randNS <- randomNumbers (populationSize*selectionSize) populationSize
    let selectedPopulation = tournamentSelection population (evaluate population sphere) (randNS) elites selectionSize
    let offspring = concat $ zipWith (\x y -> simiulatedBinary x y beta_) (take (div populationSize 2) selectedPopulation) (drop (div populationSize 2) selectedPopulation)
    let offspringSize = length $ offspring!!0
    randNM <- randomNumbers offspringSize 10
    normalN <- normalNoise offspringSize
    let mutated = map (\x -> gaussianMutate x (randNM) (normalN)) offspring
    let newPopulation = mutated
    -- print $ evaluate newPopulation sphere
    gaIterate (iter+1) newPopulation elites selectionSize distributionIndex
  | otherwise = do
    let populationSize = length population
    beta_ <- beta distributionIndex
    randNS <- randomNumbers (populationSize*selectionSize) populationSize
    let selectedPopulation = tournamentSelection population (evaluate population sphere) (randNS) elites selectionSize
    let offspring = concat $ zipWith (\x y -> simiulatedBinary x y beta_) (take (div populationSize 2) selectedPopulation) (drop (div populationSize 2) selectedPopulation)
    let offspringSize = length $ offspring!!0
    randNM <- randomNumbers offspringSize 10
    normalN <- normalNoise offspringSize
    let mutated = map (\x -> gaussianMutate x (randNM) (normalN)) offspring
    let newPopulation = mutated
    gaIterate (iter+1) newPopulation elites selectionSize distributionIndex
