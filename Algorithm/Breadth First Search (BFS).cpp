#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;
typedef queue<int> quei;

vii convertAdjList(vii &matrix) {
	vii adjlist(matrix.size()+1);
	
	for (int row=0; row<matrix.size(); row++) {
		for (int col=0; col<matrix[row].size(); col++) {
			int data = matrix[row][col];
			if (data) {
				adjlist[row+1].push_back(col+1);
			}
		}
	}
	
	return adjlist;
}

void bfs(vii &data, int start) {
	vii adjlist = convertAdjList(data);
	vi visited(adjlist.size(), 0);
	quei q;
	
	q.push(start);
	visited[start] = 1;
	
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		cout << x << '\n';
		for (int i = 0; i < adjlist[x].size(); i++) {
			int y = adjlist[x][i];
			if (!visited[y]) {
				q.push(y);
				visited[y] = 1;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);	
	
	vii data = {
		vi({0, 1, 1, 0, 0, 0, 0}),
		vi({1, 0, 1, 1, 1, 0, 0}), 
		vi({1, 1, 0, 0, 0, 1, 1}), 
		vi({0, 1, 0, 0, 1, 0, 0}), 
		vi({0, 1, 0, 1, 0, 0, 0}), 
		vi({0, 0, 1, 0, 0, 0, 1}),
		vi({0, 0, 1, 0, 0, 1, 0})	
	};
	
	bfs(data, 1);
	
	return 0;
}