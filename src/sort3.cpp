#include "algorithms.h"
using namespace std;

vector<int> sort3(int threads, int buckets) {
    vector<vector<vector<int > > > bs = getBucketsStructure(threads, buckets);
    vector<int> v = getUnsortedVector();
    
    const double bucket_interval = 100 / buckets;
    
    // Splitting into buckets
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < buckets; j++) {
            if (v[i] >= j*bucket_interval && v[i] <= (j+1)*bucket_interval) {
                // bs[omp_get_thread_num()][j].elements.push_back(v[i]);
                bs[0][j].push_back(v[i]);
                
                break;
            }
        }
    }
    
    // Connecting buckets through threads and sorting into them
    for (int i = 0; i < buckets; i++) {
        for (int j = 1; j < threads; j++) {
            bs[0][i].insert(bs[0][i].end(), bs[j][i].begin(), bs[j][i].end());    
        }    
        
        quicksort(bs[0][i], 0, bs[0][i].size()-1);
    }
    
    // Concat buckets
    vector<int> result;
    for (int i = 0; i < buckets; i++) {
        result.insert(result.end(), bs[0][i].begin(), bs[0][i].end()); 
    }

    return result;
}