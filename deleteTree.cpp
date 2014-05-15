#include <iostream>
#include <cstdlib>
using namespace std;

struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node* newNode(int data){
	struct node *Node;
	Node = (struct node *)malloc(sizeof(struct node));
	Node->data=data;
	Node->left=NULL;
	Node->right=NULL;
	
	return Node;
}

void deleteTree(struct node *node){
	if(node==NULL){
		return;
	}
	deleteTree(node->left);
	deleteTree(node->right);
	
	cout << " deleting node :" << node->data << endl;
	free(node);
}

int main() {
	
	struct node *root=newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	
	deleteTree(root);
	root=NULL;
	/* the delete tree function totally wont delete the tree. 
		It wont assign NULL to root. For this we have to have 
		other driver funtion which takes address of root and calls 
		deleteTree and assigns NULL later.*/
	return 0;
}