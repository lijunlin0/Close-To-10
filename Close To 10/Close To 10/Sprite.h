#pragma once
#include<graphics.h>

class Sprite
{
private:
	//图片
	IMAGE m_img;
	//图片值
	int m_value;
	//逻辑位置
	POINT m_position;
	//图片的选择状态
	bool m_select;
	//图片的消除状态
	bool m_valid;
public:
	void init(POINT p, int value);
	//值对应的图片路径
	LPCTSTR image_name(int value);
	//设置选择状态
	void set_select(bool select);
	//是否被选择
	bool is_select();
	//设置消除状态
	void set_valid(bool valid);
	//是否被消除
	bool is_valid();
	//获取图片的值
	int get_value();
	void to_plotting(int& x, int& y);
};