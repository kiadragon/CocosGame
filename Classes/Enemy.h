#ifndef _ENEMY_H_
#define _ENEMY_H_
#include "Cocos2d.h"
#include "Actor.h"

USING_NS_CC;

class Enemy : public Actor {
public:
	Enemy();
	~Enemy();
	Enemy(const std::string fileName);
	Enemy(const std::string fileName, float x, float y);

	void initPhysicsBody();


	void playerAnimate();
	virtual void idleAnimate() = 0;
	virtual void runAnimate() = 0;
	virtual void attackAnimate() = 0;
	virtual void stiffAnimate() = 0;



	void setJumpVector(int vec);
	void setMoveVector(int vec);

	int getJumpVector();
	int getMoveVector();

	bool isSpeedZero();

protected:
	int JUMP_VEC = 600;
	int MOVE_VEC = 200;
	bool isFaceRight = true;
	bool isMove = false;
	Vec2 speed;

	Animation* runAnimation;
	Animation* idleAnimation;
	Animation* attackAnimation;
	Animation* stiffAnimation;
	Animate* currentAnimate;
	virtual void initIdleAnimation() = 0;
	virtual void initRunAnimation() = 0;
	virtual void initAttackAnimation() = 0;
	virtual void initStiffAnimation() = 0;
	virtual void initAnimate() = 0;

};
#endif