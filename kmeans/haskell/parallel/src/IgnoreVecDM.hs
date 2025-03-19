module DistanceMetrics where

import qualified Data.Vector.Unboxed as U

squaredDiff :: Double -> Double -> Double
squaredDiff x y = (y - x)^2

euclideanDistance :: U.Vector Double -> U.Vector Double -> Double
euclideanDistance x y = sqrt c
    where c = U.foldl1 (+) (U.zipWith (squaredDiff) x y)
