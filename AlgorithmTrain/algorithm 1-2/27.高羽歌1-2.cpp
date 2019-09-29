#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 1000

int encode(char str[]) {
	int code = 0;
	int length = 0;
	int i = 0;

	while(str[i]!='\0')
		i++;
	length = i;
	printf("length:%d\t",length);

	for(i=1; i<=length; i++) { //�Ӹ�λ����λ���� 
		if (str[length-i]-96 > 26 || str[length-i]-96 < 1) //�ж��ַ��Ƿ�����a-z
			return 0;
		if (i==1)
			code += (str[length-i]-96);
		else
			code += (str[length-i]-96)*('a'-str[length-i+1]+27); //��λ���� 
	}
	
	return code;
}

int main() {

	FILE* fp;
	char ch;
	int num;
	char str[MAXSIZE][6];
	int result[MAXSIZE];

	// read file input.txt
	if ((fp = fopen("input.txt", "rt")) == NULL) {
		printf("\nCannot open file strike any key exit!");
		getchar();
		exit(1);
	}
	fscanf(fp,"%d",&num);
	for (int i=0; i<num; i++) {
		fscanf(fp,"%s",str[i]);
		result[i] = encode(str[i]); //���ñ����㷨
		printf("%s\t ====>>      %d\n",str[i],result[i]); //�������
	}
	fclose(fp);


	// write file output.txt
	if ((fp = fopen("output.txt", "w+")) == NULL) {
		printf("\nCannot open file strike any key exit!");
		getchar();
		exit(1);
	}
	for (int i=0; i<num; i++) {
		fprintf(fp,"%d\n",result[i]);//������
	}
	fclose(fp);

	printf("### ��� output.txt �ɹ���");
}


