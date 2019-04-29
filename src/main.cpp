#include "utils.h"
#include "algorithms.h"
using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 4) {
        cout << "./main.exe <threads> <buckets> <algorithm>" << endl;
        return 1;
    }

    // Parsing arguments
    int threads = atoi(argv[1]);
    int buckets = atoi(argv[2]);
    int algorithm = atoi(argv[3]);

    // Init variables
    vector<int> result;
    double start_time = omp_get_wtime();

    // Set amount of threads in omp
    omp_set_num_threads(threads);
    
    // Trigger choosen algorithm
    switch(algorithm) {
        case 1:
            result = sort1(threads, buckets);

            break;
            
        case 2:
            result = sort2(threads, buckets);

            break;
        case 3:
            result = sort3(threads, buckets);

            break;
        default:
            cout << "No algorithm with this id." << endl;
            return 1;
    }

    // Print overall algorithm time
    cout << "Overall time: " << (omp_get_wtime() - start_time) << "s" << endl;

    // Print result
    printVector(result);
}