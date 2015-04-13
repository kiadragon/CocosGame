#ifndef _MAPREADER_H_
#define _MAPREADER_H_

#include "cocos2d.h"
USING_NS_CC;

class MapReader {
public:
	MapReader(std::string mapFile, float s);
	void setMap(TMXTiledMap *map);
	TMXTiledMap* getMap();
	Array* getFloorArray();
	void createFloor();
	void setScale(int s);
	int getScale();
private:
	TMXTiledMap *map = NULL;
	TMXObjectGroup* objectGroup;
	Array *floorArray = Array::create();
	// Map SCALE to setMap Size
	float SCALE = 1;
protected:
	void initFloorArray(ValueVector);
};

#endif _MAPREADER_H_