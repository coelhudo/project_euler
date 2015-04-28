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

generateAndCount :: (Int,Int) -> (Int,Int) -> Int
generateAndCount (x,y) (xlimit,ylimit)
    | (x == xlimit) && (y == ylimit) = 1
    | (x == xlimit) && (y < ylimit) = generateAndCount (xlimit, y+1) (xlimit,ylimit)
    | (x < xlimit) && (y == ylimit) = generateAndCount (x+1,ylimit) (xlimit,ylimit)
    | otherwise = generateAndCount (x+1,y) (xlimit,ylimit) + generateAndCount (x,y+1) (xlimit,ylimit)

-- Final solution - still slow but it works. There are a plenty of better solutions in the forum
generateHalfAndCount :: (Int,Int) -> (Int,Int) -> Int -> Int
generateHalfAndCount (x,y) (xlimit,ylimit) accu
    | (x == xlimit) && (y == ylimit) = accu + 1
    | (x == xlimit) && (y < ylimit) = generateHalfAndCount (xlimit, y+1) (xlimit,ylimit) accu
    | (x < xlimit) && (y == ylimit) = generateHalfAndCount (x+1,ylimit) (xlimit,ylimit) accu
    | (x == y) = 2 * generateHalfAndCount (x+1,y) (xlimit,ylimit) accu
    | otherwise = generateHalfAndCount (x+1,y) (xlimit,ylimit) (accu + (generateHalfAndCount (x,y+1) (xlimit,ylimit) 0))

main = do
      --print (countLeaves (generate (0,0) (14,14)))
      print (generateHalfAndCount (0,0) (20,20) 0)

