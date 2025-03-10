module Main where

import GA (initializePopulation, evaluate)
import Benchmark (sphere)
import Heuristics (simiulatedBinary, gaussianMutate, tournamentSelection, sortFitness)
import Helpers (beta)

main :: IO ()
main = do 
  population <- initializePopulation 10 10
  -- print population
  print $ evaluate population sphere
  print $ simiulatedBinary [-1,-2,-3] [-4,-5,-6] 0.5
  beta_ <- beta 0.5
  print beta_
  print $ gaussianMutate [1,2,3] [0.1, 0.5, 0.0] [3, 100, 1]
  print $ sortFitness $ evaluate population sphere
  let sorted = sortFitness $ evaluate population sphere
  print $ tournamentSelection population sorted [1,2,3,4,5,6,7,8,9,0] 5 2