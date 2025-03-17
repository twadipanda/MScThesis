-- module Read where

-- import qualified Data.Vector as V
-- import qualified Data.Vector.Unboxed as U

-- parseInput :: V.Vector String -> V.Vector (U.Vector Double)
-- parseInput lines = V.map parseLine lines
--   where
--     parseLine :: String -> U.Vector Double
--     parseLine line = U.fromList $ map read $ words line

-- reada :: String -> IO (V.Vector String)
-- reada filename = do
--   content <- readFile filename
--   return $ V.fromList $ lines content

module Read where

parseInput :: [String] -> [[Double]]
parseInput [] = []
parseInput (x:xs) = (map read $ words x :: [Double]):(parseInput xs)

reada :: String -> IO [String]
reada x = do content <- readFile x
             return $ lines content