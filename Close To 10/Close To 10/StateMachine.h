#pragma once
#include"Map.h"
enum State
{
	//Ĭ��
	Idle = 0,
	//ѡ��
	Select = 1,
	//����
	Eliminate = 2
};

class StateMachine
{
public:
	State m_state;
	StateMachine(Map& m);
	Map& m;
	//����״ִ̬�в���
	void set_state(State state);
	// �������
	void reset();
	//����ѡ��
	void high_light();

};