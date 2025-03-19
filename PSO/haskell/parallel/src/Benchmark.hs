module Benchmark (sphere) where

import Particle

sphere :: Particle -> Particle
sphere particle
  | fitness < (bestFitness particle) = (Particle (position particle) (velocity particle) (position particle) fitness)
  | otherwise = particle
  where fitness = sum $ map (\x -> x ^ 2) (position particle)
