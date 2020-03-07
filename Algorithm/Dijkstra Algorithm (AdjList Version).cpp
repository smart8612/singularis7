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
  for (int i = 1; i < vec.size(); i++) {
		if (vec[i] != INF) {
			cout << vec[i] << '\n';
		} else {
			cout << "INF" << '\n';
		}
	}
}

vi dijkstra(vprii &adjList, int start) {
	const int SIZE = adjList.size();
	vi visited(SIZE, 0);
	vi distance(SIZE, INF);
	
	pque pq;
	pq.push(pri(0, start));
	distance[start] = 0;
	
	while(!pq.empty()) {
		int node = pq.top().second;
		int weight = -pq.top().first;
		pq.pop();
		
		if (visited[node]) continue;
		visited[node] = true;
		
		for (auto &each : adjList[node]) {
			int next = each.first;
			int nextweight = weight + each.second;
			if (nextweight < distance[next]) {
				distance[next] = nextweight;
				pq.push(pri(-distance[next], next));
			}
		}
	}
	
	return distance;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int V, E, K;
	cin >> V >> E >> K;
	
	vprii adjlist(V+1);
	for (int i=0; i<E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		pri tmp = pri(v, w);
		adjlist[u].push_back(tmp);
	}
	
	vi minDistanceTable = dijkstra(adjlist, K);
	toString(minDistanceTable);
	
	return 0;
}