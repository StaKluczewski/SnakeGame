#include "SnakeTable.h"
#include <time.h>
#include<cstdlib>

SnakeTable::SnakeTable(int height, int width)
{
	this->m_height = height;
	this->m_width = width;

	m_table = new int* [width];
	for (size_t i = 0; i < width; i++)
		m_table[i] = new int[height] { (int)TableItems::Empty };

	this->m_snake = new Snake(m_table[10][10], height * width);
}

bool SnakeTable::isFood(int i, int y)
{
	return this->m_table[i][y] == (int)TableItems::Food;
}

SnakeTable::~SnakeTable()
{
	for (size_t i = 0; i < this->m_width; i++)
		delete[] m_table[i];
	delete[] m_table;
}

FoodPos* SnakeTable::FoodPosGenerator() 
{
	int counter=0;							// counter 
	FoodPos** tab= new FoodPos*[this->m_height*this->m_width];				// tab with empty pos 
	FoodPos* posH = new FoodPos();							// helper 

	for (size_t x = 0; x < 20; x++)
	{
		for (size_t y = 0; y < 20; y++)
		{
			if (this->m_table[x][y] == (int)TableItems::Empty)
			{
				posH->pos_x = x;				// if empty set x and y to helper var
				posH->pos_y = y;
				tab[counter] = posH;		// write to table 
				counter++;					// increment counter
			}
		}
	}

	// get random pos from table
	// max = counter
	
	srand(time(0));
	int posRand = rand() % counter;

	return tab[posRand];
	
	
}

bool SnakeTable::update()
{
	switch (this->m_LastDirection)
	{
		case Direction::Up:
		{
			snakeHeadX--;
			if (snakeHeadX < 0)
				return false;									// KONIEC GRY BO W SCIANE UDERZY£

			return m_snake->move(m_table[snakeHeadX][snakeHeadY]);
			break;
		}

		case Direction::Down:
		{
			snakeHeadX++;
			if (snakeHeadX > m_width-1)
				return false;

			return m_snake->move(m_table[snakeHeadX][snakeHeadY]);
			break;
		}

		case Direction::Left:
		{
			snakeHeadY--;
			if (snakeHeadY < 0)
				return false;

			return m_snake->move(m_table[snakeHeadX][snakeHeadY]);
			break;
		}

		case Direction::Right:
		{
			snakeHeadY++;
			if (snakeHeadY > m_height -1)
				return false;

			return m_snake->move(m_table[snakeHeadX][snakeHeadY]);
			break;
		}
	}
	return true;
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