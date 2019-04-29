#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <iostream>
#include <string>
#include <omp.h>
#include <vector>
#include <stdlib.h>

using namespace std;

vector<int> sort1(int threads, int buckets);
vector<int> sort2(int threads, int buckets);
vector<int> sort3(int threads, int buckets);

#endif