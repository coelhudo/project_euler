data Tree a = EmptyTree | Node a (Tree a) (Tree a) deriving (Show,Read,Eq)

singleton :: a -> Tree a
singleton x = Node x EmptyTree EmptyTree

generate :: (Int,Int) -> (Int,Int) -> Tree (Int,Int)
generate (x,y) (xlimit,ylimit)
    | (x == xlimit) && (y == ylimit) = singleton (x,y)
    | (x == xlimit) && (y < ylimit) = Node (xlimit,y) (generate (xlimit, y+1) (xlimit,ylimit)) EmptyTree
    | (x < xlimit) && (y == ylimit) = Node (x,ylimit) EmptyTree (generate (x+1,ylimit) (xlimit,ylimit))
    | otherwise = Node (x,y) (generate (x+1,y) (xlimit,ylimit)) (generate (x,y+1) (xlimit,ylimit))

-- tail recursion solution
-- countLeaves :: Tree (Int,Int) -> Int -> Int
-- countLeaves (Node _ EmptyTree EmptyTree) accumulator = accumulator + 1
-- countLeaves (Node _ left EmptyTree) accumulator = countLeaves left accumulator
-- countLeaves (Node _ EmptyTree right) accumulator = countLeaves right accumulator
-- countLeaves (Node _ left right) accumulator = countLeaves left (countLeaves right accumulator)

countLeaves :: Tree (Int,Int) -> Int
countLeaves (Node _ EmptyTree EmptyTree) = 1
countLeaves (Node _ left EmptyTree) = countLeaves left
countLeaves (Node _ EmptyTree right) = countLeaves right
countLeaves (Node _ left right) = countLeaves left + countLeaves right


main = do
--       print (countLeaves (generate (0,0) (14,14)) 0)
       print (countLeaves (generate (0,0) (14,14)))

