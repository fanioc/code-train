#include <iostream>
#include "MapAI.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(int argc, char** argv) {
	int mapx[][3] = {
		{5,2,3},
		{6,0,1},
		{4,7,8}
	};

	MapAI map = MapAI((int**)mapx,3);

	map.MapSearch_DPS();
	map.show();
	map.showXY();
	map.move(6);
	map.show();
	map.showXY();
	return 0;
}
