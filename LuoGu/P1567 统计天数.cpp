//P1567 统计天数
#include<iostream>
using namespace std;

int main() {
	long long day;
	long long N[2];
	int max[2];
	int i;

	cin>>day;

	for(i=0; i<day; i++) {
		cin>>N[i%2];
		if(i>=1) {
			if(N[i%2]<N[(i+1)%2]) {
				//下降
				max[0] = max[0]>max[1]?max[0]:max[1];
				max[1] = 1;
			} else {
				//上升
				max[1]++;
			}
		} else {
			max[0]=1;
			max[1]=1;
		}
	}
	
	cout<<max[0];


}
