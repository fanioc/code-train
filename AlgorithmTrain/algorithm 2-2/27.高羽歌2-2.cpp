#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <queue>
#include <vector>
using namespace std;
 
typedef struct
{
    int x;
    int y;
} Step;

typedef struct Point
{
    int x;
    int y;
};

int N,M;//棋盘大小 

//马可以走的方向 dx[i] dy[i] 
Step step[8] = { {-2, -1}, {-1, -2}, { 1, -2}, { 2, -1}, { 2, 1}, { 1, 2}, {-1, 2}, {-2,1} };

Point point[10000];
 
//记录下一个节点的数据 
typedef struct NextPos
{
    int nextPosSteps; //表示下一位置有多少种走法；走法少的优先考虑
    int nextPosDirection; //下一位置相对于当前位置的方位
    int nextPosToMidLength; //表示当前位置距中间点距离；距离中间点远的优先考虑
 
    //
    bool operator < (const NextPos &a) const
    {
        return nextPosSteps > a.nextPosSteps && nextPosToMidLength < a.nextPosToMidLength;
    }
 
};
 
//记录节点的步数 
int board[100][100];
 
 
//检测这个位置是否可以走
bool check(int x, int y)
{
    if (x >= 0 && x < M && y >= 0 && y < N && board[x][y] == 0)
        return true;
    return false;
}

//下一位置有多少种走法
int nextPosHasSteps(int x, int y)
{
    int steps = 0;
    for (int i = 0; i < 8; ++i)
    {
        if (check(x + step[i].x, y + step[i].y))
            steps++;
    }
    return steps;
}

//判断是否回到起点
bool returnStart(int x, int y)
{
    //校验最后是否可以回到起点，也就是棋盘的中间位置
    int midx,midy;
    midx = M / 2 - 1;
    midy = N / 2 - 1;
    for (int i = 0; i < 8; ++i)
        if (x + step[i].x == midx && y + step[i].y == midy)
            return true;
    return false;
}
 
//输出结果
void outputResult(int xstart,int ystart)
{
	int num = M * N;
    int k = num - board[xstart][ystart];
    
    for (int i = 0; i < M; ++i)
    {
        printf("\n");
        for (int j = 0; j < N; ++j)
        {
            board[i][j] = (board[i][j] + k) % num + 1;
            printf("%5d",board[i][j]);
            
        	Point xxx = {j,i};
            point[board[i][j]]=xxx;

        }
    }
    printf("\n\n");
    
    for(int i = 1; i<=num ;i++)
    	printf("(%d,%d)\t",point[i].x,point[i].y);
    printf("\n\n");
    
    
    FILE* fp;
	// write file output.txt
	if ((fp = fopen("output.txt", "w+")) == NULL) {
		printf("\nCannot open file strike any key exit!");
		getchar();
		exit(1);
	}
    
    
    //输出结果
    for(int i = 1; i<=num ;i++)
    	fprintf(fp,"(%d,%d)\t",point[i].x,point[i].y);
    	
    fprintf(fp,"\n");
    for (int i = 0; i < M; ++i)
    {
        fprintf(fp,"\n");
        for (int j = 0; j < N; ++j)
        {
            fprintf(fp,"%5d",board[i][j]);

        }
    }
//    fprintf(fp,"\n");
	
	printf("### 输出 output.txt 成功。");

	fclose(fp);

	
}
 
//某一位置距离棋盘中心的距离
int posToMidLength(int x,int y)
{
    int midx = M / 2 - 1;
    int midy = N / 2 - 1;
    return (abs(x - midx) + abs(y - midy));
}
 
void BackTrace(int t, int x, int y,int xstart,int ystart)
{
    //找到结果
    if (t == M * N && returnStart(x,y)) //遍历了棋盘的所以位置，并且最后可以回到起点，形成回路
    {
        outputResult(xstart,ystart);
        exit(1);
    }
    else
    {
        priority_queue<NextPos> nextPosQueue;
        for (int i = 0; i < 8; ++i)
        {
            if (check(x + step[i].x, y + step[i].y))
            {
                NextPos aNextPos;
                aNextPos.nextPosSteps = nextPosHasSteps(x + step[i].x, y + step[i].y);
                aNextPos.nextPosDirection = i;
                aNextPos.nextPosToMidLength = posToMidLength(x + step[i].x,y + step[i].y);
                nextPosQueue.push(aNextPos);
                
            }else {
//            	point.pop_back();
			}
        }
 
        while(nextPosQueue.size())
        {
            int d = nextPosQueue.top().nextPosDirection;
            nextPosQueue.pop();
            
            x += step[d].x;
            y += step[d].y;
            board[x][y] = t + 1;
			
            BackTrace(t + 1, x, y,xstart,ystart);
            //回溯
            board[x][y] = 0;
            x -= step[d].x;
            y -= step[d].y;
        }
    }
}
 
 
void horseRun(int xstart,int ystart)
{
    //初始化棋盘
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = 0;
    int midx = M / 2 -1;
    int midy = N / 2 -1;
    board[midx][midy] = 1; //从棋盘的中间的位置开始马周游
    BackTrace(1, midx, midy,xstart,ystart);
}


//储存一次6*6的数据矩阵
//
//    1   12   29   10    3   18
//
//   28    7    2   19   -30    9
//
//   13   36   11    8   17    4
//
//   24   27    6   33   20   -31
//
//   35   14   25   22    5   16
//
//   26   23   34   15   32   21

//储存一次8*8的数据矩阵
//    1   14   17   36   27   24   19   22
//
//   16   37   64   47   18   21   -28   25
//
//   13    2   15   56   35   26   23   20
//
//   38   55   48   63   46   61   34   -29
//
//    3   12   39   54   57   30   45   52
//
//   40    9    6   49   62   53   60   33
//
//    7    4   11   42   31   58   51   44
//
//   10   41    8    5   50   43   32   59

//储存一次6*8的数据矩阵
//    1    6   25   -38   47   10   19   36
//
//   26   -39   48    7   18   37   -46    9
//
//    -5    2   17   24   11    8   35   20
//
//   30   27   40    3   16   23   12   -45
//
//   41    -4   29   32   43   14   -21   34
//
//   28   31   42   15  -22   33   44   13

//储存一次8*6的数据矩阵
//    1   30   21   16   47   14
//
//   20   -33   48   13   -22   17
//
//   31    2   29   18   15   46
//
//   -34   19   32   27   12   -23
//
//    -3   28   11   24   45   -26
//
//   10   35    8    5   42   39
//
//    7    -4   37   40   -25   44
//
//   36    9    6   43   38   41

//可以看出 每个角都有 一组循环节点 

////马可以走的方向 dx[i] dy[i] 
//int dx[8]={-2,-1,1,2,-2,-1,2,1};
//int dy[8]={-1,-2,-2,-1,1,2,1,2};
//
////记录马走过的位置  值为步数 
//int xy[MAXSIZE][MAXSIZE];
//
//
////利用分治思想 划分棋盘为 6*6，6*8，8*8 , 8*6 三种矩阵 
////利用divide()函数划分棋盘 
//void divide(){
//	
//}
//
////分块棋盘运算
////起始XY可以为(0,0),(1,2)
//int stepRun(int n,int m,int statrX,int startY,int stepNum){
//	
//}



int main() {
	FILE* fp;
	
	
	
	// read file input.txt
	if ((fp = fopen("input.txt", "rt")) == NULL) {
		printf("\nCannot open file strike any key exit!");
		getchar();
		exit(1);
	}
	fscanf(fp,"%d %d",&N,&M);
	fclose(fp);

	horseRun(0,0);
	
}


