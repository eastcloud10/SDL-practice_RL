/*This source code copyrighted by Lazy Foo' Productions (2004-2020)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include <SDL_image.h>
#include <vector>
#include <iostream>
#include <list>
#include "display.h"
#include "mapManager.h"
#include "unit.h"

//Screen dimension constants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

const int MAX_X = 4;
const int MAX_Y = 4;
//picture path
const char* PATH_TO_PNG = ".\\data\\hero.png";
const Uint32 ROUND_TIME = 100;

bool init();
int loop();
void exit();



unitManager* Hero = NULL;

int main( int argc, char* args[] )
{
	
	init();
	loop();
	exit();

	return 0;
}

bool init()
{
	//initialize environment

	bool success = true;
	
	displayManager::displayInit();
	Hero = new unitManager("hero", PATH_TO_PNG, 2, 2);


	return success;
}

int loop()
{
	//main function
	bool quit = false;
	SDL_Event e;
	int frame = 0;
	while (!quit)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
			else if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
			{
				switch (e.key.keysym.sym)
				{
				case SDLK_UP:
				case SDLK_k:
					Hero->m_mapPtr->makeMove(0, -1);
					break;
				case SDLK_DOWN:
				case SDLK_j:
					Hero->m_mapPtr->makeMove(0, 1);
					break;
				case SDLK_LEFT:
				case SDLK_h:
					Hero->m_mapPtr->makeMove(-1, 0);
					break;
				case SDLK_RIGHT:
				case SDLK_l:
					Hero->m_mapPtr->makeMove(1,0);
					break;
				case SDLK_ESCAPE:
					quit = true;
				}
			}
		}

		//loop screen display
		displayManager::redraw();
	}
	return 0;
}
 void exit()
{
	//clear environment
	delete Hero;
	return;
}
