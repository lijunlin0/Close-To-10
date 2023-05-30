#include<iostream>
#include<graphics.h>
#include<conio.h>
#include"Map.h"
using namespace std;

int main()
{
	srand((unsigned)time(NULL));//根据系统时间改变的随机种子
	initgraph(Map::BLOCK_SIZE*Map::WIDTH, Map::BLOCK_SIZE * Map::HEIGHT,SHOWCONSOLE);
	Map m;
	system("pause");
	return 0;
}