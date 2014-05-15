#include <iostream>
using namespace std;

void printBoard(int board[][8], int rows, int cols){
	int i,j;
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	return;
}

bool isSafe(int board[][8], int x, int y){
	if(x>=0 && x<8 && y>=0 && y<8 && board[x][y]==-1){
		return true;
	}
	return false;
}

bool knightsTour(int board[][8],int x, int y, int move, int xOffset[8], int yOffset[8]){
	if(move>64){
		return true;
	}
	int i,newX,newY;
	for(i=0;i<8;i++){
		newX = x + xOffset[i];
		newY = y + yOffset[i];
		if(isSafe(board,newX,newY)){
			board[newX][newY]=move;
			if(knightsTour(board,newX,newY,move+1,xOffset,yOffset)){
				return true;
			}
			board[newX][newY]=-1;
		}
	}
	return false;
}

int main() {
	// your code goes here
	int board[8][8];
	int i,j;
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			board[i][j]=-1;
		}
	}
	int xOffset[8]={2, 1, -1, -2, -2, -1,  1,  2};
	int yOffset[8]={1, 2,  2,  1, -1, -2, -2, -1};
	printBoard(board,8,8);
	board[0][0]=1;
	knightsTour(board,0,0,2,xOffset,yOffset);
	printBoard(board,8,8);
	return 0;
}