module PSO where

import System.Random (newStdGen, randomRs)
import Data.List.Split (chunksOf)

initialize :: Int -> Int -> IO [[Double]]
initialize numberParticles numberDimensions = do
  let gen = newStdGen
  let randomValues = take (numberParticles * numberDimensions) $ randomRs (-5.12, 5.12) gen
  return $ chunksOf numberDimensions randomValues

evaluate :: [[Double]] -> ([Double] -> Double) -> [Double]
evaluate particles f = map f particles