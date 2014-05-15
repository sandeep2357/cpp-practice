#include <iostream>
#include <cstdlib>
using namespace std;

struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node *lowestCommonAncestor(struct node *node, int n1, int n2){
	if(node==NULL){
		return NULL;
	}
	//cout << node->data << endl;
	if(node->data>n1 && node->data>n2){
		return lowestCommonAncestor(node->left,n1,n2);
	}
	if(node->data<n1 && node->data<n2){
		return lowestCommonAncestor(node->right,n1,n2);
	}
	return node;
}

struct node* newNode(int data){
	struct node *Node = (struct node *)malloc(sizeof(struct node));
	Node->data = data;
	Node->left = NULL;
	Node->right = NULL;
	
	return Node;
}

int main() {
	// Constructing a BST;
	struct node *root        = newNode(20);
	root->left               = newNode(8);
    root->right              = newNode(22);
    root->left->left         = newNode(4);
    root->left->right        = newNode(12);
    root->left->right->left  = newNode(10);
    root->left->right->right = newNode(14);
    
    int n1 = 8, n2 = 14;
    struct node *ans = lowestCommonAncestor(root, n1, n2);
    cout << ans->data << endl;
	// your code goes here
	return 0;
}