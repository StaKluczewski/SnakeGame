#include "SnakeTable.h"

SnakeTable::SnakeTable(int height, int width)
{
	this->m_height = height;
	this->m_width = width;

	m_table = new int* [width];
	for (size_t i = 0; i < width; i++)
		m_table[i] = new int[height] { (int)TableItems::Empty };

	this->m_snake = new Snake(m_table[10][10], height * width);
}

SnakeTable::~SnakeTable()
{
	for (size_t i = 0; i < this->m_width; i++)
		delete[] m_table[i];
	delete[] m_table;
}

void SnakeTable::update()
{
	switch (this->m_LastDirection)
	{
	case Direction::Up:
	{
		snakeHeadX--;
		m_snake->move(m_table[snakeHeadX][snakeHeadY]);
		break;
	}

	case Direction::Down:
	{
		snakeHeadX++;
		m_snake->move(m_table[snakeHeadX][snakeHeadY]);
		break;
	}

	case Direction::Left:
	{
		snakeHeadY--;
		m_snake->move(m_table[snakeHeadX][snakeHeadY]);
		break;
	}

	case Direction::Right:
	{
		snakeHeadY++;
		m_snake->move(m_table[snakeHeadX][snakeHeadY]);
		break;
	}
	}
}

void SnakeTable::setDirection(Direction dir)
{
	m_LastDirection = dir;
}

int** SnakeTable::getTable()
{
	return this->m_table;
}

int SnakeTable::getHeight()
{
	return this->m_height;
}

int SnakeTable::getWidth()
{
	return this->m_width;
}

Direction SnakeTable::getDirection()
{
	return this->m_LastDirection;
}