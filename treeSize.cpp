#include <iostream>
#include <cstdlib>
using namespace std;

struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node* newNode(int data){
	struct node *Node = (struct node *)malloc(sizeof(struct node));
	Node->data = data;
	Node->left = NULL;
	Node->right = NULL;
	
	return Node;
}

int treeSize(struct node *node){
	if(node==NULL){
		return 0;
	}
	return treeSize(node->left)+1+treeSize(node->right);
}

int main() {
	
	struct node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	
	cout << "Size of tree is : "<< treeSize(root) << endl;
	// your code goes here
	return 0;
}