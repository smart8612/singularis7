#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> pri;
typedef vector<pri> vpri;
typedef vector<vpri> vprii;
typedef priority_queue<pri> pque;

const int INF = 999999;

void toString(vi &vec) {
    cout << '[';
    for (int i = 1; i < vec.size(); i++) {
        cout << vec[i];
        (i != vec.size()-1)? cout << ',' : cout << "]\n";
    }
}

vprii toAdjList(vii &matrix) {
	const int SIZE = matrix.size();
	
	vprii adjlist(SIZE+1);
	
	for (int row=0; row<SIZE; row++) {
		for (int col=0; col<SIZE; col++) {
			int data = matrix[row][col];
			if (INF > data) {
				pri tmp = pri(col+1, data);
				adjlist[row+1].push_back(tmp);
			}
		}
	}
	
	return adjlist;
}

vi dijkstra(vii &matrix, int start) {
	vprii adjList = toAdjList(matrix);
	
	const int SIZE = matrix.size()+1;
	vi visited(SIZE, 0);
	vi distance(SIZE, INF);
	
	pque pq;
	pq.push(pri(start, 0));
	distance[start] = 0;
	
	while(!pq.empty()) {
		int node = pq.top().first;
		int weight = -pq.top().second;
		pq.pop();
		
		if (visited[node]) continue;
		visited[node] = true;
		
		for (auto &each : adjList[node]) {
			int next = each.first;
			int nextweight = weight + each.second;
			if (nextweight < distance[next]) {
				distance[next] = nextweight;
				pq.push(pri(next, -nextweight));
			}
		}
	}
	
	return distance;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	vii matrix = {
		vi({ 0 ,  2,  5,  1, INF, INF}),
		vi({ 2 ,  0,  3,  2, INF, INF}),
		vi({ 5 ,  3,  0,  3,  1,   5 }),
		vi({ 1 ,  2,  3,  0,  1,  INF}),
		vi({INF, INF, 1,  1,  0,   2 }),
		vi({INF, INF, 5, INF, 2,   0 })
	};
	
	vi minDistanceTable = dijkstra(matrix, 1);
	toString(minDistanceTable);
	
	return 0;
}