module TestDistanceMetrics (testsDM, prop_squaredDiffCommutes, prop_euclideanDistanceCommutes) where

import Test.HUnit
import DistanceMetrics


test1 :: Test
test1 = TestCase (assertEqual "squaredDiff 2 3 should be 1" 1 (squaredDiff 2 3))

test2 :: Test
test2 = TestCase (assertEqual "squaredDiff 0 3 should be 9" 9 (squaredDiff 0 3))

test3 :: Test
test3 = TestCase (assertEqual "squaredDiff 0 0 should be 0" 0 (squaredDiff 0 0))

test4 :: Test
test4 = TestCase (assertEqual "squaredDiff 1 -5 should be 36" 36 (squaredDiff 1 (-5)))

test5 :: Test
test5 = TestCase (assertEqual "euclideanDistance [1,2] [4,6] should be 5" 5 (euclideanDistance [1,2] [4,6]))

test6 :: Test
test6 = TestCase (assertEqual "euclideanDistance [0,0,0] [3,4,0] should be 5" 5 (euclideanDistance [0,0,0] [3,4,0]))

test7 :: Test
test7 = TestCase (assertEqual "euclideanDistance [-1,3] [2,-1] should be 5" 5 (euclideanDistance [-1,3] [2,-1]))

test8 :: Test
test8 = TestCase (assertEqual "euclideanDistance [1,2,3,4] [5,6,7,8] should be 8" 8 (euclideanDistance [1,2,3,4] [5,6,7,8]))

test9 :: Test
test9 = TestCase (assertEqual "euclideanDistance [2,3] [2,3] should be 0" 0 (euclideanDistance [2,3] [2,3]))

test10 :: Test
test10 = TestCase (assertEqual "euclideanDistance [1.5,2.5] [4.5,6.5] should be 5" 5 (euclideanDistance [1.5,2.5] [4.5,6.5]))

testsDM :: Test
testsDM = TestList [TestLabel "squaredDiff1" test1, TestLabel "squaredDiff2" test2,
                  TestLabel "squaredDiff3" test3, TestLabel "squaredDiff4" test4,
                  TestLabel "euclideanDistance1" test5, TestLabel "euclideanDistance2" test6,
                  TestLabel "euclideanDistance3" test7, TestLabel "euclideanDistance4" test8,
                  TestLabel "euclideanDistance5" test9, TestLabel "euclideanDistance6" test10]

-- Property: squaredDiff is commutative
prop_squaredDiffCommutes :: Double -> Double -> Bool
prop_squaredDiffCommutes x y = squaredDiff x y == squaredDiff y x

-- Property: euclideanDistance is commutative
prop_euclideanDistanceCommutes :: [Double] -> [Double] -> Bool
prop_euclideanDistanceCommutes x y = euclideanDistance x y == euclideanDistance y x
