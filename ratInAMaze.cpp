#include <iostream>
using namespace std;

void printMaze(int sol[][4]){
	int i,j;
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			cout << sol[i][j] << " ";
		}
		cout << endl;
	}
}

bool isSafe(int maze[][4],int x,int y){
	if(maze[x][y]!=0){
		return true;
	}
	return false;
}

bool solveMaze(int maze[][4],int x,int y, int sol[][4]){
	if(x==4 && y==4){
		return true;
	}
	int i;
	for(i=0;i<4;i++){
		if(isSafe(maze,x,y)){
			sol[x][y]=1;
			if(solveMaze(maze,x+1,y,sol)){
				return true;
			}
			if(solveMaze(maze,x,y+1,sol)){
				return true;
			}
			sol[x][y]=0;
		}
	}
	return false;
}

int main() {
	// your code goes here
	int maze[4][4]={{1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}};
    int sol[4][4]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    printMaze(sol);
    solveMaze(maze,0,0,sol);
    printMaze(sol);
	return 0;
}