#include <iostream>
#include <cstdlib>
using namespace std;

void printSet(int set[], int n){
	int i;
	for(i=0;i<n;i++){
		cout << set[i] << " ";
	}
	cout << endl;
}

bool tupCheck(int elem, int tuplet[], int tupSize){
	int i;
	for(i=0;i<=tupSize;i++){
		if(tuplet[i]==elem){
			return false;
		}
	}
	return true;
}

void subsetSum(int set[], int setSize, int ite, int sum, int tuplet[], int tupSize, int sumFar){
	int i;
	//printSet(tuplet,tupSize);
	if(sumFar==sum){
		cout << "Solution is : ";
		printSet(tuplet,tupSize);
		if(ite+1 < setSize && sumFar-set[ite]+set[ite+1]<=sum){
			subsetSum(set,setSize,ite+1,sum,tuplet,tupSize-1,sumFar);
		}
	}
	else{
	for(i=ite;i<setSize;i++){
		tuplet[tupSize]=set[i];
		if(sumFar+set[i]<=sum){
			subsetSum(set,setSize,i+1,sum,tuplet,tupSize+1,sumFar+set[i]);
		}	
	}
	}
}

int main() {
	// your code goes here
	int initSet[4]={1,2,3,4};
	int sum = 7;
	int *tuplet,tupSize=0,sumFar=0;
	tuplet= (int *)malloc(4*sizeof(int));
	printSet(initSet,4);
	subsetSum(initSet,4,0,sum,tuplet,tupSize,sumFar);
	return 0;
}