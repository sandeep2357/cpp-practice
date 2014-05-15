#include <iostream>
#include <cstdlib>
using namespace std;

struct node{
	int data;
	struct node *left;
	struct node *right;
};

void printPath(int path[], int pathLen){
	int i;
	for(i=0;i<pathLen;i++){
		cout << path[i] << " ";
	}
	cout << endl;
	return;
}

struct node* newNode(int data){
	struct node *Node;
	Node = (struct node *)malloc(sizeof(struct node));
	Node->data=data;
	Node->left=NULL;
	Node->right=NULL;
	 
	return Node;
}

void traversePaths(struct node *node, int path[], int pathLen){
	if(node==NULL){
		return;
	}
	path[pathLen]=node->data;
	pathLen++;
	
	if(node->left==NULL && node->right==NULL){
		printPath(path,pathLen);
	}else{
		traversePaths(node->left,path,pathLen);
		traversePaths(node->right, path, pathLen);
	}
}

int main() {
	struct node *root=newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	 
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	
	int path[100];
	int pathLen=0;
	traversePaths(root,path,pathLen);
	
	// your code goes here
	return 0;
}