#!/bin/bash

rm -f main
g++ *.cpp *.h -o main
./main 12 ~/Documents/TaMaterials/GenomeAnalysisAlgorithm/chr2L.fa > stats.txt
# ./main 8 ~/Documents/TaMaterials/GenomeAnalysisAlgorithm/data.fa