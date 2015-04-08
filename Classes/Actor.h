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
protected:
	Sprite* _sprite;
	PhysicsBody* _physicsBody;
};


#endif