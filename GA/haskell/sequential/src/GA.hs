-- | This module implements the core functionality of a Genetic Algorithm (GA).
module GA (initializePopulation, gaIterate) where 

import System.Random (newStdGen, randomRs)
import Data.List.Split (chunksOf)
import Heuristics (simiulatedBinary, gaussianMutate, tournamentSelection)
import Benchmark (sphere)
import Helpers (beta, randomNumbers, normalNoise)

-- | Initializes a population of individuals for the GA.
--
-- Generates a population of 'numIndividual' individuals, each with 'chromosome' genes,
-- where each gene is a random value in the range [-1, 1].
--
-- Arguments:
--   * numIndividual - The number of individuals in the population.
--   * chromosome - The number of genes per individual.
--
-- Returns: An IO action yielding a list of individuals, where each individual is a list of doubles.
initializePopulation :: Int -> Int -> IO ([[Double]])
initializePopulation numIndividual chromosome  = do
  gen <- newStdGen
  let population = take (numIndividual * chromosome) (randomRs (-1, 1) gen :: [Double])
  return $ chunksOf chromosome population

-- | Evaluates the fitness of a population using a given fitness function.
--
-- Applies the fitness function 'f' to each individual in the population.
--
-- Arguments:
--   * population - The list of individuals to evaluate.
--   * f - The fitness function to apply to each individual.
--
-- Returns: A list of fitness values corresponding to the population.
evaluate :: [[Double]] -> ([Double] -> Double) -> [Double]
evaluate population f = map f population

-- | Performs one iteration of the GA, evolving the population toward an optimal solution.
--
-- Iterates up to 10,000 times, using elitism, tournament selection, simulated binary crossover,
-- and Gaussian mutation. Stops at 10,000 iterations and returns the best fitness value.
--
-- Arguments:
--   * iter - The current iteration number (starts at 0).
--   * population - The current population of individuals.
--   * elites - The number of elite individuals to preserve unchanged.
--   * selectionSize - The size of the tournament for selection.
--   * distributionIndex - The distribution index for simulated binary crossover.
--
-- Returns: An IO action yielding the minimum fitness value after iterations complete.
gaIterate :: Int -> [[Double]] -> Int -> Int -> Double -> IO (Double)
gaIterate iter population elites selectionSize distributionIndex
  | iter == 10000 = do
    putStrLn "Iterations completed"
    return $ minimum $ evaluate population sphere
  | otherwise = do
    let populationSize = length population
    beta_ <- beta distributionIndex
    randNS <- randomNumbers (populationSize*selectionSize) (populationSize - 1)
    let selectedPopulation = tournamentSelection population (evaluate population sphere) (randNS) elites selectionSize
    let elitePop = take elites selectedPopulation
    let nonElitePop = drop elites selectedPopulation
    let offspring = concat $ zipWith (\x y -> simiulatedBinary x y beta_) (take (div (populationSize - elites) 2) nonElitePop) (drop (div (populationSize - elites) 2) nonElitePop)
    let offspringSize = length $ offspring!!0
    randNM <- randomNumbers offspringSize 9
    normalN <- normalNoise offspringSize
    let mutated = map (\x -> gaussianMutate x (randNM) (normalN)) offspring
    let newPopulation = elitePop ++ mutated
    gaIterate (iter+1) newPopulation elites selectionSize distributionIndex
