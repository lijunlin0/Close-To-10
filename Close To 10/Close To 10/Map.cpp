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

//���õ�ǰλ��
void Map::set_position(POINT p)
{
	m_p = p;
}

//����
void Map::eliminate()
{
	queue.push_back(m_p);
	auto direction = [&](POINT begin,int x, int y)
	{
		POINT next;
		next.x = begin.x + x;
		next.y = begin.y + y;
		if (data[next.x][next.y].get_value() == data[m_p.x][m_p.y].get_value())
		{
			queue.push_back(next);
		}
	};
	while (queue.size() != 0)
	{
		int x = m_p.x, y = m_p.y;
		data[x][y].from_plotting(x, y);
		data[x][y].set_select(true);
		POINT begin = queue[0];
		//��
		direction(begin, 0, -1);
		//��
		direction(begin, 1, 0);
		//��
		direction(begin, 0, 1);
		//��
		direction(begin, -1, 0);
		//ɾ�������е�һ��Ԫ��
		data[m_p.x][m_p.y].clear();
		queue.erase(queue.begin());
	}
}