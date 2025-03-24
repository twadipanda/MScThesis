module Main where

import System.Environment
import Criterion.Measurement
import Control.DeepSeq
import Control.Exception (evaluate)
import Read
import Kmeans
-- import qualified Data.Vector.Unboxed as U

main :: IO ()
main = do
    args <- getArgs          -- Get the command-line arguments
    points <- reada $ args!!0  -- Read data from file
    let k = read $ args!!1 :: Int
    parsed <- evaluate $ force $ parseInput points
    centers <- evaluate $ force $ getCenters k parsed
    start <- getTime
    _ <- evaluate $ force $ kmeansIter k 0 parsed centers
    end <- getTime
    let timeTaken = end - start
    print timeTaken