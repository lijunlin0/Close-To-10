#include"Map.h"
#include<graphics.h>
#include<iostream>
using namespace std;
Map::Map()
{
	for (int i = 0; i < WIDTH; i++)
	{
		for (int j = 0; j < HEIGHT; j++)
		{
			int num = rand() % 10 + 1;
			POINT p;
			p.x = i;
			p.y = j;
			cout << p.x << " " << p.y << endl;
			data[i][j].init(p,num);
		}
	}
}

