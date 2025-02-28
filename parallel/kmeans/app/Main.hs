module Main where

import Criterion.Measurement
import Control.DeepSeq
import Read
import Kmeans
import DistanceMetrics
-- import qualified Data.Vector.Unboxed as U

main :: IO ()
main = do
    --putStrLn "Reading Data..."
    points <- reada "letter.txt"
    let parsed = parseInput points
    deepseq parsed print ""
    let centers = getCenters 26 parsed
   -- putStrLn "Starting K-means with k = 3 on dim16 data..."
    start <- getTime
    let newMeans = kmeansIter 26 parsed centers
    deepseq newMeans print ""
    -- let temp = euclideanDistance1 (U.fromList (parsed!!0)) (U.fromList (parsed!!1))
    -- deepseq temp print ""
    end <- getTime
    let timeTaken = end - start
    -- let newMeans = kmeans 3 0 parsed centers
    print timeTaken
    print newMeans