#include "MapReader.h"
#include "cocos2d.h"
#include "Floor.h"
USING_NS_CC;



MapReader::MapReader(std::string mapFile, float s) {
	map = TMXTiledMap::create(mapFile);
	SCALE = s;
	CCLOG("%d %d\n", SCALE, s);
	map->setScale(SCALE, SCALE);
	objectGroup = map->getObjectGroup("object");
	ValueVector floorVector = objectGroup->getObjects();
	
	//CCASSERT(NULL != objectGroup, "'Objects' object group not found");

	//CCASSERT(!floorVector.empty(), "'Objects' object not found");
	
	initFloorArray(floorVector);
}

void MapReader::setMap(TMXTiledMap *newMap) {
	map = newMap;
}

TMXTiledMap* MapReader::getMap() {
	if (map != NULL) return map;
	else return NULL;
}

Array* MapReader::getFloorArray(){
	return floorArray;
}

void MapReader::initFloorArray(ValueVector floorVector) {
	for (int i = 0; i < floorVector.size(); i++) {
		ValueMap tempBlock = floorVector.at(i).asValueMap();
		//CCLOG("%f\n", floorVector.at(i).asValueMap().at("x").asFloat());
		float x = tempBlock.at("x").asFloat() * SCALE;
		float y = tempBlock.at("y").asFloat() * SCALE;
		float width = tempBlock.at("width").asInt() * SCALE;
		float height = tempBlock.at("height").asInt() * SCALE;
		Floor *floor = new Floor(width, height);
		floor->setPosition(x+ width / 2, y + height / 2);
		floorArray->addObject(floor);
	}
}