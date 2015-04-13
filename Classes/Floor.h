#ifndef _FLOOR_H_
#define _FLOOR_H_
#include "Cocos2d.h"
#include "Actor.h"
USING_NS_CC;


class Floor : public Actor {
public:
	Floor();
	~Floor();
	Floor(const std::string str);
	Floor(const std::string str, float x, float y);
	Floor(int width, int height);
	void initPhysicsBody();
	void initPhysicsBody(int w, int h);
private:
};


#endif