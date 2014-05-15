#include <iostream>
using namespace std;
//int row=0,col=0;
void printBoard(int Board[][9]){
	int i,j;
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			cout << Board[i][j] << " ";
		}
		cout << endl;
	}
}

bool findUnassignedLocation(int Board[][9], int &row, int &col){
	int i,j;
	for(row=0;row<9;row++){
		for(col=0;col<9;col++){
			if(Board[row][col]==0){
				return true;
			}
		}
	}
	return false;
}

bool usedInRow(int Board[][9],int num, int r){
	int i;
	for(i=0;i<9;i++){
		if(Board[r][i]==num){
			return true;
		}
	}
	return false;
}

bool usedInCol(int Board[][9],int num, int c){
	int i;
	for(i=0;i<9;i++){
		if(Board[i][c]==num){
			return true;
		}
	}
	return false;
}

bool usedInBox(int Board[][9],int num, int rowStart, int colStart){
	int i,j;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(Board[rowStart+i][colStart+j]==num){
				return true;
			}
		}
	}
	return false;
}

bool isSafe(int Board[][9], int num, int r, int c){
	if(usedInRow(Board,num,r) || usedInCol(Board,num,c) || usedInBox(Board,num,r-r%3,c-c%3)){
		return false;
	}
	return true;
}

bool solveSudoku(int Board[][9]){
	int row, col;
	if(!findUnassignedLocation(Board,row,col)){
		return true;
	}
	int i;
	for(i=1;i<=9;i++){
		if(isSafe(Board,i,row,col)){
			Board[row][col]=i;
			if(solveSudoku(Board)){
				return true;
			}
			Board[row][col]=0;
		}
	}
	return false;
}

int main() {

	int initBoard[9][9]={{3, 0, 6, 5, 0, 8, 4, 0, 0},
						{5, 2, 0, 0, 0, 0, 0, 0, 0},
						{0, 8, 7, 0, 0, 0, 0, 3, 1},
						{0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};
	cout << "Initial Board" << endl;
	printBoard(initBoard);
	solveSudoku(initBoard);
	cout << "After Solving" << endl;
	printBoard(initBoard);
	// your code goes here
	return 0;
}