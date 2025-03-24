#!bin/bash
echo "cores,runtime" > dim1024_runtime.csv
echo "cores,runtime" > g2_1024_100_runtime.csv
echo "cores,runtime" > letter_runtime.csv
echo "cores,runtime" > s1_runtime.csv
for cores in 2 4 6 8 10 14 18 22 26 30 34 38 42 46 50 54 60 64
 do
  for k in 1 2 3
   do
    echo -n $cores >> dim1024_runtime.csv
    echo -n "," >> dim1024_runtime.csv
    echo -n $cores >> g2_1024_100_runtime.csv
    echo -n "," >> g2_1024_100_runtime.csv
    echo -n $cores >> letter_runtime.csv
    echo -n "," >> letter_runtime.csv
    echo -n $cores >> s1_runtime.csv
    echo -n "," >> s1_runtime.csv
    #printf "%s" "$(cabal exec -- haskell-totient 1 $inputSize +RTS -N$cores)" >> runtime.csv
    printf "%s" "$(srun --cpus-per-task=$cores --partition=amd-longq ./charm-v7.0.0/bin/charmrun +p$cores ./kmeans ../../dim1024.txt 16 ++quiet)" >> dim1024_runtime.csv
    echo "" >> dim1024_runtime.csv
    printf "%s" "$(srun --cpus-per-task=$cores --partition=amd-longq ./charm-v7.0.0/bin/charmrun +p$cores ./kmeans ../../g2-1024-100.txt 2 ++quiet)" >> g2_1024_100_runtime.csv
    echo "" >> g2_1024_100_runtime.csv
    printf "%s" "$(srun --cpus-per-task=$cores --partition=amd-longq ./charm-v7.0.0/bin/charmrun +p$cores ./kmeans ../../letter.txt 26 ++quiet)" >> letter_runtime.csv
    echo "" >> letter_runtime.csv
    printf "%s" "$(srun --cpus-per-task=$cores --partition=amd-longq ./charm-v7.0.0/bin/charmrun +p$cores ./kmeans ../../s1.txt 15 ++quiet)" >> s1_runtime.csv
    echo "" >> s1_runtime.csv
  done
done
