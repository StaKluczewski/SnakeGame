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

const int DISP_WIDTH = 600, DISP_HEIGHT = 600;
const int sizeOfSquare = 30;
const int tableHeight = 20;
const int tableWidth = 20;


void drawTable(SnakeTable *snakeT)
{
	for (int i = 0; i < tableHeight; i++)
	{
		for (int j = 0; j < tableWidth; j++)
		{
			switch (snakeT->getTable()[i][j])
			{
				case (int)TableItems::Empty :{
					//al_draw_rectangle((30) * j, i * 30, (30 * (j + 1)), (i * 30) + 30, al_map_rgb(255, 255, 255), 1.5);
					break;
				}
				case (int)TableItems::Food: {
					al_draw_rectangle((30) * j, i * 30, (30 * (j + 1)), (i * 30) + 30, al_map_rgb(255, 0, 0), 1.5);
					break;
				}
				case (int)TableItems::SnakeBody: {
					al_draw_filled_rectangle((30) * j, i * 30, (30 * (j + 1)), (i * 30) + 30, al_map_rgb(0, 0, 255));
					break;
				}

			default:
				break;
			}
			
		}
	}
}

int main()
{
    setlocale(LC_ALL, "polish");
    std::cout << "Witamy w grze snake!\n" << std::endl;
	
	al_init();
	al_init_primitives_addon();
	al_install_keyboard();
	al_install_mouse();

	ALLEGRO_DISPLAY* disp = al_create_display(DISP_WIDTH, DISP_HEIGHT);
	ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
	ALLEGRO_FONT* font = al_create_builtin_font();


	al_register_event_source(event_queue, al_get_keyboard_event_source());


	SnakeTable* snakeTable = new SnakeTable(tableHeight, tableWidth);
	
	
	while (true)
	{

		snakeTable->update();

		drawTable(snakeTable);
		al_flip_display();

		Sleep(2000);
	}
	
    system("pause");
    return 0;
}