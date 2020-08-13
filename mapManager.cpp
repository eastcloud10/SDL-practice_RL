#include <SDL.h>
#include <stdio.h>
#include <SDL_image.h>
#include <list>
#include <iostream>
#include "mapManager.h"
#include "unit.h"
#include "display.h"
std::list<mapManager*> mapManager::unitList;
const int MAX_X = 4;
const int MAX_Y = 4;
class unitManager;
class displayManager;



void mapManager::makeMove(int deltaX, int deltaY)
{
		m_x += deltaX;
		m_y += deltaY;
		if (m_x > MAX_X)	m_x = MAX_X;
		if (m_x < 0)		m_x = 0;
		if (m_y > MAX_Y)	m_y = MAX_Y;
		if (m_y < 0)		m_y = 0;
		m_unitPtr->m_displayPtr->updatePosition(m_x, m_y);
}
