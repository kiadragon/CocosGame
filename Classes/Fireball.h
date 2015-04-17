/*************************************************************
Copyright: CocosGame
Author: kiadragon
Date: 2015-4
Description: Fireball.h
Fireball trigger form Ememy header file
**************************************************************/
#ifndef _FIREBALL_H_
#define _FIREBALL_H_
#include "cocos2d.h"
#include "Actor.h"

USING_NS_CC;

class Fireball : public Actor {
public:

	Fireball(std::string direction);
	Fireball(std::string, float x, float y);

	void setAnimation();
private:
	int SPEED = 500; /* SPEED Coonstant */
	Vec2 speed = Vec2(0, 0);
	Animation* FireballFly = NULL;
	void setSpriteFrame(std::string direction);
	void initPhysicsBody();
	void initSpeed(std::string direction);

};

#endif