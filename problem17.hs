import qualified Data.Map as Map

numberDictionary = Map.fromList [(1, "one"),(2, "two"),(3, "three"),(4, "four"),(5, "five"),(6, "six"),(7, "seven"),(8, "eight"),(9, "nine"),(10, "ten"),(11, "eleven"),(12, "twelve"),(13, "thirteen"),(14, "fourteen"),(15, "fifteen"),(16, "sixteen"),(17, "seventeen"),(18, "eighteen"),(19, "nineteen"),(20, "twenty"),(30, "thirty"),(40, "forty"),(50, "fifty"),(60, "sixty"),(70, "seventy"),(80, "eighty"),(90, "ninety"),(100, "hundred"), (-1, "and")]

decompose :: Int -> [Int]
decompose x | hundredth >= 1 = [hundredth] ++ [100] ++ decompose (x - (100 * hundredth))
            | x `div` 20 >= 1 = [-1] ++ [10 * tenth] ++ decompose (x - (10 * tenth))
            | tenth >= 1 = [-1] ++ [x]
            | x == 0 = []
            | otherwise = [x]
            where hundredth = (x `div` 100)
                  tenth = (x `div` 10)

numberToName :: Int -> String
numberToName x = foldl (++) "" [extractName (Map.lookup number numberDictionary) | number <- decompose x]

extractName :: Maybe String -> String
extractName (Just x) = x

main = do
       print $ foldl (+) 0 $ [length $ numberToName n | n <- [1..999]] ++ [length "onethousand"]
       --print $ [numberToName n | n <- [1..999]] ++ ["onethousand"]
