#pragma once
enum class Direction
{
	Up,
	Down,
	Left,
	Right
};

enum class TableItems
{
	SnakeBody,
	Food
};

class SnakeTable
{
private:
	int** m_table;
	int m_height;
	int m_width;
	Direction m_LastDirection;

public:
	SnakeTable(int height, int width);
	~SnakeTable();

	void update();

	int** getTable() {
		this->m_table;
	}

	int getHeight() {
		this->m_height;
	}

	int getWidth() {
		this->m_width;
	}

	Direction getDirection() {
		this->m_LastDirection;
	}

	void setDirection(Direction d) {
		this->m_LastDirection = d;
	}
};

