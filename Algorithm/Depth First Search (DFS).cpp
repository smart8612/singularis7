#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;

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

void dfs(vii &adjList, vi &visited, int start) {
	if (visited[start]) return;
	visited[start] = true;
	cout << start << '\n';
	
	for (int i=0; i<adjList[start].size(); i++) {
		int nextNode = adjList[start][i];
		dfs(adjList, visited, nextNode);
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
	
	vii adjList = convertAdjList(data);
	vi visited(data.size(), 0);
	
	dfs(adjList, visited, 1);
	
	return 0;
}