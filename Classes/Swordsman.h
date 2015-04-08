#ifndef _SWORDSMAN_H_
#define _SWORDSMAN_H_
#include "cocos2d.h"
#include "Enemy.h"
USING_NS_CC;

class Swordsman : public Enemy {
public:
	Swordsman(const std::string fileName);
	Swordsman(const std::string fileName, float x, float y);
	
	void jump();

	void moveLeft();
	void moveRight();

	void idleAnimate();
	void runAnimate();
	void attackAnimate();
	void stiffAnimate();
private:
	// ¼ÆÊ±Æ÷
	int timer;
	int AttackType;
	virtual void initIdleAnimation();
	virtual void initRunAnimation();
	virtual void initAttackAnimation();
	virtual void initStiffAnimation();
	virtual void initAnimate();
};

#endif