#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <string>
#include <omp.h>
#include <vector>
#include <stdlib.h>

using namespace std;

const int ELEMENTS_AMOUNT = 10;

vector<vector<vector<int> > > getBucketsStructure(int threads, int buckets);
void printBucketStructure(vector<vector<vector<int> > > v);
vector<int> getUnsortedVector();
void printVector(vector<int> v);
void quicksort(vector<int>& v, int l, int r);
void swap(vector<int>& v, int x, int y);
bool isVectorSorted(vector<int> v);


#endif