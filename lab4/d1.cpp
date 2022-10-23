#include <bits/stdc++.h>
using namespace std;

struct Node {
	int val;
	Node* left;
	Node* right;

	Node(int val) {
		this->val = val;
		this->left = nullptr;
		this->right = nullptr;
	}
};

struct BST {
private:
	Node* root;
	
	Node* _insert(Node* cur, int val) {
		if (!cur) {
			return new Node(val);
		}
		if (val > cur->val) {
			cur->right = _insert(cur->right, val);
		} else if (val < cur->val) {
			cur->left = _insert(cur->left, val);
		}
		return cur;
	}


	int _getSize(Node* node) {
		if (!node) return 0;
		return _getSize(node->left) + _getSize(node->right) + 1;
	}

	Node* _search(Node* cur, int target) {
		if (!cur) return nullptr;
		if (cur->val == target) return cur;
		else {
			Node* found = _search(cur->left, target);
			if (found == nullptr) {
				found = _search(cur->right, target);
			}
			return found;
		}
		return nullptr;
	}

public:
	BST() {
		this->root = nullptr;
	}

	void insert(int val) {
		Node* newNode = _insert(root, val);
		if (root == nullptr) root = newNode;
	}

	Node* search(int target) {
		return _search(root, target);
	}

	Node* getRoot() {
		return root;
	}

	void setRoot(Node* root) {
		this->root = root;
	}

	int getSize() {
		return _getSize(root);
	}

	int getHeight(Node* node) {
		if (!node) return 0;
		int left = getHeight(node->left);
		int right = getHeight(node->right);
		return max(left, right) + 1;
	}

	
};

void dfs(Node* node, int level, vector<int>& v) {
	if (node == nullptr) return;
	v[level]+= node->val;
	dfs(node->left, level + 1, v);
	dfs(node->right, level + 1, v);
}

int main() {
	BST tree;
	int n;
	cin >> n;
	for(int i=0; i<n; i++) {
		int x;
		cin >> x;
		tree.insert(x);
	}
	int levels = tree.getHeight(tree.getRoot());
    cout << levels;
	vector<int> v(levels);
	dfs(tree.getRoot(), 0, v);
	
    cout << v.size() << endl;
	for(int i=0; i<v.size(); i++){
		cout << v[i] << " ";
	}
	

	return 0;
}