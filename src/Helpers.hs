module Helpers (beta) where

import System.Random (newStdGen, randomRs)

beta :: Double -> IO (Double)
beta distributionIndex = do
  gen <- newStdGen
  let meu = head (randomRs (0, 1) gen :: [Double])
  if meu <= 0.5 then return $ (2 * meu) ** (1 / (distributionIndex + 1))
  else return $ (1 / (2 * (1 - meu))) ** (1 / (distributionIndex + 1))
