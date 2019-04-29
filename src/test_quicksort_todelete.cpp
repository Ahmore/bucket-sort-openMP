#include "utils.h"
#include "algorithms.h"
using namespace std;

int main(int argc, char* argv[]) {
    vector<int> a = {3, 10, -1, 5, 4, 10, 3};
    printVector(a);
    quicksort(a, 0, a.size());
    printVector(a);
}