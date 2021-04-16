#include "SnakeTable.h"
#include <time.h>
#include<cstdlib>
#include <iostream>
#include <vector>

int SnakeTable::getScore()
{
	return this->scoreCounter;
}
SnakeTable::SnakeTable(int height, int width)
{
	this->m_height = height;
	this->m_width = width;

	m_table = new int* [width];
	for (size_t i = 0; i < width; i++)
		m_table[i] = new int[height] { (int)TableItems::Empty };

	this->m_snake = new Snake(m_table[10][10], height * width);

	if (!m_food_exist)
	{
		this->generateFood();
	}
		
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

void SnakeTable::generateFood() 
{
	int MAX = 20;						// MAX number
	int posRandX = 0 + (rand() % MAX);	// random number x
	int posRandY = 0 + (rand() % MAX);	// random number y
	if (this->m_table[posRandX][posRandY] != (int)TableItems::Empty && this->m_table[posRandX][posRandY] != (int)TableItems::SnakeBody){
		this->m_table[posRandX][posRandY] = (int)TableItems::Food;	// m table pixel x pixel y = food 
	
	}
	else {
			posRandX = 0 + (rand() % MAX);
			posRandY = 0 + (rand() % MAX);
			this->m_table[posRandX][posRandY] = (int)TableItems::Food; // m table pixel x pixel y = food 
	}
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

			if (this->isFood(snakeHeadX, snakeHeadY))
			{
				m_snake->eat(m_table[snakeHeadX][snakeHeadY]);
				this->scoreCounter++;
				m_food_exist = false;
				break;
			}
			else
				return m_snake->move(m_table[snakeHeadX][snakeHeadY]);
		}

		case Direction::Down:
		{
			snakeHeadX++;
			if (snakeHeadX > m_width-1)
				return false;

			if (this->isFood(snakeHeadX, snakeHeadY))
			{
				m_snake->eat(m_table[snakeHeadX][snakeHeadY]);
				this->scoreCounter++;
				m_food_exist = false;
				break;
			}
			else
				return m_snake->move(m_table[snakeHeadX][snakeHeadY]);
		}

		case Direction::Left:
		{
			snakeHeadY--;
			if (snakeHeadY < 0)
				return false;

			if (this->isFood(snakeHeadX, snakeHeadY))
			{
				m_snake->eat(m_table[snakeHeadX][snakeHeadY]);
				this->scoreCounter++;
				m_food_exist = false;
				break;
			}
			else
				return m_snake->move(m_table[snakeHeadX][snakeHeadY]);
		}

		case Direction::Right:
		{
			snakeHeadY++;
			if (snakeHeadY > m_height -1)
				return false;

			if (this->isFood(snakeHeadX, snakeHeadY))
			{
				m_snake->eat(m_table[snakeHeadX][snakeHeadY]);
				this->scoreCounter++;
				m_food_exist = false;
				break;
			}
			else
				return m_snake->move(m_table[snakeHeadX][snakeHeadY]);
		}
	}
	if (m_food_exist == false)
	{
		this->generateFood();
		m_food_exist = true;
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