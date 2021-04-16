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

bool SnakeTable::isWall(int i, int y)
{
	return this->m_table[i][y] == (int)TableItems::Wall;
}


SnakeTable::~SnakeTable()
{
	for (size_t i = 0; i < this->m_width; i++)
		delete[] m_table[i];
	delete[] m_table;
}

void SnakeTable::generateFood() 
{
	int MAX = 20;	
	int posRandX;
	int posRandY;

	do
	{
		posRandX = 0 + (rand() % MAX);	// random number x
		posRandY = 0 + (rand() % MAX);	// random number y
	} while (this->m_table[posRandX][posRandY] == (int)TableItems::SnakeBody || this->m_table[posRandX][posRandY] == (int)TableItems::Wall);
	


	this->m_table[posRandX][posRandY] = (int)TableItems::Food;	// m table pixel x pixel y = food 

}

void SnakeTable::generateWall()
{
	int MAX = 20;
	int posRandX;
	int posRandY;

	do
	{
		posRandX = 0 + (rand() % MAX);	// random number x
		posRandY = 0 + (rand() % MAX);	// random number y
	} while (this->m_table[posRandX][posRandY] == (int)TableItems::SnakeBody || this->m_table[posRandX][posRandY] == (int)TableItems::Food);



	this->m_table[posRandX][posRandY] = (int)TableItems::Wall;	// m table pixel x pixel y = food 

}

bool SnakeTable::update()
{
	switch (this->m_LastDirection)
	{
		case Direction::Up:
		{
			snakeHeadX--;
			if (snakeHeadX < 0)
			{
				std::cout << "wjazd w scaine" << std::endl;
				return false;									// KONIEC GRY BO W SCIANE UDERZY£
			}
			if (this->isWall(snakeHeadX, snakeHeadY))
				return false;
			

			if (this->isFood(snakeHeadX, snakeHeadY))
			{
				m_snake->eat(m_table[snakeHeadX][snakeHeadY]);
				this->scoreCounter++;
				if (scoreCounter % 10 == 0)
				{

					std::cout << "odpalam" << std::endl;
					this->generateWall();
				}

				m_food_exist = false;
				break;
			}
			else
				return m_snake->move(m_table[snakeHeadX][snakeHeadY]);
		}

		case Direction::Down:
		{
			snakeHeadX++;
			if (snakeHeadX > m_width - 1)
			{
				std::cout << "wjazd w scaine" << std::endl;
				return false;
			}
			if (this->isWall(snakeHeadX, snakeHeadY))
				return false;
			if (this->isFood(snakeHeadX, snakeHeadY))
			{
				m_snake->eat(m_table[snakeHeadX][snakeHeadY]);
				this->scoreCounter++;
				if (scoreCounter % 10 == 0)
				{

					std::cout << "odpalam" << std::endl;
					this->generateWall();
				}

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
			{
				std::cout << "wjazd w scaine" << std::endl;
				return false;
			}
			if (this->isWall(snakeHeadX, snakeHeadY))
				return false;
			if (this->isFood(snakeHeadX, snakeHeadY))
			{
				m_snake->eat(m_table[snakeHeadX][snakeHeadY]);
				this->scoreCounter++;
				if (scoreCounter % 10 == 0)
				{

					std::cout << "odpalam" << std::endl;
					this->generateWall();
				}

				m_food_exist = false;
				break;
			}
			else
				return m_snake->move(m_table[snakeHeadX][snakeHeadY]);
		}

		case Direction::Right:
		{
			snakeHeadY++;
			if (snakeHeadY > m_height - 1)
			{
				std::cout << "wjazd w scaine" << std::endl;
				return false;
			}
			if (this->isWall(snakeHeadX, snakeHeadY))
				return false;
			if (this->isFood(snakeHeadX, snakeHeadY))
			{
				m_snake->eat(m_table[snakeHeadX][snakeHeadY]);
				this->scoreCounter++;
				if (scoreCounter % 10 == 0)
				{

					std::cout << "odpalam" << std::endl;
					this->generateWall();
				}

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