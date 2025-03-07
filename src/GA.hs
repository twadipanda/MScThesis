module GA (initializePopulation, evaluate) where 

import System.Random (newStdGen, randomRs)
import Data.List.Split (chunksOf)

initializePopulation :: Int -> Int -> IO ([[Double]])
initializePopulation numIndividual chromosome  = do
  gen <- newStdGen
  let population = take (numIndividual * chromosome) (randomRs (-1, 1) gen :: [Double])
  return $ chunksOf numIndividual population

-- population -> fitness function -> fitnesses
evaluate :: [[Double]] -> ([Double] -> Double) -> [Double]
evaluate population f = map f population

-- iterate :: 