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
			int num = rand() % 3 + 1;
			POINT p;
			p.x = i;
			p.y = j;
			data[i][j].init(p,num);
		}
	}
}

//设置当前位置
void Map::set_position(POINT p)
{
	int x = p.x;
	int y = p.y;
	data[0][0].from_plotting(x, y);
	m_p.x = x;
	m_p.y = y;
}

//消除
void Map::eliminate()
{
	//判断点击位置是否为0
	if (data[m_p.x][m_p.y].get_value() == 0)
	{
		return;
	}
	queue.push_back(m_p);
	auto direction = [&](POINT begin,int x, int y)
	{
		POINT next;
		next.x = begin.x + x;
		next.y = begin.y + y;
		//如果不合法则退出
		if (next.x < 0 || next.x >= WIDTH || next.y < 0 || next.y >= HEIGHT|| data[begin.x][begin.y].get_value()==0)
		{
			return;
		}
		if (data[next.x][next.y].get_value() == data[begin.x][begin.y].get_value())
		{
			queue.push_back(next);
		}
	};
	int value = data[m_p.x][m_p.y].get_value();
	int count = 0;
	while (queue.size() != 0)
	{
		POINT begin = queue[0];
		//上
		direction(begin, 0, -1);
		//右
		direction(begin, 1, 0);
		//下
		direction(begin, 0, 1);
		//左
		direction(begin, -1, 0);

		data[begin.x][begin.y].clear();
		queue.erase(queue.begin());
		cout << "合成" << endl;
		count += 1;
	}
	//合
	if (count == 1)
	{
		data[m_p.x][m_p.y].set_value(value);
	}
	else
	{
		data[m_p.x][m_p.y].set_value(value + 1);
	}
	down();
}

void Map::draw()
{
	for (int i = 0; i < WIDTH; i++)
	{
		for (int j = 0; j < HEIGHT; j++)
		{
			data[i][j].draw();
		}
	}
}

void Map::down()
{
	//下落
	for (int i = 0; i < WIDTH; i++)
	{
		for (int j = 0; j < HEIGHT; j++)
		{
			if (data[i][j].get_value() == 0)
			{
				for (int x = j; x > 0; x--)
				{
					data[i][x].set_value(data[i][x - 1].get_value());
				}
			}
		}
	}
	bool is_5 = false;
	//补齐空白
	for (int i = 0; i < WIDTH; i++)
	{
		for (int j = 0; j < HEIGHT; j++)
		{
			if (data[i][j].get_value() == 5)
			{
				is_5 = true;
			}
			if (data[i][j].get_value() == 0)
			{
				if (is_5)
				{
					int num = rand() % 4 + 1;
					data[i][j].set_value(num);
				}
				else
				{
					int num = rand() % 3 + 1;
					data[i][j].set_value(num);
				}

			}
		}
	}
}

void Map::find()
{
	return;
	queue.push_back(m_p);
	auto direction = [&](POINT begin, int x, int y)
	{
		POINT next;
		next.x = begin.x + x;
		next.y = begin.y + y;
		//如果不合法则退出
		if (next.x < 0 || next.x >= WIDTH || next.y < 0 || next.y >= HEIGHT || data[begin.x][begin.y].get_value() == 0)
		{
			return;
		}
		if (data[next.x][next.y].get_value() == data[begin.x][begin.y].get_value())
		{
			queue.push_back(next);
		}
	};
	int value = data[m_p.x][m_p.y].get_value();
	while (queue.size() != 0)
	{
		POINT begin = queue[0];
		//上
		direction(begin, 0, -1);
		//右
		direction(begin, 1, 0);
		//下
		direction(begin, 0, 1);
		//左
		direction(begin, -1, 0);
		//设置为已查询
		data[begin.x][begin.y].set_value(value+100);
		data[begin.x][begin.y].highlight();
		mark.push_back(begin);
		queue.erase(queue.begin());
	}
	for (int i = 0; i < mark.size(); i++)
	{
		data[mark[i].x][mark[i].y].set_value(value);
	}
}
