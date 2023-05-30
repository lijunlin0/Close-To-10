#pragma once
#include<graphics.h>

class Sprite
{
private:
	//ͼƬ
	IMAGE m_img;
	//ͼƬֵ
	int m_value;
	//�߼�λ��
	POINT m_position;
	//ͼƬ��ѡ��״̬
	bool m_select;
	//ͼƬ������״̬
	bool m_valid;
public:
	void init(POINT p, int value);
	//ֵ��Ӧ��ͼƬ·��
	LPCTSTR image_name(int value);
	//����ѡ��״̬
	void set_select(bool select);
	//�Ƿ�ѡ��
	bool is_select();
	//��������״̬
	void set_valid(bool valid);
	//�Ƿ�����
	bool is_valid();
	//��ȡͼƬ��ֵ
	int get_value();
	void to_plotting(int& x, int& y);
};