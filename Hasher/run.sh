#!/bin/bash

rm -f main
g++ *.cpp *.h -o main
./main 2 ~/Documents/TaMaterials/GenomeAnalysisAlgorithm/chr2L1.fa > stats.txt
# ./main 10 ~/Documents/TaMaterials/data.txt