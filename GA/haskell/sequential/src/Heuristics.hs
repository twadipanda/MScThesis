-- | This module provides heuristic operators for a Genetic Algorithm, including crossover, mutation, and selection.
module Heuristics (simiulatedBinary, gaussianMutate, tournamentSelection) where

import Data.List (sort)
import Helpers (sortFitness)

-- | Performs simulated binary crossover (SBX) between two parent individuals.
--
-- Generates two offspring by blending parent genes using a beta distribution parameter.
-- Ensures offspring genes stay within [0, 0.5].
--
-- Arguments:
--   * par1 - The first parent individual (list of genes).
--   * par2 - The second parent individual (list of genes).
--   * beta - The beta value controlling crossover spread.
--
-- Returns: A list containing two offspring individuals.
simiulatedBinary :: [Double] -> [Double] -> Double -> [[Double]]
simiulatedBinary par1 par2 beta = (zipWith (\x y -> max 0.0 (min 0.5 (((1 + beta) * x) + ((1 - beta) * y)))) par1 par2) :
                                  (zipWith (\x y -> max 0.0 (min 0.5 (((1 - beta) * x) + ((1 + beta) * y)))) par1 par2) :
                                  []

-- | Applies Gaussian mutation to an offspring individual.
--
-- Mutates genes with a probability based on 'shouldMutates', adding Gaussian noise to selected genes.
-- Ensures mutated genes stay within [0, 0.5].
--
-- Arguments:
--   * offspring - The individual to mutate.
--   * shouldMutates - List of integers indicating mutation probability (mutate if < 2).
--   * noises - List of Gaussian noise values to add.
--
-- Returns: The mutated individual.
gaussianMutate :: [Double] -> [Int] -> [Double] -> [Double]
gaussianMutate offspring shouldMutates noises = 
    zipWith3 (\gene shouldMutate noise ->
        if shouldMutate < 2 
            then max 0.0 (min 0.5 (gene + noise))
            else gene)
    offspring shouldMutates noises

-- | Helper function for tournament selection.
--
-- Selects individuals from a sorted fitness list based on tournament indices, preserving elites first.
--
-- Arguments:
--   * sorted - List of (fitness, index) pairs, sorted by fitness.
--   * selectionIndexes - Random indices for tournament participants.
--   * elites - Number of elite individuals to preserve.
--   * selectionSize - Size of each tournament.
--
-- Returns: List of selected (fitness, index) pairs.
tournamentSelectionHelper :: [(Double, Int)] -> [Int] -> Int -> Int -> [(Double, Int)]
tournamentSelectionHelper sorted selectionIndexes elites selectionSize
  | selectionIndexes == [] = []
  | elites /= 0            = take elites sorted ++ selection !! 0 : tournamentSelectionHelper sorted remaining 0 selectionSize
  | otherwise              = selection !! 0 : tournamentSelectionHelper sorted remaining 0 selectionSize
  where (selected, remaining) = splitAt selectionSize selectionIndexes
        selection = sort $ map (sorted !!) selected

-- | Performs tournament selection on a population.
--
-- Selects individuals by holding tournaments of size 'selectionSize', preserving 'elites' unchanged.
--
-- Arguments:
--   * population - The current population of individuals.
--   * fitness - Fitness values for the population.
--   * selectionIndexes - Random indices for tournament participants.
--   * elites - Number of elite individuals to preserve.
--   * selectionSize - Size of each tournament.
--
-- Returns: The selected population.
tournamentSelection :: [[Double]] -> [Double] -> [Int] -> Int -> Int -> [[Double]]
tournamentSelection population fitness selectionIndexes elites selectionSize = 
    map (\x -> population !! snd x) $ tournamentSelectionHelper (sortFitness fitness) selectionIndexes elites selectionSize
