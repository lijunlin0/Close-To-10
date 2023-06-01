#pragma once
#include"Sprite.h"
#include<vector>

using namespace std;

class Map
{
public:
	//�������ش�С
	static const int BLOCK_SIZE = 192;
	//�߼����
	static const int WIDTH = 5;
	//�߼��߶�
	static const int HEIGHT = 5;
	POINT m_p;
	//��ͼ����
	Sprite data[WIDTH][HEIGHT];
	Map();
	//��������
	vector<POINT> queue;
	//����
	void eliminate();
	//���õ�ǰλ��
	void set_position(POINT p);
};