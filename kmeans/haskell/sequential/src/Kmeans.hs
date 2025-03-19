-- | Implements the K-Means clustering algorithm.
module Kmeans where

import DistanceMetrics
import Data.List

-- | Computes the Euclidean distances between a vector and a list of mean vectors.
--
-- Arguments:
-- * First argument: The vector to compare.
-- * Second argument: List of mean vectors (centers).
--
-- Returns: A list of distances.
kmeansDist :: [Double] -> [[Double]] -> [Double]
kmeansDist _ [[]] = []
kmeansDist _ [] = []
kmeansDist x (y:ys) = (euclideanDistance x y):(kmeansDist x ys)

-- | Determines which center each vector belongs to based on minimum distance.
--
-- Arguments:
-- * First argument: List of vectors (points).
-- * Second argument: List of centers.
--
-- Returns: A list of indices, where each index corresponds to the center a vector belongs to.
belongsTo :: [[Double]] -> [[Double]] -> [Int]
belongsTo _ [] = []
belongsTo [] _ = []
belongsTo (x:xs) y = (minIndex (kmeansDist x y)):(belongsTo xs y)

-- | Finds the index of the minimum value in a list.
--
-- Arguments:
-- * A list of Doubles.
--
-- Returns: The index of the minimum value, or 0 if not found.
minIndex :: [Double] -> Int
minIndex x = case b of
             Just val -> val
             Nothing -> 0
             where b = elemIndex (foldl1 min x) x

-- | Retrieves all vectors assigned to a specific center.
--
-- Arguments:
-- * First argument: Center index to filter by.
-- * Second argument: Current vector index (for recursion).
-- * Third argument: List of center assignments for vectors.
-- * Fourth argument: List of all vectors.
--
-- Returns: List of vectors assigned to the specified center.
pointsForCenters :: Int -> Int -> [Int] -> [[Double]] -> [[Double]]
pointsForCenters _ _ [] _ = []
pointsForCenters k t (x:xs) y | x == k = y!!t:pointsForCenters k (t+1) xs y
                              | otherwise = pointsForCenters k (t+1) xs y

-- | Adds vectors element-wise.
--
-- Arguments:
-- * List of vectors to sum.
--
-- Returns: A single vector representing the sum.
vectorAdd :: [[Double]] -> [Double]
vectorAdd x = foldl1 (zipWith (+)) x

-- | Divides a vector by a scalar value.
--
-- Arguments:
-- * First argument: Scalar denominator (as Int).
-- * Second argument: Vector to divide.
--
-- Returns: The resulting vector after division.
vectorDiv ::  Int -> [Double] -> [Double]
vectorDiv x y = map (/ (fromIntegral x)) y

-- | Computes the mean of a list of vectors.
--
-- Arguments:
-- * List of vectors.
--
-- Returns: The mean vector.
vectorMean :: [[Double]] -> [Double]
vectorMean x = vectorDiv (length x) (vectorAdd x)

-- | Selects the initial cluster centers from the data points.
--
-- Arguments:
-- * First argument: Number of centers to select.
-- * Second argument: List of all points.
--
-- Returns: List of selected centers.
getCenters :: Int -> [[Double]] -> [[Double]]
getCenters x y = take x y

-- | Performs one iteration of K-Means to compute new centers.
--
-- Arguments:
-- * First argument: Number of clusters (k).
-- * Second argument: Current iteration index.
-- * Third argument: List of points.
-- * Fourth argument: Current centers.
--
-- Returns: List of new centers for this iteration.
kmeans :: Int -> Int -> [[Double]] -> [[Double]] -> [[Double]]
kmeans k it x y | it < k = (vectorMean kthPoints):(kmeans k (it+1) x y)
                | otherwise = []
    where indexes = belongsTo x y
          kthPoints = pointsForCenters it 0 indexes x

-- | Iteratively applies K-Means until convergence.
--
-- Arguments:
-- * First argument: Number of clusters (k).
-- * Second argument: Current iteration index (usually 0).
-- * Third argument: List of points.
-- * Fourth argument: Initial centers.
--
-- Returns: Final list of centers after convergence.
kmeansIter :: Int -> Int -> [[Double]] -> [[Double]] -> [[Double]]
kmeansIter k it x y | currMeans /= newMeans = kmeansIter k it x currMeans
                    | otherwise = newMeans
    where currMeans = kmeans k it x y
          newMeans = kmeans k it x currMeans