module Main where

-- import System.CPUTime (getCPUTime)
import Criterion.Measurement
import Control.DeepSeq
import Read
import Kmeans

main :: IO ()
main = do
    --putStrLn "Reading Data..."
    points <- reada "dim16.txt"
    let parsed = parseInput points
    deepseq parsed print ""
    let centers = getCenters 16 parsed
   -- putStrLn "Starting K-means with k = 3 on dim16 data..."
    start <- getTime
    let newMeans = kmeansIter 16 0 parsed centers
    deepseq newMeans print ""
    end <- getTime
    let timeTaken = end - start
    -- let newMeans = kmeans 3 0 parsed centers
    print timeTaken
    -- print newMeans

