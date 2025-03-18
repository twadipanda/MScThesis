module PSO where

import System.Random (newStdGen, randomRs)
import Data.List.Split (chunksOf)
import Particle
import Control.Parallel.Strategies (using, parList, rdeepseq)

initialize :: Int -> Int -> IO [Particle]
initialize numberParticles numberDimensions = do
  gen1 <- newStdGen
  gen2 <- newStdGen
  let particles = take (numberParticles * numberDimensions) $ randomRs (-5.12, 5.12) gen1 :: [Double]
  let velocities = take (numberParticles * numberDimensions) $ randomRs (-5.12, 5.12) gen2 :: [Double]
  let particleChunks = chunksOf numberDimensions particles
  let velocityChunks = chunksOf numberDimensions velocities
  return $ map (\(particle, velocity) -> Particle particle velocity particle (1 / 0)) (zip particleChunks velocityChunks)


evaluate_ :: [Particle] -> (Particle -> Particle) -> [Particle]
evaluate_ particles f = map f particles

globalBest :: [Particle] -> Particle -> Particle
globalBest particles globalBestParticle = foldl (\best particle -> if bestFitness particle < bestFitness best then particle else best) globalBestParticle particles

updateParticle :: Particle -> Particle -> [Double] -> [Double] -> Double -> Double -> Double -> Particle
updateParticle particle globalBestParticle r1 r2 intertia cognitive social = Particle (zipWith (+) (position particle) velocityComponent) velocityComponent (bestPosition particle) (bestFitness particle)
  where cognitiveComponent = zipWith (\x y -> x * cognitive * y) (zipWith (-) (bestPosition particle) (position particle)) r1 `using` parList rdeepseq
        socialComponent = zipWith (\x y -> x * social * y) (zipWith (-) (position globalBestParticle) (position particle)) r2 `using` parList rdeepseq
        velocityComponent = zipWith3 (\x y z -> (x * intertia) + y + z) (velocity particle) cognitiveComponent socialComponent `using` parList rdeepseq

update :: [Particle] -> Particle -> Double -> Double -> Double -> IO [Particle]
update particles globalBestParticle intertia cognitive social = do
  gen1 <- newStdGen
  gen2 <- newStdGen
  let len = length particles
  let dim = length (position globalBestParticle) 
  let r1 = take (len * dim) $ randomRs (0, 1) gen1 :: [Double]
  let r2 = take (len * dim) $ randomRs (0, 1) gen2 :: [Double]
  return $ zipWith3 (\particle r1_ r2_ -> updateParticle particle globalBestParticle r1_ r2_ intertia cognitive social) particles (chunksOf dim r1) (chunksOf dim r2)

psoIterate :: Int -> [Particle] -> (Particle -> Particle) -> Particle -> Double -> Double -> Double -> IO [Particle]
psoIterate 0 particles f globalBestParticle _ _ _ = do
  return particles
psoIterate n particles f globalBestParticle intertia cognitive social = do
  let particles_ = evaluate_ particles f
  let globalBestParticle_ = globalBest particles_ globalBestParticle
  particles__ <- update particles_ globalBestParticle intertia cognitive social
  psoIterate (n - 1) particles__ f globalBestParticle_ intertia cognitive social