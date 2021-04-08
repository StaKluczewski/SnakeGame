#pragma once
class Snake
{
private:
	int** m_body;
	int m_maxSize;

public:
	Snake(int& Starting_Point, int max_Size);
	void move(int& next_p);

	~Snake();

};

