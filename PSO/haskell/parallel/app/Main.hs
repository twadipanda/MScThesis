module Main where

import PSO
import Benchmark
import Particle
import Criterion.Measurement
import Control.DeepSeq
import Control.Exception (evaluate)

main :: IO ()
main = do
  start <- getTime
  particles <- initialize 10000 100
  updateParticles <- psoIterate 10000 particles sphere (head particles) 0.5 1.0 2.0
  let updateParticles_ = evaluate_ updateParticles sphere
  evaluated <- evaluate (force (bestFitness (globalBest updateParticles_ (head updateParticles_))))
  end <- getTime
  let timeTaken = end - start
  putStrLn $ show evaluated ++ "," ++ show timeTaken
