#!bin/bash
echo "cores,runtime" > runtime.csv
for cores in 1 2 4 6 8 10 12 14 16 18 20 22 24 26 28 30 32 36 40 44 48 52 56 60 64
 do
  for k in 1 2 3 4 5
   do
    echo -n $cores >> runtime.csv
    echo -n "," >> runtime.csv
    #printf "%s" "$(cabal exec -- haskell-totient 1 $inputSize +RTS -N$cores)" >> runtime.csv
    printf "%s" "$(srun --cpus-per-task=$cores --partition=amd-longq ./charm-v7.0.0/bin/charmrun +p$cores ./kmeans ++quiet)" >> runtime.csv
    echo "" >> runtime.csv
   done
  done
done
