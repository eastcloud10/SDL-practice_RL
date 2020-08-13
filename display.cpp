#include <SDL.h>
#include <stdio.h>
#include <SDL_image.h>
#include <vector>
#include <iostream>
#include <list>
#include "display.h"

const char* TITLE = "5x5 adventure";
const int SCREEN_WIDTH = 800, SCREEN_HEIGHT = 600;
SDL_Window* displayManager::mainWindow;
SDL_Renderer* displayManager::gRenderer;
SDL_Texture* displayManager::gTexture;
std::list<displayManager*> displayManager::displayUnitList;

void displayManager::displayInit()
{
	SDL_Surface* windowSurface;

	mainWindow = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
										SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	gRenderer = SDL_CreateRenderer(mainWindow, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);

	windowSurface = SDL_GetWindowSurface(mainWindow);
	gTexture = SDL_CreateTextureFromSurface(gRenderer, windowSurface);
	SDL_FreeSurface(windowSurface);
	windowSurface = NULL;

	IMG_Init(IMG_INIT_PNG);
	SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0xFF);
}
displayManager::displayManager(std::string uniqueName, const char* pathToImage, unitManager* unitPtr)
{
	SDL_Surface* spriteSurface;
	m_Rect = new SDL_Rect();
	m_Rect->x = 0;
	m_Rect->y = 0;
	m_Rect->w = 80;
	m_Rect->h = 80;
	m_unitPtr = unitPtr;
	spriteSurface = IMG_Load(pathToImage);
	m_texture = SDL_CreateTextureFromSurface(displayManager::gRenderer, spriteSurface);
	SDL_FreeSurface(spriteSurface);
	spriteSurface = NULL;

	displayManager::displayUnitList.push_back(this);
}


displayManager::~displayManager()
{
	delete m_Rect;
	displayUnitList.remove(this);
	SDL_DestroyTexture(m_texture);
	m_texture = NULL;
}

void displayManager::updateUnitPointer(unitManager* unitPtr)
{
	m_unitPtr = unitPtr;
}


void displayManager::updatePosition(int x, int y)
{
	int displayX, displayY;
	fromXYtoRect(x, y, &displayX, &displayY);
	m_Rect->x = displayX;
	m_Rect->y = displayY;
	return;
}

void displayManager::redraw()
{
		SDL_RenderClear(gRenderer);

		SDL_RenderCopy(gRenderer, gTexture, NULL, NULL); //Background
		drawBackground();		
		for (displayManager* U:displayUnitList)
		{
			SDL_RenderCopy(gRenderer, U->m_texture, NULL, U->m_Rect);
		}
		SDL_RenderPresent(gRenderer);
}
void displayManager::drawBackground()
{
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderDrawLine(gRenderer, 150, 50, 650, 50);
	SDL_RenderDrawLine(gRenderer, 150, 150, 650, 150);
	SDL_RenderDrawLine(gRenderer, 150, 250, 650, 250);
	SDL_RenderDrawLine(gRenderer, 150, 350, 650, 350);
	SDL_RenderDrawLine(gRenderer, 150, 450, 650, 450);
	SDL_RenderDrawLine(gRenderer, 150, 550, 650, 550);

	SDL_RenderDrawLine(gRenderer, 150, 50, 150, 550);
	SDL_RenderDrawLine(gRenderer, 250, 50, 250, 550);
	SDL_RenderDrawLine(gRenderer, 350, 50, 350, 550);
	SDL_RenderDrawLine(gRenderer, 450, 50, 450, 550);
	SDL_RenderDrawLine(gRenderer, 550, 50, 550, 550);
	SDL_RenderDrawLine(gRenderer, 650, 50, 650, 550);

	return;
}
void displayManager::fromXYtoRect(int x, int y, int *displayX, int *displayY)
{
	*displayX = 160 + x * 100;
	*displayY = 60 + y * 100;
	return;
}
