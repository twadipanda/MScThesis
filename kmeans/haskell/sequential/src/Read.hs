-- | Handles reading and parsing input data for K-Means clustering.
module Read where

-- | Parses a list of strings into a list of vectors.
--
-- Arguments:
-- * List of strings, where each string contains space-separated numbers.
--
-- Returns: A list of vectors, where each vector is a list of Doubles.
parseInput :: [String] -> [[Double]]
parseInput [] = []
parseInput (x:xs) = (map read $ words x :: [Double]):(parseInput xs)

-- | Reads a file and returns its contents as a list of lines.
--
-- Arguments:
-- * File path as a String.
--
-- Returns: IO action yielding a list of strings (lines from the file).
reada :: String -> IO [String]
reada x = do content <- readFile x
             return $ lines content