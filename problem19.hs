import qualified Data.Map as Map

totalDefault = 365
totalLeap = 366

monthsByYear :: Int -> Int -> [Int] -> [Int]
monthsByYear init end result | isCentury && init `mod` 400 == 0 = monthsByYear nextYear end $ totalLeap : result
                             | (not isCentury) && init `mod` 4 == 0 = monthsByYear nextYear end $ totalLeap : result
                             | init /= end = monthsByYear nextYear end $ totalDefault : result
                             | otherwise = result
                             where nextYear = succ init
                                   isCentury = init `mod` 100 == 0

main = do
       print $ monthsByYear 1999 2000 []
