#include"StateMachine.h"
#include<iostream>

StateMachine::StateMachine(Map& m):m(m)
{
	m_state = Idle;
}

//����״ִ̬�в���
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
		std::cout << "ѡ��" << endl;
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