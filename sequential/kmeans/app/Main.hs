module Main where

import Criterion.Measurement
import Control.DeepSeq
import Control.Exception (evaluate)
import Read
import Kmeans

main :: IO ()
main = do
    points <- reada "worms_64d.txt"
    parsed <- evaluate $ force $ parseInput points
    centers <- evaluate $ force $ getCenters 25 parsed
    start <- getTime
    _ <- evaluate $ force $ kmeansIter 25 parsed centers
    end <- getTime
    let timeTaken = end - start
    print timeTaken