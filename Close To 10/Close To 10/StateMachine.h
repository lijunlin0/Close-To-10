#pragma once
#include"Map.h"
enum State
{
	//默认
	Idle = 0,
	//选中
	Select = 1,
	//消除
	Eliminate = 2
};

class StateMachine
{
public:
	State m_state;
	StateMachine(Map& m);
	Map& m;
	//根据状态执行操作
	void set_state(State state);
	// 清除高亮
	void reset();
	//高亮选中
	void high_light();

};