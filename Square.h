#pragma once
class Square
{
public:
	Square(float x, float y);
	void update(float x, float y);
	~Square();
	float getx();
	float gety();
	void increaseSpeed();
private:
	float xpos;
	float ypos;
	float speed;
};

