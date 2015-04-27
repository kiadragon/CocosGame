/*************************************************************
Copyright: CocosGame
Author: kiadragon
Date: 2015-4
Description: Fireball.cpp
Fireball trigger form Ememy
**************************************************************/
#include "Fireball.h"
#include "cocos2d.h"
USING_NS_CC;

/*************************************************
Function:       Fireball Default Constructor
Description:	Constructor
Input:			Direction: left right bottom top
Warning:		String pass into Actor Constructor IS HARDCODE_STYLE and Be care for file Existence;
*************************************************/
Fireball::Fireball(std::string direction) : Actor("fireball/fireball_" + direction + "_1.png") {
	initSpeed(direction);
	initPhysicsBody();
	setSpriteFrame(direction);
	setAnimation();
	_physicsBody->setVelocity(speed);
}

/*************************************************
Function:       Fireball Constructor
Description:	Constructor
Input:			Direction: left right bottom top
				Position: float x float y coordinate
Warning:		String pass into Actor Constructor IS HARDCODE_STYLE and Be care for file Existence;
*************************************************/
Fireball::Fireball(std::string direction, float x, float y) : Actor("fireball/fireball_" + direction + "_1.png") {
	initSpeed(direction);
	initPhysicsBody();
	setSpriteFrame(direction);
	setPosition(x, y);
	setAnimation();
	_physicsBody->setVelocity(speed);
}


/*************************************************
Function:       Fireball setAnimation
Description:	
*************************************************/
void Fireball::setAnimation() {
	_sprite->runAction(Animate::create(FireballFly));
}


/*************************************************
Function:       Fireball setSpriteFrame
Description:	Fireball set SpriteFrame inside it.
*************************************************/
void Fireball::setSpriteFrame(std::string direction) {
	FireballFly = Animation::create();
	for (int i = 1; i < 5; i++) {
		/* read File saved to SpriteFrame */
		FireballFly->addSpriteFrameWithFile("fireball/fireball_" 
			+ direction + "_" 
			+ (std::string)StringUtils::format("%d.png", i));
	}
	FireballFly->setDelayPerUnit(0.10f);
	FireballFly->setLoops(-1);
}

/*************************************************
Function:       Fireball initPhysicsBody
Description:	Fireball initialize PhysicsBody
*************************************************/
void Fireball::initPhysicsBody() {
	_physicsBody = PhysicsBody::createBox(_sprite->getContentSize(), PhysicsMaterial(10, 0, 0), Point::ZERO);
	_physicsBody->getShape(0)->setFriction(0);
	_physicsBody->getShape(0)->setMass(0);
	_physicsBody->setDynamic(true);
	_physicsBody->setRotationEnable(false);
	_physicsBody->setGravityEnable(false);
	initPhysicsCollision(0x10, 0x10, -1);
	_sprite->setPhysicsBody(_physicsBody);
}

/*************************************************
Function:       Fireball initspeed
Description:	Fireball initialize Speed
*************************************************/
void Fireball::initSpeed(std::string direction) {
	if ("left" == direction)  speed =  Vec2(-SPEED, 0);
	if ("right" == direction) speed =  Vec2(SPEED, 0);
	if ("top" == direction)   speed =  Vec2(0, SPEED);
	if ("bottom" == direction)speed =  Vec2(0, -SPEED);
}