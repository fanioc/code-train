#include <stdio.h>
#include <stdlib.h>

//集合划分实际上是一个贝尔数
//考虑3个元素的集合，可划分为
//① 1个子集的集合：{{1，2，3}}
//② 2个子集的集合：{{1，2}，{3}}，{{1，3}，{2}}，{{2，3}，{1}}
//③ 3个子集的集合：{{1}，{2}，{3}}
//∴F(3,1)=1;F(3,2)=3;F(3,3)=1; 
//利用分治思想将 每次计算的值都累加起来 
long long diverSet(long long m,long long n) {
	if(m==1)
		return 1;
	if(m==n)
		return 1;
	else
		return diverSet(m-1,n-1)+diverSet(m,n-1)*m;
}

int main() {

	FILE* fp;
	char ch;
	int n;

	// read file input.txt
	if ((fp = fopen("input.txt", "rt")) == NULL) {
		printf("\nCannot open file strike any key exit!");
		getchar();
		exit(1);
	}
	fscanf(fp,"%d",&n);
	fclose(fp);


	// write file output.txt
	if ((fp = fopen("output.txt", "w+")) == NULL) {
		printf("\nCannot open file strike any key exit!");
		getchar();
		exit(1);
	}

	long long sum = 0;
	for(int i=1; i<=n; i++)
		sum+=diverSet(i,n);
	fprintf(fp,"%d\n",sum);//输出结果
	fclose(fp);
	
	printf("%d => %d\n",n,sum);
	printf("### 输出 output.txt 成功。");
}


