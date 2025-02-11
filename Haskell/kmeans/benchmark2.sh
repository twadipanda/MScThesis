#!bin/bash
echo "cores,runtime" > runtime2.csv
for cores in 1 2 4 6 8 10 12 14 16 18 20 22 24 26 28 30
 do
  for k in 1 2 3
   do
    echo -n $cores >> runtime2.csv
    echo -n "," >> runtime2.csv
    #printf "%s" "$(cabal exec -- haskell-totient 1 $inputSize +RTS -N$cores)" >> runtime.csv
    printf "%s" "$(srun --cpus-per-task=$cores --partition=amd-longq cabal exec k-means -- +RTS -ls -N$cores)" >> runtime2.csv
    echo "" >> runtime2.csv
   done
  done
done
