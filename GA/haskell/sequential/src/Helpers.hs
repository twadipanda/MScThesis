module Helpers (beta, sortFitness, randomNumbers, normalNoise) where

import System.Random (newStdGen, randomRs)
import Data.Random.Normal (normals)
import Data.List (sort)

beta :: Double -> IO (Double)
beta distributionIndex = do
  gen <- newStdGen
  let meu = head (randomRs (0, 1) gen :: [Double])
  if meu <= 0.5 then return $ (2 * meu) ** (1 / (distributionIndex + 1))
  else return $ (1 / (2 * (1 - meu))) ** (1 / (distributionIndex + 1))

sortFitness :: [Double] -> [(Double, Int)]
sortFitness fitness = sort $ zip fitness [0..]

randomNumbers :: Int -> Int -> IO ([Int])
randomNumbers size range = do
  gen <- newStdGen
  return $ take size (randomRs (0, range) gen :: [Int])

normalNoise :: Int -> IO ([Double])
normalNoise size = do
  gen <- newStdGen
  return $ map realToFrac (scaleNormal 0 0.1 $ take size (normals gen))

scaleNormal :: Float -> Float -> [Float] -> [Float]
scaleNormal mean std = map (\x -> mean + std * x)