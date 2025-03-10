module Heuristics (simiulatedBinary, gaussianMutate, tournamentSelection, sortFitness) where

import Data.List (sort)

simiulatedBinary :: [Double] -> [Double] -> Double -> [[Double]]
simiulatedBinary par1 par2 beta = (zipWith (\x y -> max 0.0 (min 0.5 (((1 + beta) * x) + ((1 - beta) * y)))) par1 par2) :
                                  (zipWith (\x y -> max 0.0 (min 0.5 (((1 - beta) * x) + ((1 + beta) * y)))) par1 par2) :
                                  []

gaussianMutate :: [Double] -> [Double] -> [Double] -> [Double]
gaussianMutate offspring shouldMutates noises = 
    zipWith3 (\gene shouldMutate noise ->
        if shouldMutate < 0.2 
            then max 0.0 (min 0.5 (gene + noise))
            else gene)
        offspring shouldMutates noises

tournamentSelection :: [[Double]] -> [(Double, Int)] -> [Int] -> Int -> Int -> [(Double, Int)]
tournamentSelection population sorted selectionIndexes elites selectionCriteria
  | elites /= 0             = take elites sorted ++ selection !! 0 : tournamentSelection population sorted remaining 0 selectionCriteria
  | selectionIndexes == [] = []
  | otherwise               = selection !! 0 : tournamentSelection population sorted remaining 0 selectionCriteria
  where (selected, remaining) = splitAt selectionCriteria selectionIndexes
        selection = sort $ map (sorted !!) selected

sortFitness :: [Double] -> [(Double, Int)]
sortFitness fitness = sort $ zip fitness [0..]
