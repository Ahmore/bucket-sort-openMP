#include "algorithms.h"
#include "utils.h"
using namespace std;

vector<int> sort1(int threads, int buckets) {
    vector<vector<vector<int > > > all_buckets = getBucketsStructure(1, buckets, true);
    vector<int> origin_table = getUnsortedVector();
    vector<int> result_table;
    vector<int> indexes(buckets, 0);

    double buckets_interval = 100 / buckets;
    double splitting_start, splitting_end;
    double sorting_start, sorting_end;
    double concatenating_buckets_start, concatenating_buckets_end;

    splitting_start = omp_get_wtime();

    #pragma omp parallel for shared(all_buckets, origin_table, buckets_interval) schedule(static, origin_table.size()/threads)
    for (int i = 0; i < origin_table.size(); i++) {
        for (int j = 0; j < buckets; j++) {
            if (origin_table[i] >= j*buckets_interval && origin_table[i] <= (j+1)*buckets_interval) {
                all_buckets[0][j][indexes[j]++] = origin_table[i];

                break;
            }
        }
    }
    splitting_end = omp_get_wtime();
    
    sorting_start = omp_get_wtime();

    #pragma omp parallel for schedule(dynamic)
    for (int i = 0; i < buckets; i++) {
        quicksort(all_buckets[0][i], 0, indexes[i]-1);
    }
    sorting_end = omp_get_wtime();
    
    concatenating_buckets_start = omp_get_wtime();

    for (int i = 0; i < buckets; i++) {
        result_table.insert(result_table.end(), all_buckets[0][i].begin(), all_buckets[0][i].begin() + indexes[i]-1);
    }
    concatenating_buckets_end = omp_get_wtime();

    
    cout << (splitting_end-splitting_start) << "; ";
    cout << (sorting_end-sorting_start) << "; ";
    cout << (concatenating_buckets_end-concatenating_buckets_start) << "; ";

    return result_table;
}

