#include"Sprite.h"

class Map
{
public:
	//�������ش�С
	static const int BLOCK_SIZE = 192;
	//�߼����
	static const int WIDTH = 5;
	//�߼��߶�
	static const int HEIGHT = 5;
	//��ͼ����
	Sprite data[WIDTH][HEIGHT];
	Map();
};