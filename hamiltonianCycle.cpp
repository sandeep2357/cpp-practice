#include <iostream>
#include <cstdlib>
using namespace std;

void printCycle(int path[]){
	int i;
	for(i=0;i<5;i++){
		cout << path[i] << " ";
	}
	
	cout << path[0] << endl;
}

bool isSafe(int graph[][5], int path[], int pos, int v){
	int i;
	for(i=0;i<pos;i++){
		if(path[i]==v){
			return false;
		}
	}
	return true;
}

bool hamiltonianCycle(int graph[][5],int path[], int pos){
	if(pos==5){
		if(graph[path[pos-1]][path[0]]==1){
			return true;
		}
		return false;
	}
	int i;
	for(i=0;i<5;i++){
		if(graph[i][path[pos-1]]==1 && isSafe(graph, path,pos,i)){
			path[pos]=i;
			if(hamiltonianCycle(graph,path,pos+1)){
				return true;
			}
			path[pos]=-1;
		}
	}
	return false;
}

int main() {
	// your code goes here
	int graph1[5][5] = {{0, 1, 0, 1, 0},
                      {1, 0, 1, 1, 1},
                      {0, 1, 0, 0, 1},
                      {1, 1, 0, 0, 1},
                      {0, 1, 1, 1, 0},
                     };
    int path1[5]={0,-1,-1,-1,-1};
    hamiltonianCycle(graph1,path1,1);
    printCycle(path1);
    
    int graph2[5][5] = {{0, 1, 0, 1, 0},
                      {1, 0, 1, 1, 1},
                      {0, 1, 0, 0, 1},
                      {1, 1, 0, 0, 0},
                      {0, 1, 1, 0, 0},
                     };
    int path2[5]={0,-1,-1,-1,-1};
    hamiltonianCycle(graph2,path2,1);
    printCycle(path2);
	return 0;
}