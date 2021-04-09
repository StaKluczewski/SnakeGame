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
	Direction m_LastDirection = Direction::Left;

public:

	SnakeTable(int height, int width);
	~SnakeTable();
	void setDirection(Direction dir);
	bool update();
	int** getTable();
	int getHeight();
	int getWidth();
	Direction getDirection();
};

