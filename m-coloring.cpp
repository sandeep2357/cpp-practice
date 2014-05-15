#include <iostream>
#include <cstdlib>
using namespace std;

void printSolution(int color[]){
	int i;
	for(i=0;i<4;i++){
		cout << color[i] << " ";
	}
	cout << endl;
	return;
}

bool isSafe(int graph[][4], int c, int color[], int v){
	int i;
	for(i=0;i<4;i++){
		if(graph[i][v]==1 && color[i]==c){
			return false;
		}
	}
	return true;
}

bool graphColoring(int graph[][4], int m, int color[], int vertex){
  if(vertex==4){
  	return true; 
  }
  int i;
  for(i=1;i<=m;i++){
  	if(color[vertex]==0 && isSafe(graph,i,color,vertex)){
  		color[vertex]=i;
  		if(graphColoring(graph,m,color,vertex+1)){
  			return true;
  		}
  		color[vertex]=0;
  	}
  }
  return false;
}

int main() {
	// your code goes here
	int graph[4][4] = {{0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0},
    };
    int m = 3;
    int color[4];
    int i;
    for(i=0;i<4;i++){
    	color[i]=0;
    }
    if(graphColoring(graph,m,color,0)){
    	cout << "Can be Colored" << endl;
    }
    else{
    	cout << "Impossible" << endl;
    }
    printSolution(color);
	return 0;
}