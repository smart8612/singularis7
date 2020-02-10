#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;

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
	
	vi parent(11);
	// 각 노드는 자기 자신에게만 속해있음
	for (int i=1; i<parent.size(); i++) {
		parent[i] = i;
	}
	
	unionParent(parent, 1, 2);
	
	cout << "1 & 2? : " << findParent(parent, 1, 2) <<'\n';
	cout << "2 & 3? : " << findParent(parent, 2, 3) <<'\n';
	
	return 0;
}