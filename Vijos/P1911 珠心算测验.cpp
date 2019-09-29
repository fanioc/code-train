#include <iostream>
#define MAXSIZE 100

using namespace std;

int main() {
	int n;
	int arr[MAXSIZE];
	int recod[30000];
	int num=0;
	cin>>n;
	for(int i=0; i<n; i++) {
		cin>>arr[i];
		recod[arr[i]]=1;
	}

	for(int j=0; j<n; j++) {
		for(int k=j+1; k<n; k++) {
			if(recod[arr[j]+arr[k]]==1) {
				num++;
				recod[arr[j]+arr[k]]=0;
			}
		}
	}

	cout<<num<< endl;
	
}
