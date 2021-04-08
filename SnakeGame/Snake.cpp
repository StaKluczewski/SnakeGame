#include "Snake.h"
#include "SnakeTable.h"

Snake::Snake(int& Starting_Point, int max_Size)
{
	this->m_body = new int* [max_Size] { nullptr };
	this->m_body[0] = &Starting_Point;
	Starting_Point = (int)TableItems::SnakeBody;
}

void Snake::move(int& next_p)
{
	*this->m_body[0] = (int)TableItems::Empty;
	this->m_body[0] = &next_p;
	*this->m_body[0] = (int)TableItems::SnakeBody;
}

Snake::~Snake()
{
}
