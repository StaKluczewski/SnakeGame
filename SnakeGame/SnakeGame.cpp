#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>	
#include <allegro5/allegro_primitives.h>
#include <Windows.h>
#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <math.h>
#include "SnakeTable.h"
#include <time.h>
#include <string>
#include <sstream>

const int DISP_WIDTH = 600, DISP_HEIGHT = 600;
const int sizeOfSquare = 30;
const int tableHeight = 20;
const int tableWidth = 20;



void drawTable(SnakeTable* snakeT)
{
	for (int i = 0; i < tableHeight; i++)
	{
		for (int j = 0; j < tableWidth; j++)
		{
			switch (snakeT->getTable()[i][j])
			{
			case (int)TableItems::Empty:
			{
				al_draw_filled_rectangle((30) * j, i * 30, (30 * (j + 1)), (i * 30) + 30, al_map_rgb(0, 0, 0));
				break;
			}
			case (int)TableItems::Food:
			{
				al_draw_filled_rectangle((30) * j, i * 30, (30 * (j + 1)), (i * 30) + 30, al_map_rgb(255, 0, 0));
				break;
			}
			case (int)TableItems::SnakeBody:
			{
				al_draw_filled_rectangle((30) * j, i * 30, (30 * (j + 1)), (i * 30) + 30, al_map_rgb(0, 0, 255));
				break;
			}

			}

		}
	}
}

using std::endl;
using std::cout;
using std::cerr;


int main()
{
	srand((unsigned)time(NULL));
	//setlocale(LC_ALL, "polish");
	//std::cout << "Witamy w grze snake!\n" << std::endl;

	al_init();
	al_init_primitives_addon();
	al_install_keyboard();
	al_install_mouse();

	ALLEGRO_DISPLAY* disp = al_create_display(DISP_WIDTH, DISP_HEIGHT);
	ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
	ALLEGRO_FONT* font = al_create_builtin_font();


	al_register_event_source(event_queue, al_get_keyboard_event_source());


	SnakeTable* snakeTable = new SnakeTable(tableHeight, tableWidth);

	

	//bool al_key_down(const ALLEGRO_KEYBOARD_STATE * state, int keycode)
	//snakeTable.


	bool isGameOn = true;
	int milisPerMove = 50;

	ALLEGRO_KEYBOARD_STATE state;

	ALLEGRO_KEYBOARD_STATE copy_state;

	while (isGameOn)
	{
		int milis = 0;

		do {
			
			al_get_keyboard_state(&state);
			if (al_key_down(&state, ALLEGRO_KEY_W))
			{
				copy_state = state;
				Sleep(100);
				break;
			}
			else if (al_key_down(&state, ALLEGRO_KEY_S))
			{
				copy_state = state;
				Sleep(100);
				break;
			}
			else if (al_key_down(&state, ALLEGRO_KEY_A))
			{
				copy_state = state;
				Sleep(100);
				break;
			}
			else if (al_key_down(&state, ALLEGRO_KEY_D))
			{
				copy_state = state;
				Sleep(100);
				break;
			}
			Sleep(10);
			milis++;
		} while (milis < milisPerMove);

		

		if (al_key_down(&state,ALLEGRO_KEY_W))
		{
			snakeTable->setDirection(Direction::Up);
		}
		else if(al_key_down(&state, ALLEGRO_KEY_S))
		{
			snakeTable->setDirection(Direction::Down);
		}
		else if (al_key_down(&state, ALLEGRO_KEY_A))
		{
			snakeTable->setDirection(Direction::Left);
		}
		else if (al_key_down(&state, ALLEGRO_KEY_D))
		{
			snakeTable->setDirection(Direction::Right);
		}

		isGameOn = snakeTable->update();
		
		drawTable(snakeTable);

		
		al_draw_textf(font, al_map_rgb(255, 0, 0), 300, 50,
			ALLEGRO_ALIGN_CENTER,"SCORE:  %d", snakeTable->getScore());
		al_flip_display();


	}
	//cout << "PROSZĘ PANA DZIAŁA!!!" << endl;

	system("pause");
	return 0;
}