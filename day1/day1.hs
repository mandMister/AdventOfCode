import           Data.List (sort, transpose)
import qualified Data.Map  as Map

-- "1 3\n2 4"
-- ["1 3", "2 4", ...]
-- [["1", "3"], ["2", "4"]]
-- [["1", "2"], ["3", "4"]]
parseContent :: String -> ([Integer], [Integer])
parseContent content = let columns = transpose (map words (lines content))
                       in (sort $ map read (head columns),
                           sort $ map read (columns !! 1))

absoluteSum :: [Integer] -> [Integer] -> Integer
absoluteSum l r = sum (zipWith (\l r -> abs $ l - r) l r)

calculateScore :: [Integer] -> [Integer] -> Integer
calculateScore l r =
  let counts = Map.fromListWith (+) [(x, 1) | x <- r]
  in sum [x * Map.findWithDefault 0 x counts | x <- l]

main :: IO()
main = do
  content <- readFile "input"
  let (l, r) = parseContent content
  print $ absoluteSum l r
  print $ calculateScore l r
