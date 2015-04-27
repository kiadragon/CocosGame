#ifndef __CONTROLSWORDSMAN_H__
#define __CONTROLSWORDSMAN_H__

#include "cocos2d.h"
#include "Swordsman.h"

class ControlSwordsman {
public:
	ControlSwordsman(Swordsman* s);
	void SwordsmanAI(int jumpFlag, bool isMovingRight, bool isMovingLeft, Vec2 playerPosition);
private:
	Swordsman* _swordsman;
};




#endif