import qualified Data.Map as Map

data Tree a = EmptyTree | Node a (Tree a) (Tree a) deriving (Show,Read,Eq,Ord)

singleton :: a -> Tree a
singleton x = Node x EmptyTree EmptyTree

generate :: (Int,Int) -> (Int,Int) -> Tree (Int,Int)
generate (x,y) (xlimit,ylimit)
    | (x == xlimit) && (y == ylimit) = singleton (x,y)
    | (x == xlimit) && (y < ylimit) = Node (xlimit,y) (generate (xlimit, y+1) (xlimit,ylimit)) EmptyTree
    | (x < xlimit) && (y == ylimit) = Node (x,ylimit) EmptyTree (generate (x+1,ylimit) (xlimit,ylimit))
-- Remove redundancies
    | (x == y) = Node (x,y) (generate (x+1,y) (xlimit,ylimit)) EmptyTree 
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

--Final solution - still slow but it works. There are a plenty of better solutions in the forum
countPossiblePathsFrom  :: (Int,Int) -> Int -> Int -> Int
countPossiblePathsFrom  (x,y) limit accu
    | (x == limit) && (y == limit) = accu + 1
    | (x == limit) && (y < limit) = countPossiblePathsFrom  (limit, y+1) limit accu
    | (x < limit) && (y == limit) = countPossiblePathsFrom  (x+1,limit) limit accu
    | (x == y) = 2 * countPossiblePathsFrom  (x+1,y) limit accu
    | otherwise = countPossiblePathsFrom  (x+1,y) limit (accu + (countPossiblePathsFrom  (x,y+1) limit 0))

main = do
      print (countPossiblePathsFrom  (0,0) 14 0)

