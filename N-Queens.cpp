#include <iostream>
using namespace std;
void printArray(int defArray[][8], int rows, int cols){
	int i,j;
	for(i=0;i<rows;i++){
		for(j=0;j<cols;j++){
			cout << defArray[i][j] << " ";
		}
		cout << endl;
	}
	return;
}

bool isSafe(int defArray[][8],int row, int col, int rows, int cols){
	int i,j,k,l;
	for(i=col;i>=0;i--){
		if(defArray[row][i]==1){
			return false;
		}
	}
	for(i=row,j=col;i>=0 && j>=0;i--,j--){
		if(defArray[i][j]==1){
			return false;
		}
	}
	for(i=row,j=col;i<=8 && j>=0;i++,j--){
		if(defArray[i][j]==1){
			return false;
		}
	}
	
	return true;
	
}

bool NQueens(int defArray[][8],int col, int rows, int cols){
	if(col>=8){
		return true;
	}
	int i;
	for(i=0;i<rows;i++){
		if(isSafe(defArray,i,col,rows,cols)){
			defArray[i][col]=1;
			if(NQueens(defArray,col+1,rows,cols)){
				return true;
			}
			defArray[i][col]=0;
		}
	}
	return false;
}

int main() {
	// your code goes here
	int defArray[8][8],i,j;
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			defArray[i][j]=0;
		}
	}
	cout << "Printing Array before NQueens" << endl;
	printArray(defArray,8,8);
	NQueens(defArray,0,8,8);
	cout << "Printing Array after NQueens" << endl;
	printArray(defArray,8,8);
	return 0;
}