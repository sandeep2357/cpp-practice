#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

void swap(char *a, char *b){
	char *temp;
	*temp=*a;
	*a=*b;
	*b=*temp;
}

void permutation(string str,int i, int n){
	int j;
	if(i==n){
		cout << str << endl;
	}

	for(j=i;j<n;j++){
		swap(str[i],str[j]);
		permutation(str,i+1,n);
		swap(str[i],str[j]);
	}
}

int main() {
	// your code goes here
	string str;
	cin >> str;
	int len = str.length();
	permutation(str,0,len);
	//cout << str << endl;
	return 0;
}