module Particle where

data Particle = Particle { position :: [Double]
                         , velocity :: [Double]
                         , bestPosition :: [Double]
                         , bestFitness :: Double
                         }
                        deriving (Show)
