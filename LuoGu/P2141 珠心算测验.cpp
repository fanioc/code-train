//P2141 жщаФЫуВтбщ
#include<iostream>
using namespace std;

int main() {
	int m,n,a[100],i,j;
	int H[30000];
	cin>>m;
	for(i=0; i<m; i++) {
		cin>>a[i];
		H[a[i]]=1;
	}

	for(i=0,n=0; i<m; i++)
		for(j=i+1; j<m; j++){
			if(H[a[i]+a[j]] == 1) {
				H[a[i]+a[j]]=0;
				n++;
			}
		}
	
	cout<<n;
}
