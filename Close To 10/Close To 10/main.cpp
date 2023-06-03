#include<iostream>
#include<graphics.h>
#include<conio.h>
#include"Map.h"
#include"StateMachine.h"
using namespace std;

int main()
{
	srand((unsigned)time(NULL));//根据系统时间改变的随机种子
	initgraph(Map::BLOCK_SIZE*Map::WIDTH, Map::BLOCK_SIZE * Map::HEIGHT,SHOWCONSOLE);
	ExMessage msg;
	Map m;
	m.draw();
	StateMachine s(m);
	while (true)
	{
		bool b = peekmessage(&msg, EX_MOUSE);
		if (b && msg.message == WM_LBUTTONDOWN)
		{
			POINT p;
			p.x = msg.x;
			p.y = msg.y;
			m.set_position(p);
			if (s.m_state == Idle)
			{
				s.set_state(Select);
			}
			else if (s.m_state == Select)
			{
				s.set_state(Idle);
			}

			BeginBatchDraw();
			m.draw();
			EndBatchDraw();
		}
	}
	system("pause");
	return 0;
}