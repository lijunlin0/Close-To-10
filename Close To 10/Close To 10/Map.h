#include"Sprite.h"

class Map
{
public:
	//方块像素大小
	static const int BLOCK_SIZE = 192;
	//逻辑宽度
	static const int WIDTH = 5;
	//逻辑高度
	static const int HEIGHT = 5;
	//地图数据
	Sprite data[WIDTH][HEIGHT];
	Map();
};