module Benchmark (sphere) where

sphere :: [Double] -> Double
sphere individual = sum $ map (\x -> x ^ 2) individual