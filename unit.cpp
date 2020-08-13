#include <SDL.h>
#include <stdio.h>
#include <SDL_image.h>
#include <vector>
#include <iostream>
#include <list>
#include "display.h"
#include "mapManager.h"
#include "unit.h"

class mapManager;
class displayManager;
std::list<unitManager> unitManager::unitList;

unitManager::unitManager(std::string uniqueName, const char* pathToImage, int initialX, int initialY)
{
	m_displayPtr = new displayManager(uniqueName, pathToImage,this);
	m_mapPtr = new mapManager(uniqueName, initialX, initialY,this);
	m_displayPtr->updatePosition(initialX, initialY);
}
unitManager::~unitManager()
{
	delete m_displayPtr;
	delete m_mapPtr;
}
