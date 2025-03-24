-- | Main module for running the K-Means clustering algorithm with performance measurement.
module Main where

import System.Environment
import Criterion.Measurement
import Control.DeepSeq
import Control.Exception (evaluate)
import Read
import Kmeans

-- | Entry point of the program. Reads points from a file, performs K-Means clustering,
-- and measures the execution time.
main :: IO ()
main = do
    args <- getArgs          -- Get the command-line arguments
    points <- reada $ args!!0  -- Read data from file
    let k = read $ args!!1 :: Int
    parsed <- evaluate $ force $ parseInput points  -- Parse and force evaluation of points
    centers <- evaluate $ force $ getCenters k parsed  -- Initialize k cluster centers
    start <- getTime  -- Start timing
    _ <- evaluate $ force $ kmeansIter k 0 parsed centers  -- Run K-Means and force evaluation
    end <- getTime  -- End timing
    let timeTaken = end - start  -- Calculate elapsed time
    print timeTaken  -- Output time taken