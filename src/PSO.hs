module PSO where

import System.Random (newStdGen, randomRs)
import Data.List.Split (chunksOf)
import Particle

initialize :: Int -> Int -> IO [Particle]
initialize numberParticles numberDimensions = do
  gen1 <- newStdGen
  gen2 <- newStdGen
  let particles = take (numberParticles * numberDimensions) $ randomRs (-5.12, 5.12) gen1 :: [Double]
  let velocities = take (numberParticles * numberDimensions) $ randomRs (-5.12, 5.12) gen2 :: [Double]
  let particleChunks = chunksOf numberDimensions particles
  let velocityChunks = chunksOf numberDimensions velocities
  return $ map (\(particle, velocity) -> Particle particle velocity particle (1 / 0)) (zip particleChunks velocityChunks)


evaluate :: [Particle] -> ([Particle] -> Particle) -> [Particle]
evaluate particles f = map f particles