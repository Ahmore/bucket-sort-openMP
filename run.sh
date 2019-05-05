#!/bin/bash

# Compile
g++ -fopenmp -o main.exe src/main.cpp src/utils.cpp src/sort1.cpp src/sort2.cpp src/sort3.cpp

# Make results dir
mkdir results;

# Make experiments
for ALGORITHM in 1 3
do
	for BUCKETS in 5 10 15 20 25
	do
		for THREADS in {1..8}
		do 
			./main.exe ${THREADS} ${BUCKETS} ${ALGORITHM} >> results/out_${ALGORITHM}_${BUCKETS}.txt
		done
	done
done

