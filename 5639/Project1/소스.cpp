#include <iostream>
#include <string>
using namespace std;

class node {
public:
	int key;
	node* parent;
	node* left;
	node* right;

	node(int key){
		this->key = key;
		parent = left = right = NULL;
	}
	void setLeft(node* child) {
		left = child;
		if (child != NULL)child->parent = this;
	}
	void setRight(node* child) {
		right = child;
		if (child != NULL) child->parent = this;
	}
};
class BST {
public:
	node* root;
	BST() {
		root = NULL;
	}

	void insert(int key) {
		node* newNode = new node(key);
		if (root == NULL) {
			root = newNode;
			return;
		}
		node* parNode = root;
		while (true) {
			if (parNode->key < key) {
				if (parNode->right == NULL) {
					parNode->setRight(newNode);
					break;
				}
				parNode = parNode->right;
			}
			else {
				if (parNode->left == NULL) {
					parNode->setLeft(newNode);
					break;
				}
				parNode = parNode->left;
			}
		}

	}
	void print(node* root) {
		if (root->left != NULL) {
			print(root->left);
		}
		if (root->right != NULL) {
			print(root->right);
		}
		cout << root->key << endl;

	}
};
int main() {
	BST bst;
	int input;
	while (cin >> input) {
		bst.insert(input);
	}
	bst.print(bst.root);
}