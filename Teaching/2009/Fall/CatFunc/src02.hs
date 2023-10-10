-- -*- mode: haskell; haskell-program-name: "hugs -98" -*- 

module Src02 where

import Data.List (nub,sort)
import Data.Monoid
import Data.Foldable

data IntSet = Iset [Int]

iset'ex1 = Iset [1,2,3]

iseq :: IntSet -> IntSet -> Bool
iseq (Iset s) (Iset s') = (sort $ nub s) == (sort $ nub s')

instance Eq IntSet where
  (==) = iseq

data Set a = Set [a] deriving Show

sseq :: (Eq a,Ord a) => Set a -> Set a -> Bool
sseq (Set s) (Set s') = (sort $ nub s) == (sort $ nub s')

instance (Eq a,Ord a) => Eq (Set a) where
    (==) = sseq

data InfNat = PosInt Integer | Infty deriving (Show,Eq)

instance Num InfNat where
    a + Infty = a
    Infty + b = b
    (PosInt a) + (PosInt b) = PosInt $ min a b
    a * Infty =Infty
    Infty * b = Infty
    (PosInt a) * (PosInt b) = PosInt (a + b)
    (-) = error "FOOBAR"
    abs = undefined
    negate = undefined
    signum = undefined
    fromInt = undefined
    fromInteger = PosInt

class Semiring a where
    one :: a
    zero :: a
    combine :: a -> a -> a
    extend :: a -> a -> a

type Var = String
newtype INT = INT Int


instance (Monoid (Sum a),Monoid (Product a)) => Semiring a where
  one = getProduct mempty
  zero = getSum mempty
  extend a a' = getProduct ((Product a) `mappend`  (Product a'))
  combine a a' = getSum ((Sum a) `mappend` (Sum a'))

data Tree a = Leaf a | Branch (Tree a) (Tree a) deriving Show

treesum :: Num a => Tree a -> a
treesum (Leaf a) = a
treesum (Branch t1 t2) = (treesum t1) + (treesum t2)

treefold :: Monoid b => (a -> b) -> Tree a -> b
treefold f (Leaf a) = f a
treefold f (Branch t1 t2) = (treefold f t1) `mappend`  (treefold f t2)

monoTreeSum t = getSum $ foldMap Sum t
monoTreeProd t = getProduct $ foldMap Product t

monoTreeAny p = getAny . (foldMap (Any . p))

instance Foldable Tree where
    foldMap = treefold