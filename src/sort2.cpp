#include "algorithms.h"
#include "utils.h"
using namespace std;


vector<int> sort2(int threads, int buckets) {
    vector<vector<vector<int > > > bs = getBucketsStructure(threads, buckets);
    vector<int> v = getUnsortedVector();
    vector<int> result;

    double bucket_interval = 100 / buckets;
    double splitting_start, splitting_end;
    double sorting_start, sorting_end;
    double concating_buckets_start, concating_buckets_end;

    // Splitting into buckets
    splitting_start = omp_get_wtime();

    #pragma omp parallel for shared(bs, v, bucket_interval) schedule(dynamic)
    for (int i = 0; i < buckets; i++) {
        for (int j = 0; j < v.size(); j++) {
            if (v[j] >= i*bucket_interval && v[j] <= (i+1)*bucket_interval) {
                bs[0][i].push_back(v[j]);
            }
        }
    }

    splitting_end = omp_get_wtime();


    // Sorting elements in buckets
    sorting_start = omp_get_wtime();

    #pragma omp parallel for schedule(dynamic)
    for (int i = 0; i < buckets; i++) {
        quicksort(bs[0][i], 0, bs[0][i].size()-1);
    }
    sorting_end = omp_get_wtime();


    // Concat buckets
    concating_buckets_start = omp_get_wtime();

    for (int i = 0; i < buckets; i++) {
        result.insert(result.end(), bs[0][i].begin(), bs[0][i].end());
    }
    concating_buckets_end = omp_get_wtime();


    // Print results
    cout << (splitting_end-splitting_start) << "; ";
    cout << "0.0; ";
    cout << (sorting_end-sorting_start) << "; ";
    cout << (concating_buckets_end-concating_buckets_start) << "; ";

    return result;
}