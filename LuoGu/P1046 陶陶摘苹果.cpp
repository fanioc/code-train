//P1046 陶陶摘苹果
#include<iostream>
using namespace std;

int main () {
	int a[10],i,m,n;
	for(i=0;i<10;i++)
		cin>>a[i];
	cin>>m;
	for(i=0,n=0;i<10;i++){
		if(a[i]<=m+30)
			n++;
	}
	cout<<n;
}
