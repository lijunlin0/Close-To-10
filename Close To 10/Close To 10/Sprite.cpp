#include"Sprite.h"
#include"Map.h"
#include<iostream>
using namespace std;
void Sprite::init(POINT p,int value)
{
	m_value = value;
	m_select = false;

	int x = p.x;
	int y = p.y;
	to_plotting(x, y);
	m_position.x = x;
	m_position.y = y;
}

void Sprite::draw()
{
	loadimage(&m_img, image_name(m_value));
	putimage(m_position.x, m_position.y, &m_img);
}

void Sprite::to_plotting(int& x, int& y)
{
	x *= Map::BLOCK_SIZE;
	y *= Map::BLOCK_SIZE;
}

void Sprite::from_plotting(int& x, int& y)
{
	x /= Map::BLOCK_SIZE;
	y /= Map::BLOCK_SIZE;
}

//值对应的图片路径
LPCTSTR Sprite::image_name(int value)
{
	switch (value)
	{
	case 0:return "./images/0.png";
	case 1:return "./images/1.png";
	case 2:return "./images/2.png";
	case 3:return "./images/3.png";
	case 4:return "./images/4.png";
	case 5:return "./images/5.png";
	case 6:return "./images/6.png";
	case 7:return "./images/7.png";
	case 8:return "./images/8.png";
	case 9:return "./images/9.png";
	case 10:return "./images/10.png";
	case 101:return "./images/1.png";
	case 102:return "./images/2.png";
	case 103:return "./images/3.png";
	case 104:return "./images/4.png";
	case 105:return "./images/5.png";
	case 106:return "./images/6.png";
	case 107:return "./images/7.png";
	case 108:return "./images/8.png";
	case 109:return "./images/9.png";
	default:return 0;
	}
}
//设置选择状态
void Sprite::set_select(bool select) 
{
	m_select = select;
}
//是否被选择
bool Sprite::is_select() 
{
	return m_select;
}

//获取图片的值
int Sprite::get_value() 
{
	return m_value; 
}

void Sprite::set_value(int value)
{
	m_value = value;
}

//清除当前图片
void Sprite::clear()
{
	m_value = 0;
}

//高亮图片
void Sprite::highlight()
{
	POINT p = m_position;
	line(p.x, p.y, p.x + Map::WIDTH * Map::BLOCK_SIZE, p.y);
	line(p.x + Map::WIDTH * Map::BLOCK_SIZE, p.y, p.x + Map::WIDTH * Map::BLOCK_SIZE, p.y + Map::HEIGHT * Map::BLOCK_SIZE);
	line(p.x + Map::WIDTH * Map::BLOCK_SIZE, p.y + Map::HEIGHT * Map::BLOCK_SIZE, p.x, p.y + Map::HEIGHT * Map::BLOCK_SIZE);
	line(p.x, p.y + Map::HEIGHT * Map::BLOCK_SIZE, p.x, p.y);
}