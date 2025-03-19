module Kmeans where

import DistanceMetrics
import Data.List

--takes a list of mean vectors and a vector to find the distance
kmeansDist :: [Double] -> [[Double]] -> [Double]
kmeansDist _ [[]] = []
kmeansDist _ [] = []
kmeansDist x (y:ys) = (euclideanDistance x y):(kmeansDist x ys)

---------------------------------------------
--ARGS
--first argument is vector
--second argument is centers
--DESC
--finds the center a vector should belong to
--returns a list of int, where the value is
--the index of the center a vector should
--belong to, the index of the returned list
-- is the index of the vector in the input list.
---------------------------------------------
belongsTo :: [[Double]] -> [[Double]] -> [Int]
belongsTo _ [] = []
belongsTo [] _ = []
belongsTo (x:xs) y = (minIndex (kmeansDist x y)):(belongsTo xs y)

--finds the index of min in a list
minIndex :: [Double] -> Int
minIndex x = case b of
             Just val -> val
             Nothing -> 0
             where b = elemIndex (foldl1 min x) x

-- 0,2,3,5,8
--[0,1,0,0,1,0,1,1,0,1]
-- gives vectors for a given center
pointsForCenters :: Int -> Int -> [Int] -> [[Double]] -> [[Double]]
pointsForCenters _ _ [] _ = []
pointsForCenters k t (x:xs) y | x == k = y!!t:pointsForCenters k (t+1) xs y
                              | otherwise = pointsForCenters k (t+1) xs y

vectorAdd :: [[Double]] -> [Double]
vectorAdd x = foldl1 (zipWith (+)) x

vectorDiv ::  Int -> [Double] -> [Double]
vectorDiv x y = map (/ (fromIntegral x)) y

vectorMean :: [[Double]] -> [Double]
vectorMean x = vectorDiv (length x) (vectorAdd x)

getCenters :: Int -> [[Double]] -> [[Double]]
getCenters x y = take x y

-- k -> iterator -> Points -> Centers -> New Centers
-- kmeans :: Int -> Int -> [[Double]] -> [[Double]] -> [[Double]]
-- kmeans k it x y | it < k = (vectorMean kthPoints):(kmeans k (it+1) x y) `using` parList rdeepseq
--                 | otherwise = []
--     where indexes = belongsTo x y
--           kthPoints = pointsForCenters it 0 indexes x

kmeans :: Int -> Int -> [[Double]] -> [[Double]] -> [[Double]]
kmeans k it x y | it < k = (vectorMean kthPoints):(kmeans k (it+1) x y)
                | otherwise = []
    where indexes = belongsTo x y
          kthPoints = pointsForCenters it 0 indexes x

kmeansIter :: Int -> Int -> [[Double]] -> [[Double]] -> [[Double]]
kmeansIter k it x y | currMeans /= newMeans = kmeansIter k it x currMeans
                    | otherwise = newMeans
    where currMeans = kmeans k it x y
          newMeans = kmeans k it x currMeans