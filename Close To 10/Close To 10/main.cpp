#include<iostream>
#include<graphics.h>
#include<conio.h>
#include"Map.h"
using namespace std;

int main()
{
	srand((unsigned)time(NULL));//����ϵͳʱ��ı���������
	initgraph(Map::BLOCK_SIZE*Map::WIDTH, Map::BLOCK_SIZE * Map::HEIGHT,SHOWCONSOLE);
	Map m;
	system("pause");
	return 0;
}