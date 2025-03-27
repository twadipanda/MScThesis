module Main where

import Test.HUnit
import Test.QuickCheck
import TestDistanceMetrics
import TestKmean

-- Run the tests
main :: IO ()
main = do
  runTestTT  testsDM 
  runTestTT testsKmeans
  quickCheck prop_squaredDiffCommutes
  quickCheck prop_euclideanDistanceCommutes