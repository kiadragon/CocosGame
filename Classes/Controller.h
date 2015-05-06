#ifndef __Controller_H__
#define __Controller_H__

#include "cocos2d.h"
#include "Player.h"
#include"ui\CocosGUI.h"

USING_NS_CC;
using namespace ui;

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
	Button* getLeftBtn();
	Button* getRightBtn();

private:
	Player* player;
	Button* leftBtn;
	Button* rightBtn;
	Vec2 location = Vec2::ZERO;
	Vec2 jLocation = Vec2::ZERO;
};

#endif