module Heuristics (simiulatedBinary, gaussianMutate, tournamentSelection) where

import Control.Parallel.Strategies (using, parList, rdeepseq)
import Data.List (sort)
import Helpers (sortFitness)

simiulatedBinary :: [Double] -> [Double] -> Double -> [[Double]]
simiulatedBinary par1 par2 beta = (zipWith (\x y -> max 0.0 (min 0.5 (((1 + beta) * x) + ((1 - beta) * y)))) par1 par2) :
                                  (zipWith (\x y -> max 0.0 (min 0.5 (((1 - beta) * x) + ((1 + beta) * y)))) par1 par2) :
                                  []

gaussianMutate :: [Double] -> [Int] -> [Double] -> [Double]
gaussianMutate offspring shouldMutates noises = 
    zipWith3 (\gene shouldMutate noise ->
        if shouldMutate < 2 
            then max 0.0 (min 0.5 (gene + noise))
            else gene)
    offspring shouldMutates noises

tournamentSelectionHelper :: [(Double, Int)] -> [Int] -> Int -> Int -> [(Double, Int)]
tournamentSelectionHelper sorted selectionIndexes elites selectionSize
  | selectionIndexes == [] = []
  | elites /= 0            = take elites sorted ++ selection !! 0 : tournamentSelectionHelper sorted remaining 0 selectionSize
  | otherwise              = selection !! 0 : tournamentSelectionHelper sorted remaining 0 selectionSize
  where (selected, remaining) = splitAt selectionSize selectionIndexes
        selection = sort $ map (sorted !!) selected

tournamentSelection :: [[Double]] -> [Double] -> [Int] -> Int -> Int -> [[Double]]
tournamentSelection population fitness selectionIndexes elites selectionSize = 
    (map (\x -> population !! snd x) $ tournamentSelectionHelper (sortFitness fitness) selectionIndexes elites selectionSize)
