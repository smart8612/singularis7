#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;

class node {
public:
  int data;
  node *left;
  node *right;
  node(int data) {
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
  }
};

class BST {
public:
  node *root;
  BST() {
    this->root = nullptr;
  }
  node* insertTraversal(node *ptr, int data) {
    if (ptr == nullptr) {
      return new node(data);
    
    } else if (ptr->data > data) {
      ptr->left = insertTraversal(ptr->left, data);

    } else {
      ptr->right = insertTraversal(ptr->right, data);
    }

    return ptr;
  }
  void insert(int data) {
    this->root = insertTraversal(this->root, data);
  }
  void pot(node *ptr) {
    if (ptr != nullptr) {
      pot(ptr->left);
      pot(ptr->right);
      cout << ptr->data << '\n';
    }
  }
};

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  BST tree;
  int x;
  while (cin >> x) {
    tree.insert(x);
  }
  tree.pot(tree.root);

  return 0;
}
