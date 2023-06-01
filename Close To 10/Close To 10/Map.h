#pragma once
#include"Sprite.h"
#include<vector>

using namespace std;

class Map
{
public:
	//方块像素大小
	static const int BLOCK_SIZE = 192;
	//逻辑宽度
	static const int WIDTH = 5;
	//逻辑高度
	static const int HEIGHT = 5;
	POINT m_p;
	//地图数据
	Sprite data[WIDTH][HEIGHT];
	Map();
	//消除队列
	vector<POINT> queue;
	//消除
	void eliminate();
	//设置当前位置
	void set_position(POINT p);
};