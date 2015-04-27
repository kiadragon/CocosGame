#include "ControlSwordsman.h"
#include "cocos2d.h"

USING_NS_CC;

ControlSwordsman::ControlSwordsman(Swordsman* s) {
	if (_swordsman != NULL)
		_swordsman = s;
}

void ControlSwordsman::SwordsmanAI(int jumpFlag, bool isMovingRight, bool isMovingLeft, Vec2 playerPosition) {
	Vec2 smPosition = _swordsman->getSprite()->getPosition();

	if (playerPosition.x > smPosition.x) {
		_swordsman->moveRight();
	} else {
		_swordsman->moveLeft();
	}

	if (playerPosition.y < smPosition.y) {
		_swordsman->jump();
	}
}