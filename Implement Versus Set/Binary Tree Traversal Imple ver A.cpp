#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node *left, *right;
	
	Node() {
		this->data = 0;
		this->left = NULL;
		this->right = NULL;
	}
	
	Node(int data) {
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

typedef vector<Node> vn;
typedef vector<int> vi;

void inorder(Node *ptr) {
	if (ptr) {
		inorder(ptr->left);
		cout << ptr->data << ' ';
		inorder(ptr->right);
	}
}

void toString(vn &nodes) {
	for (const auto node : nodes) {
		cout << node.data << ' ';
		
	}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	// 이진트리를 담을 배열 생성
	const int SIZE = 15;
	vn nodes(SIZE+1);
	
	// 노드 별 데이터 초기화
	for (int i=1; i<=SIZE; i++) {
		nodes[i] = Node(i);
	}
	
	// 자식 노드 설정
	for (int i=1; i<=SIZE; i++) {
		if (i % 2 == 0) {
			nodes[i / 2].left = &nodes[i];
		} else {
			nodes[i / 2].right = &nodes[i];
		}
	}
	
	inorder(&nodes[1]);
	
	return 0;
}