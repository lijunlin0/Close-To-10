#include"StateMachine.h"

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
	if (m_state = Select)
	{
		m.eliminate();
		m_state = Idle;
	}
}

void StateMachine::reset()
{

}