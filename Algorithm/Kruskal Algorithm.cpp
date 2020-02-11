#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
	int vertexA, vertexB;
	int distance;
	
	Edge(int vertexA, int vertexB, int distance) {
		this->vertexA = vertexA;
		this->vertexB = vertexB;
		this->distance = distance;
	}
	
	bool operator <(Edge &edge) {
		return this->distance < edge.distance;
	}
};

typedef vector<int> vi;
typedef vector<Edge> ve;

int getParent(vi &parent, int node) {
	if (parent[node] == node) return node;
	return parent[node] = getParent(parent, parent[node]);
}

void unionParent(vi &parent, int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

bool findParent(vi &parent, int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a == b) return true;
	else return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	// MST를 찾을 그래프의 모든 간선을 인접리스트 형태로 변환
	ve vec;
	vec.push_back(Edge(1, 7, 12));
	vec.push_back(Edge(1, 4, 28));
	vec.push_back(Edge(1, 2, 67));
	vec.push_back(Edge(1, 5, 17));
	vec.push_back(Edge(2, 4, 24));
	vec.push_back(Edge(2, 5, 62));
	vec.push_back(Edge(3, 5, 20));
	vec.push_back(Edge(3, 6, 37));
	vec.push_back(Edge(4, 7, 13));
	vec.push_back(Edge(5, 6, 45));
	vec.push_back(Edge(5, 7, 73));
	
	// 간선의 distance 를 기준으로 정렬하고
	sort(vec.begin(), vec.end());
	
	// Union-Find 연산을 수행하기 전에 부모 테이블을 초기값으로 설정
	vi parent(8);
	for (int i=1; i<parent.size(); i++) {
		parent[i] = i;
	}
	
	int totalDistance = 0;
	for (auto &edge : vec) {
		if (!findParent(parent, edge.vertexA, edge.vertexB)) {
			totalDistance += edge.distance;
			unionParent(parent, edge.vertexA, edge.vertexB);
		} else {
			cout << "Distance: " << edge.distance << '\n';
		}
	}
	
	cout << "Total: " << totalDistance << '\n';
	
	return 0;
}