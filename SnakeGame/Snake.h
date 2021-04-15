#pragma once
#include <deque>


class Snake
{
private:
	std::deque<int*> m_body = {};
	int m_maxSize;

public:
	Snake(int& Starting_Point, int max_Size);
	bool move(int& next_p);
	void eat(int& next_p);
	int getLenght();

	~Snake();

};

