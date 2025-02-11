module Read where

parseInput :: [String] -> [[Double]]
parseInput [] = []
parseInput (x:xs) = (map read $ words x :: [Double]):(parseInput xs)

reada :: String -> IO [String]
reada x = do content <- readFile x
             return $ lines content
