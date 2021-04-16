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

struct FoodPos
{
	int pos_x;
	int pos_y;
};

class SnakeTable
{
private:
	int** m_table;
	int m_height;
	int m_width;
	int snakeHeadX = 10;
	int snakeHeadY = 10;
	int scoreCounter = 0;
	bool m_food_exist = false;

	bool isFood(int, int);
	void generateFood();
	Snake* m_snake;
	Direction m_LastDirection = Direction::Left;

public:
	int getScore();
	SnakeTable(int height, int width);
	~SnakeTable();
	void setDirection(Direction dir);
	bool update();
	int** getTable();
	int getHeight();
	int getWidth();
	Direction getDirection();
};

