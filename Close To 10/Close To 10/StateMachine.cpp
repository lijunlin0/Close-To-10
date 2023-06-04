#include"StateMachine.h"
#include<iostream>

StateMachine::StateMachine(Map& m):m(m)
{
	m_state = Idle;
}

//根据状态执行操作
void StateMachine::set_state(State state)
{
	m_state = state;
	if (m_state == Idle)
	{
		reset();
	}
	else if (m_state == Select)
	{
		m.find();
		std::cout << "选中" << endl;
	}
	else
	{
		m.eliminate();
		set_state(Idle);
	}
}

void StateMachine::reset()
{

}