import System.IO
import Control.Monad

main = do
        let list = []
        handle <- openFile "problem18_set2.txt" ReadMode
        contents <- hGetContents handle
        let singlelines = lines contents
            list = wordsToInt $ map words singlelines
            path = maximumPathSum 2 $ reverse list
        print $ maximum path
        hClose handle

wordsToInt :: [[String]] -> [[Int]]
wordsToInt = map wordToInt

wordToInt :: [String] -> [Int]
wordToInt = map read

combinea :: [Int] -> [Int] -> Int -> [Int]
combinea xs [] current = []
combinea xs ys current = map (+ head ys) (take current xs) ++ (combinea (drop (current `div` 2) xs) (tail ys) current)

maximumPathSum :: Int -> [[Int]] -> [Int]
maximumPathSum current (xs:[]) = xs
maximumPathSum current (xs:ys:xxs) = maximumPathSum (2 * current) $ combinea xs ys current : xxs
