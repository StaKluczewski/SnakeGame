#pragma once
#include "Snake.h"
enum class Direction
{
	Up,
	Down,
	Left,
	Right
};

enum class TableItems
{
	Empty,
	SnakeBody,
	Food
};

class SnakeTable
{
private:
	int** m_table;
	int m_height;
	int m_width;

	int snakeHeadX = 10;
	int snakeHeadY = 10;

	Snake* m_snake;
	Direction m_LastDirection = Direction::Up;

public:
	SnakeTable(int height, int width);
	~SnakeTable();

	void update();

	int** getTable() {
		return this->m_table;
	}

	int getHeight() {
		return this->m_height;
	}

	int getWidth() {
		return this->m_width;
	}

	Direction getDirection() {
		return this->m_LastDirection;
	}

	void setDirection(Direction d) {
		this->m_LastDirection = d;
	}
};

