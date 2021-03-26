#include "Snake.h"

Snake::Snake(int* Starting_Point, int max_Size)
{
	this->m_body = new int*[max_Size];
	this->m_body[0] = Starting_Point;
}

void Snake::move(int* next_p)
{

}

Snake::~Snake()
{
}
