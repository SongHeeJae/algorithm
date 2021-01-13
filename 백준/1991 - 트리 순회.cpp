#include <iostream>
using namespace std;

typedef struct Node {
	char val;
	struct Node* left;
	struct Node* right;
}Node;

Node* getNewNode(char val) {
	if (val == '.') return NULL;
	Node* temp = new Node;
	temp->val = val;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

Node* searchNode(Node* root, char val) {
	if (root) {
		if (root->val == val) return root;
		else {
			Node* temp = searchNode(root->left, val);
			if (temp) return temp;
			return searchNode(root->right, val);
		}
	}
	else return NULL;
}

void insertNode(Node* temp, char b, char c) {
	temp->left = getNewNode(b);
	temp->right = getNewNode(c);
}

void postorder(Node* root) {
	if (root) {
		postorder(root->left);
		postorder(root->right);
		cout << root->val;
	}
}

void preorder(Node* root) {
	if (root) {
		cout << root->val;
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(Node* root) {
	if (root) {
		inorder(root->left);
		cout << root->val;
		inorder(root->right);
	}
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	char a, b, c;
	Node* root = getNewNode('A');
	
	cin >> n;
	while (n--) {
		cin >> a >> b >> c;
		Node* temp = searchNode(root, a);
		insertNode(temp, b, c);
	}
	preorder(root);
	cout << "\n";
	inorder(root);
	cout << "\n";
	postorder(root);
	cout << "\n";
}