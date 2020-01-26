#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

void quickSort(vi &vec, int start, int end) {
    if (start >= end) return;
    
    int key = start;
    int i = start + 1;
    int j = end;
    
    while (i <= j) {
        while (i <= end && vec[i] <= vec[key]) i++;
        while (j > start && vec[j] >= vec[key]) j--;
        (i <= j)? swap(vec[i], vec[j]):swap(vec[key], vec[j]);
    }
    
    quickSort(vec, start, j-1);
    quickSort(vec, j+1, end);
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
    
    vi vec = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};
    
    quickSort(vec, 0, vec.size()-1);
    printArray(vec);
    
    return 0;
}