#!bin/bash
echo "cores,runtime" > a1_runtime.csv
echo "cores,runtime" > a2_runtime.csv
echo "cores,runtime" > a3_runtime.csv
echo "cores,runtime" > birch1_runtime.csv
for cores in 2 4 6 8 10 14 18 22 26 30 34 38 42 46 50 54 60 64
 do
  for k in 1 2 3
   do
    echo -n $cores >> a1_runtime.csv
    echo -n "," >> a1_runtime.csv
    echo -n $cores >> a2_runtime.csv
    echo -n "," >> a2_runtime.csv
    echo -n $cores >> a3_runtime.csv
    echo -n "," >> a3_runtime.csv
    echo -n $cores >> birch1_runtime.csv
    echo -n "," >> birch1_runtime.csv
    #printf "%s" "$(cabal exec -- haskell-totient 1 $inputSize +RTS -N$cores)" >> runtime.csv
    printf "%s" "$(srun --cpus-per-task=$cores --partition=amd-longq cabal exec k-means -- ../../a1.txt 20 +RTS -N$cores)" >> a1_runtime.csv
    echo "" >> a1_runtime.csv
    printf "%s" "$(srun --cpus-per-task=$cores --partition=amd-longq cabal exec k-means -- ../../a2.txt 35 +RTS -N$cores)" >> a2_runtime.csv
    echo "" >> a2_runtime.csv
    printf "%s" "$(srun --cpus-per-task=$cores --partition=amd-longq cabal exec k-means -- ../../a3.txt 50 +RTS -N$cores)" >> a3_runtime.csv
    echo "" >> a3_runtime.csv
    printf "%s" "$(srun --cpus-per-task=$cores --partition=amd-longq cabal exec k-means -- ../../birch1.txt 100 +RTS -N$cores)" >> birch1_runtime.csv
    echo "" >> birch1_runtime.csv
    # mv k-means.eventlog "k-means_$cores$k.eventlog"
  done
done
