#ifndef MAPMANAGER_H_
#define MAPMANAGER_H_

//forward declaration
class unitManager;

class mapManager {
public:
	mapManager(std::string uniqueName, int x, int y, unitManager* unitPtr):
		m_uniqueName(uniqueName), m_x(x), m_y(y)
	{
		unitList.push_back(this);
		m_unitPtr = unitPtr;
	}
	~mapManager() 
	{
		unitList.remove(this);
	}
	void makeMove(int deltaX, int deltaY);
private:
	unitManager* m_unitPtr;
	std::string m_uniqueName;
	int m_x;
	int m_y;
private:
	static std::list<mapManager*> unitList;
};
#endif
