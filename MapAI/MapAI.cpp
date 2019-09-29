#include<stdio.h>
#include"MapAI.h"

bool MapAI::move(int v) {
	if(v>=n*n||v<=0)
		return false;
	printf("value:%d ,i:%d,j:%d\n",v,XY[v][0],XY[v][1]);
	printf("value:%d ,i:%d,j:%d\n",0,XY[0][0],XY[0][1]);
	if(XY[v][1]==XY[0][1]&&XY[v][0]-1==XY[0][0]) { //上方
		printf("move:%d 上移\n",v);
	} else if(XY[v][1]==XY[0][1]&&XY[v][0]+1==XY[0][0]) { //下方
		printf("move:%d 下移\n",v);
	} else if(XY[v][0]==XY[0][0]&&XY[v][1]-1==XY[0][1]) { //左方
		printf("move:%d 左移\n",v);
	} else if(XY[v][0]==XY[0][0]&&XY[v][1]+1==XY[0][1]) { //右方
		printf("move:%d 右移\n",v);
	} else return false;

	//swap 0 <-> v
	//swap value
	setValue(XY[v][0],XY[v][1],0);
	setValue(XY[0][0],XY[0][1],v);

	//swap XY
	int tempXY[2] = {XY[v][0],XY[v][1]};
	XY[v][0] = XY[0][0];
	XY[v][1] = XY[0][1];
	XY[0][0] = tempXY[0];
	XY[0][1] = tempXY[1];
	return true;
}

bool MapAI::move(int i,int j) {
	if(i>n||j>n||i<0||j<0)
		return false;

	int tempV = Martix[i][j];

	if(j==XY[0][1]&&i-1==XY[0][0]) { //上方
		printf("move:%d 上移\n",tempV);
	} else if(j==XY[0][1]&&i+1==XY[0][0]) { //下方
		printf("move:%d 下移\n",tempV);
	} else if(i==XY[0][0]&&j-1==XY[0][1]) { //左方
		printf("move:%d 左移\n",tempV);
	} else if(i==XY[0][0]&&j+1==XY[0][1]) { //右方
		printf("move:%d 右移\n",tempV);
	} else return false;

	//swap 0 <-> v
	//swap value
	setValue(i,j,0);
	setValue(XY[0][0],XY[0][1],tempV);

	//swap XY
	XY[tempV][0] = XY[0][0];
	XY[tempV][1] = XY[0][1];
	XY[0][0] = i;
	XY[0][1] = j;
	return true;

}

MapAI::MapAI(int **Martix,int n) {
	this->Martix = Martix;
	this->n = n;

	int value;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			value = getValue(i,j);
			printf("i:%d,j:%d,value:%d\n",i,j,value);
			XY[value][0]=i;
			XY[value][1]=j;
		}
	}
}

void MapAI::show() {
	int value;
	printf("#####################\n");
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			value = getValue(i,j);
			printf("%3d",value);
		}
		printf("\n");
	}
	printf("#####################\n");
}

void MapAI::showXY() {
	int value;
	printf("#####################\n");
	for(int i=0; i<=n*n-1; i++) 
		printf("value:%d ==> i:%d,j:%d\n",i,XY[i][0],XY[i][1]);
	printf("#####################\n");
}

int MapAI::getValue(int i,int j) {
	return *((int*)Martix+j+i*n);
}

void MapAI::setValue (int i,int j,int value) {
	*((int*)Martix+j+i*n) = value;
}


typedef struct NodeP{
	int XY[1000][2];
	int num;
	NodeP *top;
	NodeP *bottom;
	NodeP *left;
	NodeP *right;
};


int* MapAI::MapSearch_DPS() {
	int i,j = 0;
	
}

int* MapAI::MapSearch_BPS() {

}

int* MapAI::MapSearch_A() {

}
