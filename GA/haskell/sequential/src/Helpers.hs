-- | This module provides utility functions for the Genetic Algorithm, including random number generation and sorting.
module Helpers (beta, sortFitness, randomNumbers, normalNoise) where

import System.Random (newStdGen, randomRs)
import Data.Random.Normal (normals)
import Data.List (sort)

-- | Generates a beta value for simulated binary crossover.
--
-- Computes a beta parameter based on a random value and distribution index, following the SBX formula.
--
-- Arguments:
--   * distributionIndex - Controls the spread of crossover (higher values narrow the distribution).
--
-- Returns: An IO action yielding the beta value.
beta :: Double -> IO (Double)
beta distributionIndex = do
  gen <- newStdGen
  let meu = head (randomRs (0, 1) gen :: [Double])
  if meu <= 0.5 then return $ (2 * meu) ** (1 / (distributionIndex + 1))
  else return $ (1 / (2 * (1 - meu))) ** (1 / (distributionIndex + 1))

-- | Pairs fitness values with their original indices and sorts them.
--
-- Prepares a population for selection by associating fitness with individual indices.
--
-- Arguments:
--   * fitness - List of fitness values.
--
-- Returns: A sorted list of (fitness, index) pairs.
sortFitness :: [Double] -> [(Double, Int)]
sortFitness fitness = sort $ zip fitness [0..]

-- | Generates a list of random integers within a specified range.
--
-- Arguments:
--   * size - Number of random numbers to generate.
--   * range - Upper bound of the random range (inclusive, starting from 0).
--
-- Returns: An IO action yielding a list of random integers.
randomNumbers :: Int -> Int -> IO ([Int])
randomNumbers size range = do
  gen <- newStdGen
  return $ take size (randomRs (0, range) gen :: [Int])

-- | Generates a list of Gaussian noise values.
--
-- Produces normally distributed noise scaled to a mean of 0 and standard deviation of 0.1.
--
-- Arguments:
--   * size - Number of noise values to generate.
--
-- Returns: An IO action yielding a list of noise values.
normalNoise :: Int -> IO ([Double])
normalNoise size = do
  gen <- newStdGen
  return $ map realToFrac (scaleNormal 0 0.1 $ take size (normals gen))

-- | Scales a list of normal random values.
--
-- Adjusts a list of normally distributed values by a mean and standard deviation.
--
-- Arguments:
--   * mean - The mean to shift the distribution.
--   * std - The standard deviation to scale the distribution.
--   * values - The list of normal values to scale.
--
-- Returns: The scaled list of values.
scaleNormal :: Float -> Float -> [Float] -> [Float]
scaleNormal mean std = map (\x -> mean + std * x)