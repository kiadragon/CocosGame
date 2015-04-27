#ifndef __ControlforTest_H__
#define __ControlforTest_H__

#include "cocos2d.h"
#include "Player.h"
#include "ui\CocosGUI.h"

using namespace ui;
USING_NS_CC;

class ControlforTest : public Node{
public:
	ControlforTest(Node* p) {
		player = p;
	};
	EventListenerTouchOneByOne* controlPlayer();
	Node* getPlayer() {
		return player;
	};
	Button* getButton();

private:
	Button* _button;
	Node* player;
	Vec2 location = Vec2::ZERO;
	Vec2 jLocation = Vec2::ZERO;
};

#endif