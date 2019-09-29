#include <stdio.h>
#include <stdlib.h>

//���ϻ���ʵ������һ��������
//����3��Ԫ�صļ��ϣ��ɻ���Ϊ
//�� 1���Ӽ��ļ��ϣ�{{1��2��3}}
//�� 2���Ӽ��ļ��ϣ�{{1��2}��{3}}��{{1��3}��{2}}��{{2��3}��{1}}
//�� 3���Ӽ��ļ��ϣ�{{1}��{2}��{3}}
//��F(3,1)=1;F(3,2)=3;F(3,3)=1; 
//���÷���˼�뽫 ÿ�μ����ֵ���ۼ����� 
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
	fprintf(fp,"%d\n",sum);//������
	fclose(fp);
	
	printf("%d => %d\n",n,sum);
	printf("### ��� output.txt �ɹ���");
}


