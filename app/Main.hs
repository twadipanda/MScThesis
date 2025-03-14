module Main where

import PSO
import Benchmark

main :: IO ()
main = do
  particles <- initialize 10 5
  print particles
  print $ evaluate particles sphere
