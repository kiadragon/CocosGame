/*************************************************************
Copyright: CocosGame
Author: kiadragon
Date: 2015-4
Description: Actor.h
Base Class for moveable sprite header file
**************************************************************/
#ifndef _ACTOR_H_
#define _ACTOR_H_
#include "Cocos2d.h"
USING_NS_CC;

class Actor : public Node {
public:
	Actor();
	Actor(const std::string image);
	void setSprite(Sprite* sp);
	Sprite* getSprite();

	void setPhysicsBody(PhysicsBody* p);
	PhysicsBody* getPhysicsBody();

	void setPosition(float x, float y);

	void initPhysicsCollision(int CategoryBitMark = 0xFFFFFFFF,
		int CollisionBitMask   = 0xFFFFFFFF,
		int groupIndex = 0,
		int ContactTestBitMask = 0x00000000);
protected:
	Sprite* _sprite; /* Sprite inside Actor */
	PhysicsBody* _physicsBody; /* PhysicsBody inside Actor */
};


#endif