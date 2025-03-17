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


evaluate :: [Particle] -> (Particle -> Particle) -> [Particle]
evaluate particles f = map f particles

globalBest :: [Particle] -> Particle -> Particle
globalBest particles globalBestParticle = foldl (\best particle -> if bestFitness particle < bestFitness best then particle else best) globalBestParticle particles

updateParticle :: Particle -> Particle -> [Double] -> [Double] -> Double -> Double -> Double -> Particle
updateParticle particle globalBestParticle r1 r2 intertia cognitive social = Particle (zipWith (+) (position particle) velocityComponent) velocityComponent (bestPosition particle) (bestFitness particle)
  where cognitiveComponent = zipWith (\x y -> x * cognitive * y) (zipWith (-) (bestPosition particle) (position particle)) r1
        socialComponent = zipWith (\x y -> x * social * y) (zipWith (-) (position globalBestParticle) (position particle)) r2
        velocityComponent = zipWith3 (\x y z -> (x * intertia) + y + z) (velocity particle) cognitiveComponent socialComponent

-- update :: [Particle] -> Particle -> Double -> Double -> Double -> Double -> IO([Particle])
-- update particles globalBestParticle intertia cognitive social = do
--   gen1 <- newStdGen
--   gen2 <- newStdGen
--   let r1 = randomRs (0, 1) gen1 :: [Double]
--   let r2 = randomRs (0, 1) gen2 :: [Double]
--   return $ map (\particle -> updateParticle particle globalBestParticle r1 r2 intertia cognitive social) particles

-- update :: [Particle] -> Particle -> Double -> Double -> Double -> Double -> IO [Particle]
-- update particles globalBestParticle intertia cognitive social = do
--   gen1 <- newStdGen
--   gen2 <- newStdGen
--   let r1 = randomRs (0, 1) gen1 :: [Double]
--   let r2 = randomRs (0, 1) gen2 :: [Double]
--   return $ map (\particle -> updateParticle particle globalBestParticle r1 r2 intertia cognitive social) particles