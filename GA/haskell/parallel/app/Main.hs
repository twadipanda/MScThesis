module Main where

import Control.DeepSeq
import Control.Exception (evaluate)
import Criterion.Measurement
import GA (initializePopulation, gaIterate)

main :: IO ()
main = do
  start <- getTime
  population <- initializePopulation 5000 100
  fitness <- gaIterate 0 population 200 2 2.0
  evaluated <- evaluate (force fitness)
  --putStrLn $ "Final fitness: " ++ show fitness
  end <- getTime
  let timeTaken = end - start
  putStrLn $ show evaluated ++ "," ++ show timeTaken                                             
