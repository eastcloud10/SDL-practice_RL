#ifndef UNIT_H_
#define UNIT_H_

//forward declaration
class displayManager;
class mapManager;

class unitManager
{
private:
	static std::list<unitManager> unitList;
public:
	unitManager(std::string uniqueName, const char* pathToImage, int initialX, int initialY);
	~unitManager();
	displayManager* m_displayPtr;
	mapManager* m_mapPtr;

};



#endif