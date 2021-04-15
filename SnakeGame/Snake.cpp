#include "Snake.h"
#include "SnakeTable.h"

#include <iostream>

Snake::Snake(int& Starting_Point, int max_Size)
{
	this->m_maxSize = max_Size;

	this->m_body.push_front(&Starting_Point);
	Starting_Point = (int)TableItems::SnakeBody;
}

/*
* @return false if body clash 
*/
bool Snake::move(int& next_p)
{
	if (this->getLenght() == 1)
	{
		*this->m_body.at(0) = (int)TableItems::Empty;

		this->m_body.at(0) = &next_p;
		*this->m_body.at(0) = (int)TableItems::SnakeBody;

		return true;
	}
	else
	{
		int lenght = this->getLenght();

		this->m_body.push_front(&next_p);
		*this->m_body.at(0) = (int)TableItems::SnakeBody;


		*m_body.back() = (int)TableItems::Empty;
		this->m_body.pop_back();
		
		bool not_crash = true;

		for (size_t i = 1; i < this->getLenght(); i++)
			if (this->m_body.at(i) == &next_p)
				not_crash = false;

		return not_crash;
	}
}

void Snake::eat(int& next_p)
{
	this->m_body.push_front(&next_p);
	*this->m_body.at(0) = (int)TableItems::SnakeBody;	
}

int Snake::getLenght()
{
	return this->m_body.size();
}

Snake::~Snake()
{
	
}
