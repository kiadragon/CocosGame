/*************************************************************
Copyright: CocosGame
Author: kiadragon
Date: 2015-4
Description: Actor.cpp
Base Class for moveable sprite
**************************************************************/

#include "Actor.h"
#include <iostream>
/*************************************************
Function:       Actor Default Constructor
Description:	Constructor
Input:
Output:			
Return:      
*************************************************/
Actor::Actor() {
	_sprite = Sprite::create();
}

/*************************************************
Function:       Actor Constructor
Description:	Constructor by initialize by Image for Resource:/
Input:			String <fileName>
Return:
*************************************************/

Actor::Actor(const std::string image) {
	_sprite = Sprite::create(image);
}


/*************************************************
Function:       Actor SetPhysicsBody
Description:	set Actor a Phycics Body by Input
Input:			PhycicsBody p
Return:
*************************************************/
void Actor::setPhysicsBody(PhysicsBody* p) {
	_physicsBody = p;
}

/*************************************************
Function:       Actor getPhysicsBody
Description:	get Actor Phycics Body by Input
Input:			
Return:			PhycicsBody inside Actor			
*************************************************/
PhysicsBody* Actor::getPhysicsBody() {
	return _physicsBody;
}

/*************************************************
Function:       Actor setSprite
Description:	set Actor Sprite by Input Sprite
Input:			A sprite
Return:
*************************************************/
void Actor::setSprite(Sprite* sp) {
	_sprite = sp;
}

/*************************************************
Function:       Actor getSprite
Description:	get Actor Sprite
Input:			
Return:			the Sprite inside the Sprite
*************************************************/
Sprite* Actor::getSprite() {
	if (_sprite) return _sprite;
	else return NULL;
}

/*************************************************
Function:       Actor setPosition
Description:	set Actor Position
Input:			float x (x coordinate), float y (y coordinate)
Return:
*************************************************/
void Actor::setPosition(float x, float y) {
	_sprite->setPosition(x, y);
}

/*************************************************
Function:       Actor initPhysicsCollision
Description:	set Actor Physics Bit Mark
Input:			int CategoryBitMark, int CollisionBitMark,
				int CollisionTestBitMark, int group;
Return:
*************************************************/
void Actor::initPhysicsCollision(int CategoryBitMark,
	int CollisionBitMark,
	int Group, int ContactTestBitMark) {
	if (!_physicsBody) return; /* ensure _physicsBody Here */
	_physicsBody->setCategoryBitmask(CategoryBitMark);
	_physicsBody->setCollisionBitmask(CollisionBitMark);
	_physicsBody->setContactTestBitmask(ContactTestBitMark);
	_physicsBody->setGroup(Group);
}