#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;

const int INF = 999999;

void toString(vii &vec) {
	const int SIZE = vec.size();
	for (int i=0; i<SIZE; i++) {
		for (int j=0; j<SIZE; j++) {
			cout << vec[i][j] << ' ';
		}
		cout << '\n';
	}
}

vii floydWarshall(vii &matrix) {
	const int SIZE = matrix.size();
	vii distance(SIZE, vi(SIZE, 0));	
	
	for (int i=0; i<SIZE; i++) {
		for (int j=0; j<SIZE; j++) {
			distance[i][j] = matrix[i][j];
		}
	}
	
	for (int k=0; k<SIZE; k++) {
		for (int i=0; i<SIZE; i++) {
			for (int j=0; j<SIZE; j++) {
				int i_j = distance[i][j];
				int i_k_j = distance[i][k] + distance[k][j]; 
				distance[i][j] = min(i_j, i_k_j);
			}
		}
	}
	
	return distance;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	vii matrix = {
		vi({ 0 ,  5 , INF,  9 ,  1 }),
		vi({ 5 ,  0 ,  2 , INF, INF}),
		vi({INF,  2 ,  0 ,  7 , INF}),
		vi({ 9 , INF,  7 ,  0 ,  2 }),
		vi({ 1 , INF, INF,  2 ,  0 })
	};
	
	vii minDistance = floydWarshall(matrix);
	toString(minDistance);
	
	return 0;
}