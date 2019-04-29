#include "utils.h"

using namespace std;

vector <vector<vector < int>> >

getBucketsStructure(int threads, int buckets) {
    vector<int> v3(1, 0);
    vector <vector<int>> v2(buckets, v3);
    vector < vector < vector < int > > > v1(threads, v2);

    return v1;
}

void printBucketStructure(vector < vector < vector < int > > > v) {
    for (int i = 0; i < v.size(); i++) {
        cout << "thread " << i << endl;
        for (int j = 0; j < v[i].size(); j++) {
            cout << "bucket " << j << endl;
            for (int k = 0; k < v[i][j].size(); k++) {
                cout << v[i][j][k] << " ";
            }
            cout << endl;
        }
    }
}

vector<int> getUnsortedVector() {
    vector<int> v;

    for (int i = 0; i < ELEMENTS_AMOUNT; i++) {
        v.push_back(rand() % (100 + 1));
    }

    return v;
}

void printVector(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }

    cout << endl;
}

void quicksort(vector<int> &vec, int l, int r) {
    int i, j, mid, piv;
    i = l;
    j = r;
    mid = l + (r - l) / 2;
    piv = vec[mid];

    while (i < r || j > l) {
        while (vec[i] < piv)
            i++;
        while (vec[j] > piv)
            j--;

        if (i <= j) {
            swap(vec, i, j); //error=swap function doesnt take 3 arguments
            i++;
            j--;
        } else {
            if (i < r)
                quicksort(vec, i, r);
            if (j > l)
                quicksort(vec, l, j);
            return;
        }
    }
}

void swap(vector<int>& v, int x, int y) {
    int temp = v[x];
    v[x] = v[y];
    v[y] = temp;
}
