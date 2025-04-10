-- | This module provides a benchmark fitness function for optimization problems.
module Benchmark (sphere) where

-- | Computes the sphere function for a given individual.
--
-- The sphere function is a common benchmark in optimization, defined as the sum of squared values
-- of an individual's genes. It evaluates to a non-negative value, with the global minimum at 0
-- when all genes are 0.
--
-- >>> sphere [1.0, 2.0, 3.0]
-- 14.0
-- >>> sphere [0.0, 0.0, 0.0]
-- 0.0
sphere :: [Double] -> Double
sphere individual = sum $ map (\x -> x ^ 2) individual