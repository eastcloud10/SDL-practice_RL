#ifndef DISPLAY_H_
#define DISPLAY_H_
//forward declaration
class unitManager;

class displayManager
{
public:
	static void displayInit();
	static void redraw();
	static void drawBackground();
	

	static SDL_Window* mainWindow;
	static SDL_Renderer* gRenderer;
	static SDL_Texture* gTexture;
	static std::list<displayManager*> displayUnitList;
	
public:
	displayManager(std::string uniqueName, const char* pathToImage, unitManager* unitPtr);
	~displayManager();
	void updateUnitPointer(unitManager* unitPtr);
	void updatePosition(int x, int y);
	

private:
	unitManager* m_unitPtr;
	SDL_Texture* m_texture;
	SDL_Rect* m_Rect;
	void fromXYtoRect(int x, int y, int *displayX, int *displayY);
};



#endif
