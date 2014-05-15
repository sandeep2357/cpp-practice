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

bool identicalTree(struct node *node1, struct node *node2){
	if(node1 == NULL && node2 == NULL){
		return true;
	}
	if(node1!=NULL && node2!=NULL){
		return node1->data==node2->data && identicalTree(node1->left,node2->left) && identicalTree(node1->right,node2->right);
	}
	return false;
}

int main() {
	struct node *root1 = newNode(1);
	root1->left = newNode(2);
	root1->right = newNode(3);
	
	root1->left->left = newNode(4);
	root1->left->right = newNode(5);
	
	struct node *root2 = newNode(1);
	root2->left = newNode(2);
	root2->right = newNode(3);
	
	root2->left->left = newNode(4);
	root2->left->right = newNode(5);
	
	if(identicalTree(root1,root2)){
		cout << " The given trees are identical" << endl;
	}else{
		cout << " The given trees are not identical " << endl;
	}
	// your code goes here
	return 0;
}