
---

# Genetic Algorithms, K-Means, and Particle Swarm Optimization

This project implements **K-Means Clustering**, **Genetic Algorithms (GA)**, and **Particle Swarm Optimization (PSO)** in both **sequential** and **parallel** versions. The implementations are written in **C++** and **Haskell**, leveraging parallelism with **Charm++** for C++ and **Haskell Strategies** for Haskell. The goal is to provide a comparative framework for these optimization and clustering algorithms across different languages and parallelization techniques.

## Project Overview

- **Algorithms**: K-Means, Genetic Algorithm, Particle Swarm Optimization
- **Languages**: C++ and Haskell
- **Parallelism**:
  - **C++**: Uses Charm++ for parallel execution.
  - **Haskell**: Uses Haskell Strategies for parallel execution.
- **Structure**: Each algorithm has its own directory, with subdirectories for the implementation technology (C++/Charm++ or Haskell) and further divided into `parallel` and `sequential` versions.

## Directory Structure

```
.
├── kmeans
│   ├── charm++
│   │   ├── parallel    # Parallel K-Means in C++ with Charm++
│   │   │   └── Makefile
│   │   └── sequential  # Sequential K-Means in C++
│   │       └── Makefile
│   └── haskell
│       ├── parallel    # Parallel K-Means in Haskell
│       │   └── kmeans.cabal
│       └── sequential  # Sequential K-Means in Haskell
│           └── kmeans.cabal
├── ga
│   ├── charm++
│   │   ├── parallel    # Parallel GA in C++ with Charm++
│   │   │   └── Makefile
│   │   └── sequential  # Sequential GA in C++
│   │       └── Makefile
│   └── haskell
│       ├── parallel    # Parallel GA in Haskell
│       │   └── ga.cabal
│       └── sequential  # Sequential GA in Haskell
│           └── ga.cabal
├── pso
│   ├── charm++
│   │   ├── parallel    # Parallel PSO in C++ with Charm++
│   │   │   └── Makefile
│   │   └── sequential  # Sequential PSO in C++
│   │       └── Makefile
│   └── haskell
│       ├── parallel    # Parallel PSO in Haskell
│       │   └── pso.cabal
│       └── sequential  # Sequential PSO in Haskell
│           └── pso.cabal
└── README.md
```

## Prerequisites

### For C++ Implementations
- **g++**: C++ compiler (e.g., GCC).
- **Charm++**: Required for parallel C++ implementations. Install it by following the [Charm++ installation guide](https://charm.cs.illinois.edu/software).

### For Haskell Implementations
- **GHC**: Glasgow Haskell Compiler (version compatible with base >=4.13).
- **Cabal**: Haskell package manager (version >= 1.10).
- **Dependencies**: Install required Haskell libraries:
  ```bash
  cabal update
  cabal install random split normaldistribution criterion-measurement deepseq parallel
  ```

## Building and Running

### C++ Implementations (with Makefile)

Each `charm++/parallel` and `charm++/sequential` directory contains a `Makefile` to compile the code.

1. **Navigate to the desired directory**:
   ```bash
   cd ga/charm++/parallel  # Example for parallel GA
   ```

2. **Build the project**:
   ```bash
   make
   ```
   This compiles the source files (e.g., `main.cpp`, `ga.cpp`) into an executable named after the algorithm (e.g., `ga`).

3. **Run the executable**:
   ```bash
   ./ga
   ```

4. **Clean up (optional)**:
   ```bash
   make clean
   ```
   This removes object files and the executable.

#### Notes for Charm++ (Parallel C++)
- Ensure Charm++ is installed and configured.
- You may need to adjust the `Makefile` to include Charm++-specific flags (e.g., linking with `charmc` instead of `g++`).

### Haskell Implementations (with Cabal)

Each `haskell/parallel` and `haskell/sequential` directory contains a `.cabal` file (e.g., `ga.cabal`) to build and run the code.

1. **Navigate to the desired directory**:
   ```bash
   cd ga/haskell/parallel  # Example for parallel GA
   ```

2. **Build the project**:
   ```bash
   cabal build
   ```
   This compiles the Haskell source files (e.g., `Main.hs`, `GA.hs`) with optimizations (`-O2`) and threading support.

3. **Run the executable**:
   ```bash
   cabal run ga
   ```
   For parallel execution, you can specify runtime options:
   ```bash
   cabal run ga -- +RTS -N -RTS
   ```
   `-N` enables all available CPU cores for parallelism.

4. **Clean up (optional)**:
   ```bash
   cabal clean
   ```

## Example Files
- **Makefile** (C++): Compiles `.cpp` files into object files and links them into an executable.
- **ga.cabal** (Haskell): Specifies dependencies, source directories, and GHC options like `-threaded` for parallelism.

## Contributing
Feel free to fork this repository, submit issues, or contribute improvements via pull requests.

## License
See the [LICENSE](LICENSE) file for details.

---