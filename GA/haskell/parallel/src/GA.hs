module GA (initializePopulation, gaIterate) where 

import Control.Parallel.Strategies (using, parList, parListChunk, rdeepseq)
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
evaluate population f = map f population `using` parListChunk 100 rdeepseq

gaIterate :: Int -> [[Double]] -> Int -> Int -> Double -> IO (Double)
gaIterate iter population elites selectionSize distributionIndex
  | iter == 1000 = do
    putStrLn "Iterations completed"
    return $ minimum $ evaluate population sphere
  | otherwise = do
    let populationSize = length population
    beta_ <- beta distributionIndex
    randNS <- randomNumbers (populationSize*selectionSize) (populationSize - 1)
    let selectedPopulation = tournamentSelection population (evaluate population sphere) (randNS) elites selectionSize --`using` parListChunk 500 rdeepseq
    let elitePop = take elites selectedPopulation
    let nonElitePop = drop elites selectedPopulation
    let offspring = concat (zipWith (\x y -> simiulatedBinary x y beta_) (take (div (populationSize - elites) 2) nonElitePop) (drop (div (populationSize - elites) 2) nonElitePop)) `using` parListChunk 10 rdeepseq
    let offspringSize = length $ offspring!!0
    randNM <- randomNumbers offspringSize 9
    normalN <- normalNoise offspringSize
    let mutated = map (\x -> gaussianMutate x (randNM) (normalN)) offspring `using` parListChunk 10 rdeepseq
    let newPopulation = elitePop ++ mutated
    gaIterate (iter+1) newPopulation elites selectionSize distributionIndex
