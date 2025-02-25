module Kmeans where

import qualified Data.Vector as V
import qualified Data.Vector.Unboxed as U
import DistanceMetrics
import Data.List (elemIndex)
import Data.Maybe (fromMaybe)
import Control.Parallel.Strategies (using, parList, rdeepseq)

kmeansDist :: U.Vector Double -> V.Vector (U.Vector Double) -> U.Vector Double
kmeansDist x centers = U.convert $ V.map (euclideanDistance x) centers

belongsTo :: V.Vector (U.Vector Double) -> V.Vector (U.Vector Double) -> U.Vector Int
belongsTo points centers
  | V.null points || V.null centers = U.empty
  | otherwise = U.convert $ V.map (\p -> minIndex (kmeansDist p centers)) points
  where
    minIndex dists = fromMaybe 0 (U.elemIndex (U.minimum dists) dists)

pointsForCenters :: Int -> U.Vector Int -> V.Vector (U.Vector Double) -> V.Vector (U.Vector Double)
pointsForCenters k assignments points = V.ifilter (\i _ -> assignments U.! i == k) points

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

kmeans :: Int -> Int -> V.Vector (U.Vector Double) -> V.Vector (U.Vector Double) -> V.Vector (U.Vector Double)
kmeans k iter points centers
  | iter >= k = V.empty
  | otherwise = V.cons (vectorMean kthPoints) (kmeans k (iter + 1) points centers) `using` parList rdeepseq
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
