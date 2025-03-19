module Main where

import Criterion.Measurement
import GA (initializePopulation, gaIterate)

main :: IO ()
main = do
  start <- getTime
  population <- initializePopulation 10000 100
  fitness <- gaIterate 0 population 200 2 2.0
  putStrLn $ "Final fitness: " ++ show fitness
  end <- getTime
  let timeTaken = end - start
  putStrLn $ "Time Taken: " ++ show timeTaken
