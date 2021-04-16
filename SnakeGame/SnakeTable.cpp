#include "SnakeTable.h"
#include <time.h>
#include<cstdlib>
#include <iostream>
#include <vector>
SnakeTable::SnakeTable(int height, int width)
{
	this->m_height = height;
	this->m_width = width;

	m_table = new int* [width];
	for (size_t i = 0; i < width; i++)
		m_table[i] = new int[height] { (int)TableItems::Empty };

	this->m_snake = new Snake(m_table[10][10], height * width);

	if (!m_food_exist)
		this->generateFood();
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
	



	/*
	//std::cout << "DUPA" << std::endl;
	int counter=0;																			// counter 
	std::vector<FoodPos**> tab= new FoodPos*[(this->m_height*this->m_width)];				// tab with empty pos 
	FoodPos* posH = new FoodPos();															// helper 
	
	for (size_t x = 0; x < 20; x++)
	{
		for (size_t y = 0; y < 20; y++)
		{
			
			if (this->m_table[x][y] == (int)TableItems::Empty)
			{
				posH->pos_x = x;										// if empty set x and y to helper var
				posH->pos_y = y;
				tab[counter] = posH;		// write to table 
				counter++;					// increment counter
			}
		}
	}

	// get random pos from table
	// max = counter
	
	std::cout << "licznik:" << counter << std::endl;
	int posRand = 1+(rand() % counter);
	std::cout << "wylosowane:"<<posRand << std::endl;
	std::cout << "pos x:"<< tab[posRand]->pos_x << std::endl;
	std::cout << "pos y:"<< tab[posRand]->pos_y << std::endl;
	m_table[tab[posRand]->pos_x][tab[posRand]->pos_y] = (int)TableItems::Food;
	//m_table[5][5] = (int)TableItems::Food;

	//m_table[9][9] = (int)TableItems::Food;
	*/
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