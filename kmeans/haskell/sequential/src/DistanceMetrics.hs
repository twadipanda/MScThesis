-- | Provides distance metric functions used in K-Means clustering.
module DistanceMetrics where

-- | Computes the squared difference between two numbers.
squaredDiff :: Double -> Double -> Double
squaredDiff x y = (y - x)^2

-- | Calculates the Euclidean distance between two vectors.
--
-- Arguments:
-- * First argument: First vector as a list of Doubles.
-- * Second argument: Second vector as a list of Doubles.
--
-- Returns: The Euclidean distance as a Double.
euclideanDistance :: [Double] -> [Double] -> Double
euclideanDistance x y = sqrt c
    where c = foldl1 (+) (zipWith (squaredDiff) x y)