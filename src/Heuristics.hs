module Heuristics (simiulatedBinary, gaussianMutate) where

import Data.List (sortBy)

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

tournamentSelection :: [[Double]] -> [Double] -> [Int]
tournamentSelection population fitness indexes = zip [0..] fitness
