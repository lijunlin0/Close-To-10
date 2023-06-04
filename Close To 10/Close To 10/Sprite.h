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
public:
	void init(POINT p, int value);
	//ֵ��Ӧ��ͼƬ·��
	LPCTSTR image_name(int value);
	//����ѡ��״̬
	void set_select(bool select);
	//�Ƿ�ѡ��
	bool is_select();
	//��ȡͼƬ��ֵ
	int get_value();
	void set_value(int value);
	void to_plotting(int& x, int& y);
	void from_plotting(int& x, int& y);
	//�����ǰͼƬ
	void clear();
	void draw();
	//����ͼƬ
	void highlight();
};