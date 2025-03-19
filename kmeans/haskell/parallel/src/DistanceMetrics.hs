module DistanceMetrics where

squaredDiff :: Double -> Double -> Double
squaredDiff x y = (y - x)^2

euclideanDistance :: [Double] -> [Double] -> Double
euclideanDistance x y = sqrt c
    where c = foldl1 (+) (zipWith (squaredDiff) x y)
