#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "Cocos2d.h"
#include "Actor.h"

USING_NS_CC;

class Player : public Actor {
public:
	Player();
	~Player();
	Player(const std::string image);
	Player(const std::string image, float x, float y);

	void initPhysicsBody();
	void playerAnimate();
	void jump();

	void moveLeft();
	void moveRight();

	void setJumpVector(int vec);
	void setMoveVector(int vec);
	void setHorizontalSpeed(int speed);

	int getJumpVector();
	int getMoveVector();
	Vec2 getSpeed();
	int jumpFlag = 0;
	bool isMovingLeft = false;
	bool isMovingRight = false;
private:
	int JUMP_VEC;
	int MOVE_VEC;
};
#endif