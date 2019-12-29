#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

void InsertionSort(vi &vec) {
	for (int i=0; i<vec.size(); i++) {
		for (int j=0; j<vec.size()-i-1; j++) {
			cout << vec[j] << ' ' << vec[j+1] << '\n';
			if (vec[j] > vec[j+1]) {
				swap(vec[j], vec[j+1]);
			}
		}
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
	InsertionSort(vec);
	printArray(vec);
	
	return 0;
}