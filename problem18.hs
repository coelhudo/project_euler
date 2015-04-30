import System.IO
import Control.Monad

main = do
        let list = []
        handle <- openFile "problem18_set1.txt" ReadMode
        contents <- hGetContents handle
        let singlelines = lines contents
            list = wordsToInt $ map words singlelines
            path = maximumPathSum list 0 [head $ head list]
        print path
        print $ sum path
        hClose handle

wordsToInt :: [[String]] -> [[Int]]
wordsToInt = map wordToInt

wordToInt :: [String] -> [Int]
wordToInt = map read

maximumPathSum :: [[Int]] -> Int -> [Int] -> [Int]
maximumPathSum (x:[]) column accumulator = accumulator
maximumPathSum (x:y:xs) column accumulator = maximumPathSum (y:xs) findNextColumn (accumulator ++ [maxValue])
                where  maxValue = max (y !! column) (y !! nextColumn)
                       findNextColumn = if (y !! column) < (y !! nextColumn) then nextColumn else column
                       nextColumn = succ column
