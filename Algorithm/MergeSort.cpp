#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

void merge(vi &vec, vi &sorted, int start, int middle, int end) {
    int i = start;
    int j = middle + 1;
    int idx = start;
    
    while (i <= middle && j <= end) {
        sorted[idx++] = (vec[i] <= vec[j])? vec[i++] : vec[j++];
    }
    
	int k = (i > middle)?  j : i;
    while (k <= end) {
        sorted[idx++] = vec[k++];
    }
    
    for (int k=start; k<=end; k++) {
        vec[k] = sorted[k];
    }
}

void mergeSort(vi &vec, vi &sorted, int start, int end) {
    if (start >= end) return;
    
    int middle = (start + end) / 2;
	
    mergeSort(vec, sorted, start, middle);
    mergeSort(vec, sorted, middle+1, end);
    merge(vec, sorted, start, middle, end);
}

void printArray(vi &vec) {
    cout << '[';
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i];
        (i != vec.size()-1)? cout << ',' : cout << "]\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vi vec = {7, 6, 5, 8, 3, 4, 9, 1, 2};
	int SIZE = vec.size();
	vi sorted(SIZE);
    
    mergeSort(vec, sorted, 0, SIZE-1);
    printArray(vec);
    
    return 0;
}