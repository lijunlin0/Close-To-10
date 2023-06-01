#include"Sprite.h"
#include"Map.h"
#include<iostream>
using namespace std;
void Sprite::init(POINT p,int value)
{
	m_position = p;
	m_value = value;
	m_select = false;

	int x = p.x;
	int y = p.y;
	to_plotting(x, y);

	loadimage(&m_img, image_name(m_value));
	putimage(x,y, &m_img);
}

void Sprite::to_plotting(int& x, int& y)
{
	x *= Map::BLOCK_SIZE;
	y *= Map::BLOCK_SIZE;
}

void from_plotting(int& x, int& y)
{
	x /= Map::BLOCK_SIZE;
	y /= Map::BLOCK_SIZE;
}

//ֵ��Ӧ��ͼƬ·��
LPCTSTR Sprite::image_name(int value)
{
	switch (value)
	{
	case 1:cout << "�ɹ�" << endl; return "./images/1.png";
	case 2:return "./images/2.png";
	case 3:return "./images/3.png";
	case 4:return "./images/4.png";
	case 5:return "./images/5.png";
	case 6:return "./images/6.png";
	case 7:return "./images/7.png";
	case 8:return "./images/8.png";
	case 9:return "./images/9.png";
	case 10:return "./images/10.png";
	default:return 0;
	}
}
//����ѡ��״̬
void Sprite::set_select(bool select) 
{
	m_select = select;
}
//�Ƿ�ѡ��
bool Sprite::is_select() 
{
	return m_select;
}

//��ȡͼƬ��ֵ
int Sprite::get_value() 
{
	return m_value; 
}

//�����ǰͼƬ
void Sprite::clear()
{
	int x = m_position.x;
	int y = m_position.y;
	to_plotting(x, y);
	clearrectangle(x, y, x + Map::BLOCK_SIZE, y + Map::BLOCK_SIZE);
}