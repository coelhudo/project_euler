numberToList :: (Integral a) => a -> [a]
numberToList 0 = []
numberToList n  = n `mod` 10 : (numberToList (n `div` 10))

main = do
       print . sum $ numberToList (2^1000)
