toDigit :: Integer -> [Integer]
toDigit 0 = []
toDigit x | x < 0 = []
toDigit x | x `mod` 10 == x = [x]
toDigit x = toDigit (x `div` 10) ++ [(x `mod` 10)]

reversea :: [Integer] -> [Integer]
reversea [] = []
reversea (x:xs) = reversea xs ++ [x]

toDigitRev :: Integer -> [Integer]
toDigitRev = reversea . toDigit

doubleEveryOther :: [Integer] -> [Integer]
doubleEveryOther [] = []
doubleEveryOther [x] = [x]
doubleEveryOther (x:y:xs) = [x*2] ++ [y] ++ doubleEveryOther xs

sumDigits :: [Integer] -> Integer
sumDigits [] = 0
sumDigits [x] | x < 0 = 0
sumDigits [x] = x
sumDigits (x:xs) = (sumDigits . toDigit) + sumDigits xs

validate :: Integer -> Bool
validate x | mod (sumDigits (doubleEveryOther (toDigit x))) 10 == 0 = True
validate x = False

validatea :: Integer -> Integer
validatea x = mod (sumDigits (doubleEveryOther (toDigit x))) 10

mySum :: [Integer] -> Integer
mySum [] = 0
mySum (x:xs) = x + mySum xs
