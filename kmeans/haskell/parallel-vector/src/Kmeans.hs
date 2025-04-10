module Kmeans where

import qualified Data.Vector as V
import qualified Data.Vector.Unboxed as U
import DistanceMetrics
import Data.List (elemIndex)
import Data.Maybe (fromMaybe)
import Control.Parallel
import Control.Parallel.Strategies
import Control.DeepSeq (force)

kmeansDist :: U.Vector Double -> V.Vector (U.Vector Double) -> V.Vector Double
kmeansDist point centers = V.map (euclideanDistance point) centers

parVector :: NFData a => Strategy (V.Vector a)
parVector vec = do
  V.mapM_ (\x -> rpar (force x)) vec
  rseq (force vec)
  return vec

belongsTo :: V.Vector (U.Vector Double) -> V.Vector (U.Vector Double) -> V.Vector Int
belongsTo points centers
  | V.null points || V.null centers = V.empty
  | otherwise = V.map (\p -> minIndex (kmeansDist p centers)) points `using` parVector
  where
    minIndex dists = fromMaybe 0 (V.elemIndex (V.minimum dists) dists)

-- belongsTo :: V.Vector (U.Vector Double) -> V.Vector (U.Vector Double) -> V.Vector Int --indexes
-- belongsTo points centers
--   | V.null points || V.null centers = V.empty
--   | otherwise = V.map (\p -> minIndex (kmeansDist p centers)) points
--   where
--     minIndex dists = fromMaybe 0 (V.elemIndex (V.minimum dists) dists)

pointsForCenters :: Int -> V.Vector Int -> V.Vector (U.Vector Double) -> V.Vector (U.Vector Double)
pointsForCenters k assignments points = V.ifilter (\i _ -> assignments V.! i == k) points

vectorAdd :: V.Vector (U.Vector Double) -> U.Vector Double
vectorAdd vecs = V.foldl1 (U.zipWith (+)) vecs

vectorDiv :: Int -> U.Vector Double -> U.Vector Double
vectorDiv n vec = U.map (/ fromIntegral n) vec

vectorMean :: V.Vector (U.Vector Double) -> U.Vector Double
vectorMean vecs
  | V.null vecs = U.empty
  | otherwise = vectorDiv (V.length vecs) (vectorAdd vecs)

getCenters :: Int -> V.Vector (U.Vector Double) -> V.Vector (U.Vector Double)
getCenters k points = V.take k points

-- parKmeansCenters :: Int -> V.Vector (U.Vector Double) -> V.Vector (U.Vector Double) -> Strategy (V.Vector (U.Vector Double))
-- parKmeansCenters k points centers vec = do
--   let assignments = belongsTo points centers
--   means = V.map (\i -> vectorMean $ pointsForCenters i assignments points) (V.enumFromN 0 k)
--   -- Spark parallel evaluation of each mean
--   V.mapM_ (\m -> rpar (force m)) means
--   -- Ensure all are evaluated
--   rseq (force means)
--   return vec

-- parKmeansCenters :: Int -> V.Vector (U.Vector Double) -> V.Vector (U.Vector Double) -> Strategy (V.Vector (U.Vector Double))
-- parKmeansCenters k points centers vec = do
--   let assignments = belongsTo points centers
--   let means = V.map (\i -> vectorMean $ pointsForCenters i assignments points) (V.enumFromN 0 k)
--   -- Spark parallel evaluation of each mean
--   V.mapM_ (\m -> rparWith rdeepseq m) means
--   -- Ensure all are evaluated
--   rseq (force means)
--   return vec

-- kmeans :: Int -> Int -> V.Vector (U.Vector Double) -> V.Vector (U.Vector Double) -> V.Vector (U.Vector Double)
-- kmeans k iter points centers
--   | iter >= k = V.empty
--   | otherwise = V.generate k genNewCenter `using` parKmeansCenters k points centers
--   where
--     assignments = belongsTo points centers
--     genNewCenter i = vectorMean $ pointsForCenters i assignments points

kmeans :: Int -> Int -> V.Vector (U.Vector Double) -> V.Vector (U.Vector Double) -> V.Vector (U.Vector Double)
kmeans k iter points centers
  | iter >= k = V.empty
  | otherwise = V.cons (vectorMean kthPoints) (kmeans k (iter + 1) points centers)
  where
    assignments = belongsTo points centers
    kthPoints = pointsForCenters iter assignments points

kmeansIter :: Int -> V.Vector (U.Vector Double) -> V.Vector (U.Vector Double) -> V.Vector (U.Vector Double)
kmeansIter k points initialCenters
  | currMeans == newMeans = newMeans
  | otherwise = kmeansIter k points currMeans
  where
    currMeans = kmeans k 0 points initialCenters
    newMeans = kmeans k 0 points currMeans
