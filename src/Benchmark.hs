module Benchmark (sphere) where

import Particle

sphere :: [Particle] -> Particle
sphere particle = (Particle (particle position) (particle velocity) (particle bestPosition) (sum $ map (\x -> x ^ 2) (particle position)))
-- sphere individual = sum $ map (\x -> x ^ 2) individual