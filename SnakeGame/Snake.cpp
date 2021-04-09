#include "Snake.h"
#include "SnakeTable.h"

Snake::Snake(int& Starting_Point, int max_Size)
{
	this->m_maxSize = max_Size;
	this->m_body = new int* [max_Size] { nullptr };
	this->m_body[0] = &Starting_Point;
	Starting_Point = (int)TableItems::SnakeBody;
}

bool Snake::move(int& next_p)
{
	if (this->getLenght() == 1)
	{
		*this->m_body[0] = (int)TableItems::Empty;
		this->m_body[0] = &next_p;
		*this->m_body[0] = (int)TableItems::SnakeBody;

		bool bodyContain = false;

		for (size_t i = 0; i < this->m_maxSize; i++)
			if (this->m_body[i] == &next_p)
				bodyContain = true;

		return bodyContain;
	}
	else
	{
		this->m_body[0] = &next_p;
		*this->m_body[0] = (int)TableItems::SnakeBody;

		for (size_t i = 1; i < this->getLenght()-1; i++)
			*this->m_body[i] = *this->m_body[i + 1];

		*this->m_body[this->getLenght() - 1] = (int)TableItems::SnakeBody;
	}
}

void Snake::eat(int& next_p)
{
	this->m_body[0] = &next_p;
	*this->m_body[0] = (int)TableItems::SnakeBody;

	for (size_t i = 0; i < this->getLenght() - 1; i++)
		*this->m_body[i] = *this->m_body[i + 1];
}

int Snake::getLenght()
{
	int temp = 1;

	for (size_t i = 1; i < m_maxSize; i++)
		if (m_body[i] != nullptr)
			temp++;
	
	return temp;
}

Snake::~Snake()
{
	if (m_body != nullptr)
	{
		delete[]m_body;
		m_body = nullptr;
	}
}
