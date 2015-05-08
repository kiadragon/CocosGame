#ifndef _MAPREADER_H_
#define _MAPREADER_H_

#include "cocos2d.h"
USING_NS_CC;
class MapReader {
public:
	MapReader(std::string mapName, float s);
	void setMap(TMXTiledMap *map);
	TMXTiledMap* getMap();
	Sprite* getBackground();
	Array* getFloorArray();
	void createFloor();
	void setScale(int s);
	int getScale();
private:
	TMXTiledMap *map = NULL;
	Sprite* background;
	TMXObjectGroup* objectGroup;
	Array *floorArray = Array::create();
	// Map SCALE to setMap Size
	float SCALE = 1;
protected:
	void initBackgroundSprite();
	void initFloorArray(ValueVector);
};

#endif