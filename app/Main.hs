module Main where

import PSO
import Benchmark

main :: IO ()
main = do
  particles <- initialize 10 5
  print particles
  print $ evaluate particles sphere
  let particles_ = evaluate particles sphere
  print $ map (\particle -> bestFitness particle) particles_
  print "GLOBAL BEST:"
  print $ globalBest particles_ (head particles_)
