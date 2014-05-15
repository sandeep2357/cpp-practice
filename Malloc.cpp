#include <iostream>
#include <cstdlib>
using namespace std;

void printArray(int **defArray,int rows,int cols){
	int i,j;
	for(i=0;i<rows;i++){
		for(j=0;j<cols;j++){
			//cout << *(defArray+rows*i+j) << " ";
			cout << defArray[i][j] << " ";
		}
		cout << endl;
	}
	return;
}
int main() {
	// your code goes here
	int **defArray;
	int i,j;
	defArray = (int **)malloc(8*sizeof(int *));
	for(i=0;i<8;i++){
		defArray[i]=(int *)malloc(8*sizeof(int));
	}
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			defArray[i][j]=3;
			//*(defArray+8*i+j)=3;
		}
	}
	printArray(defArray,8,8);
	for(i=0;i<8;i++){
		free(defArray[i]);
	}
	free(defArray);
	return 0;
}