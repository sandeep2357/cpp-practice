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

void mirror(struct node *node){
	if(node == NULL){
		return;
	}
	mirror(node->left);
	mirror(node->right);
	struct node *temp;
	temp=node->left;
	node->left=node->right;
	node->right= temp;
}

void inorderTree(struct node *node){
	if(node==NULL){
		return;
	}
	inorderTree(node->left);
	cout << node->data << " ";
	inorderTree(node->right);
}

int main() {
	struct node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
 
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	
	cout << "Before Mirroring" << endl;
	inorderTree(root);
	cout << endl;
	mirror(root);
	
	cout << "After Mirroring" << endl;
	inorderTree(root);
	cout << endl;
	// your code goes here
	return 0;
}