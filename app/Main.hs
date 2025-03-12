module Main where

import GA (initializePopulation, gaIterate)

main :: IO ()
main = do
  population <- initializePopulation 1000 100
  gaIterate 0 population 200 2 2.0
