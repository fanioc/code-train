#ifndef CIRCLE_H
#define CIRCLE_H
  

class MapAI {
	public:
		int n;
		int **Martix;
		MapAI(int **Martix,int n);

		int getValue (int i,int j);
		void setValue (int i,int j,int value);
		bool move(int v);
		bool move(int i,int j);
		void show();//输出显示矩阵
		void showXY();//输出显示矩阵

		int* MapSearch_DPS();//深度优先搜索
		int* MapSearch_BPS();//广度优先搜索
		int* MapSearch_A();//A*算法搜索
	private:
		int XY[1000][2];//存储值的坐标
};

#endif

