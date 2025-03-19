-- | Main module for running the K-Means clustering algorithm with performance measurement.
module Main where

import Criterion.Measurement
import Control.DeepSeq
import Control.Exception (evaluate)
import Read
import Kmeans

-- | Entry point of the program. Reads points from a file, performs K-Means clustering,
-- and measures the execution time.
main :: IO ()
main = do
    points <- reada "worms_64d.txt"  -- Read data from file
    parsed <- evaluate $ force $ parseInput points  -- Parse and force evaluation of points
    centers <- evaluate $ force $ getCenters 25 parsed  -- Initialize 25 cluster centers
    start <- getTime  -- Start timing
    _ <- evaluate $ force $ kmeansIter 25 0 parsed centers  -- Run K-Means and force evaluation
    end <- getTime  -- End timing
    let timeTaken = end - start  -- Calculate elapsed time
    print timeTaken  -- Output time taken