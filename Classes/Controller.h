#ifndef __Controller_H__
#define __Controller_H__

#include "cocos2d.h"
#include "Player.h"

USING_NS_CC;

class Controller : public Node{
public:
	Controller(Player* p) {
		player = p;
	};
	EventListenerAcceleration* controlPlayer();
	EventListenerTouchOneByOne* controlPlayerJump();
	Player* getPlayer() {
		return player;
	};

private:
	Player* player;
	Vec2 location = Vec2::ZERO;
	Vec2 jLocation = Vec2::ZERO;
};

#endif