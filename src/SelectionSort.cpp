#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

void SelectionSort(vi &vec) {
	for (int i=0; i<vec.size(); i++) {
		int minIdx = i;
		for (int j=i+1; j<vec.size(); j++) {
			if (vec[minIdx] > vec[j]) minIdx = j;
		}
		swap(vec[minIdx], vec[i]);
	}
}

void printArray(vi &vec) {
	cout << '[';
	for (int i=0; i<vec.size(); i++) {
		cout << vec[i];
		(i != vec.size()-1)? cout << ',' : cout << ']';
	}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	vi vec = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};
	SelectionSort(vec);
	printArray(vec);
	
	return 0;
}