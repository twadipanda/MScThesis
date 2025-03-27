module TestKmean (testsKmeans) where

import Test.HUnit
import Kmeans

-- Adding two simple vectors
test1 :: Test
test1 = TestCase (assertEqual "vectorAdd [[1,2], [3,4]] should be [4,6]" [4,6] (vectorAdd [[1,2], [3,4]]))

-- Adding three vectors
test2 :: Test
test2 = TestCase (assertEqual "vectorAdd [[1,1], [2,2], [3,3]] should be [6,6]" [6,6] (vectorAdd [[1,1], [2,2], [3,3]]))

-- Single vector (list with one vector)
test3 :: Test
test3 = TestCase (assertEqual "vectorAdd [[5,5]] should be [5,5]" [5,5] (vectorAdd [[5,5]]))

-- Vectors with negative numbers
test4 :: Test
test4 = TestCase (assertEqual "vectorAdd [[-1,2], [3,-4]] should be [2,-2]" [2,-2] (vectorAdd [[-1,2], [3,-4]]))

-- Vectors with floating-point numbers
test5 :: Test
test5 = TestCase (assertEqual "vectorAdd [[1.5,2.5], [2.5,3.5]] should be [4.0,6.0]" [4.0,6.0] (vectorAdd [[1.5,2.5], [2.5,3.5]]))

-- Basic division with positive scalar
test6 :: Test
test6 = TestCase (assertEqual "vectorDiv 2 [4,6,8] should be [2,3,4]" [2,3,4] (vectorDiv 2 [4,6,8]))

-- Division with negative scalar
test7 :: Test
test7 = TestCase (assertEqual "vectorDiv (-2) [4,-6,8] should be [-2,3,-4]" [-2,3,-4] (vectorDiv (-2) [4,-6,8]))

-- Vector with zeros
test8 :: Test
test8 = TestCase (assertEqual "vectorDiv 5 [0,0,0] should be [0,0,0]" [0,0,0] (vectorDiv 5 [0,0,0]))

-- Vector with floating-point elements
test9 :: Test
test9 = TestCase (assertEqual "vectorDiv 2 [1.5,2.5,3.5] should be [0.75,1.25,1.75]" [0.75,1.25,1.75] (vectorDiv 2 [1.5,2.5,3.5]))

-- Empty vector
test10 :: Test
test10 = TestCase (assertEqual "vectorDiv 3 [] should be []" [] (vectorDiv 3 []))

-- Division by zero (checking for Infinity or NaN behavior)
test11 :: Test
test11 = TestCase (do
  let result = vectorDiv 0 [1,2,3]
  assertBool "vectorDiv 0 [1,2,3] should produce [Infinity,Infinity,Infinity]" (all (\x -> x == 1/0) result))

-- Mean of two simple vectors
test12 :: Test
test12 = TestCase (assertEqual "vectorMean [[1,2], [3,4]] should be [2,3]" [2,3] (vectorMean [[1,2], [3,4]]))

-- Mean of three vectors
test13 :: Test
test13 = TestCase (assertEqual "vectorMean [[1,1], [2,2], [3,3]] should be [2,2]" [2,2] (vectorMean [[1,1], [2,2], [3,3]]))

-- Single vector
test14 :: Test
test14 = TestCase (assertEqual "vectorMean [[4,5]] should be [4,5]" [4,5] (vectorMean [[4,5]]))

-- Vectors with negative numbers
test15 :: Test
test15 = TestCase (assertEqual "vectorMean [[-1,2], [3,-4]] should be [1,-1]" [1,-1] (vectorMean [[-1,2], [3,-4]]))

-- Vectors with floating-point numbers
test16 :: Test
test16 = TestCase (assertEqual "vectorMean [[1.5,2.0], [2.5,4.0]] should be [2.0,3.0]" [2.0,3.0] (vectorMean [[1.5,2.0], [2.5,4.0]]))

-- Single cluster (k=1), all points averaged
test17 :: Test
test17 = TestCase (assertEqual "kmeans 1 0 [[1,1], [3,3]] [[0,0]] should be [[2,2]]" [[2,2]] (kmeans 1 0 [[1,1], [3,3]] [[0,0]]))

-- Two clusters (k=2), first iteration (it=0)
test18 :: Test
test18 = TestCase (assertEqual "kmeans 2 0 [[1,1], [4,4]] [[1,1], [5,5]] should be [[1,1], [4,4]]" [[1,1], [4,4]] (kmeans 2 0 [[1,1], [4,4]] [[1,1], [5,5]]))

-- Two clusters (k=2), second iteration (it=1)
test19 :: Test
test19 = TestCase (assertEqual "kmeans 2 1 [[1,1], [4,4]] [[1,1], [5,5]] should be [[4,4]]" [[4,4]] (kmeans 2 1 [[1,1], [4,4]] [[1,1], [5,5]]))

-- Base case (it >= k), should return empty list
test20 :: Test
test20 = TestCase (assertEqual "kmeans 2 2 [[1,1], [2,2]] [[0,0], [3,3]] should be []" [] (kmeans 2 2 [[1,1], [2,2]] [[0,0], [3,3]]))

-- Empty list of points
-- test21 :: Test
-- test21 = TestCase (assertEqual "kmeans 1 0 [] [[0,0]] should be [vectorMean []]" [vectorMean []] (kmeans 1 0 [] [[0,0]]))

-- Multiple points per cluster (k=2)
test22 :: Test
test22 = TestCase (assertEqual "kmeans 2 0 [[0,0], [1,1], [4,4], [5,5]] [[0,0], [5,5]] should be [[0.5,0.5], [4.5,4.5]]" [[0.5,0.5], [4.5,4.5]] (kmeans 2 0 [[0,0], [1,1], [4,4], [5,5]] [[0,0], [5,5]]))

testsKmeans :: Test
testsKmeans = TestList
  [ TestLabel "Test1" test1
  , TestLabel "Test2" test2
  , TestLabel "Test3" test3
  , TestLabel "Test4" test4
  , TestLabel "Test5" test5
  , TestLabel "Test6" test6
  , TestLabel "Test7" test7
  , TestLabel "Test8" test8
  , TestLabel "Test9" test9
  , TestLabel "Test10" test10
  , TestLabel "Test11" test11
  , TestLabel "Test12" test12
  , TestLabel "Test13" test13
  , TestLabel "Test14" test14
  , TestLabel "Test15" test15
  , TestLabel "Test16" test16
  , TestLabel "Test17" test17
  , TestLabel "Test18" test18
  , TestLabel "Test19" test19
  , TestLabel "Test20" test20
--   , TestLabel "Test21" test21
  , TestLabel "Test22" test22
  ]