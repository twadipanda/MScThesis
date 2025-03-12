module Main where

import GA (initializePopulation, gaIterate)

main :: IO ()
main = do
  population <- initializePopulation 10000 100
  gaIterate 0 population 200 2 2.0
