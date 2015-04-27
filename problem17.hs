import qualified Data.Map as Map

numberDictionary = Map.fromList [(1, "one"),(2, "two"),(3, "three"),(4, "four"),(5, "five"),(6, "six"),(7, "seven"),(8, "eight"),(9, "nine"),(10, "ten"),(11, "eleven"),(12, "twelve"),(13, "thirteen"),(14, "fourteen"),(15, "fifteen"),(16, "sixteen"),(17, "seventeen"),(18, "eighteen"),(19, "nineteen"),(20, "twenty"),(30, "thirty"),(40, "fourty"),(50, "fifty"),(60, "sixty"),(70, "seventy"),(80, "eighty"),(90, "ninety"),(100, "hundred")]

decompose :: Int -> [Int]
decompose x | hundredth >= 1 = [100 * hundredth] ++ decompose (x - (100 * hundredth))
            | x `div` 20 >= 1 = [10 * tenth] ++ decompose (x - (10 * tenth))
            | tenth >= 1 = [x]
            | otherwise = [x]
            where hundredth = (x `div` 100)
                  tenth = (x `div` 10)
