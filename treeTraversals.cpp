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

void inOrder(struct node *node){
	if(node==NULL){
		return;
	}
	
	inOrder(node->left);
	cout << node->data << " ";
	inOrder(node->right);
}

void postOrder(struct node *node){
	if(node==NULL){
		return;
	}
	
	postOrder(node->left);
	postOrder(node->right);
	cout << node->data << " ";
}

void preOrder(struct node *node){
	if(node==NULL){
		return;
	}
	
	cout << node->data << " ";
	preOrder(node->left);
	preOrder(node->right);
}

int main() {
	struct node *root=newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	
	inOrder(root);
	cout << endl;
	postOrder(root);
	cout << endl;
	preOrder(root);
	cout << endl;
	// your code goes here
	return 0;
}