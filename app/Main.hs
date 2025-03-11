module Main where

import GA (initializePopulation, gaIterate)

main :: IO ()
main = do
  population <- initializePopulation 1000 100
  -- print population
  -- print $ evaluate population sphere
  -- print $ simiulatedBinary [-1,-2,-3] [-4,-5,-6] 0.5
  -- beta_ <- beta 0.5
  -- print beta_
  -- print $ gaussianMutate [1,2,3] [1, 5, 0] [3, 100, 1]
  -- print $ sortFitness $ evaluate population sphere
  -- let sorted = sortFitness $ evaluate population sphere
  -- print $ tournamentSelectionHelper sorted [0,2,3,4,5,6,7,8,9,0] 5 2
  -- print $ tournamentSelection population (evaluate population sphere) [0,2,3,4,5,6,7,8,9,0] 5 2
  -- rand <- randomNumbers 10 10
  -- print $ rand
  -- noise <- normalNoise 10
  -- print $ noise
  -- let l = zipWith (\x y -> simiulatedBinary x y beta_) (take (div 10 2) population) (drop (div 10 2) population)
  -- print $ concat l
  -- [[[1,2],[3,4]],[[5,6],[7,8]]] but I want [[1,2], [3,4], [5,6], [7,8]]
  gaIterate 0 population 200 2 2.0
