#include <iostream>

typedef struct Tree {
	int val;
	struct Tree* left;
	struct Tree* right;
}Tree;

Tree* insert(Tree* root, int val) {
	if (!root) {
		root = new Tree();
		root->val = val;
		root->left = root->right = NULL;
		return root;
	}
	else {
		if (val > root->val)
			root->right = insert(root->right, val);
		else
			root->left = insert(root->left, val);
	}
	return root;
}

void postfix(Tree* root) {
	if (root) {
		postfix(root->left);
		postfix(root->right);
		printf("%d\n", root->val);
	}
}
int main()
{
	Tree* root = NULL;
	int a;
	while (scanf("%d", &a) == 1)
	{
		root = insert(root, a);
	}
	postfix(root);
}
