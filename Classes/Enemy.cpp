#include "Enemy.h"
#include "Cocos2d.h"
USING_NS_CC;
Enemy::Enemy() : Actor() {
	initPhysicsBody();
}

Enemy::Enemy(const std::string str) {
	_sprite = Sprite::create(str + "/idle_1.png");
	initPhysicsBody();
}

Enemy::Enemy(const std::string str, float x, float y) {
	_sprite = Sprite::create(str + "idle_1.png");
	initPhysicsBody();
	setPosition(x, y);
}

void Enemy::initPhysicsBody() {
	_physicsBody = PhysicsBody::createBox(_sprite->getContentSize(), PhysicsMaterial(10,0,0), Point::ZERO);
	_physicsBody->getShape(0)->setFriction(0);
	_physicsBody->getShape(0)->setMass(0);
	_physicsBody->setDynamic(true);
	_physicsBody->setRotationEnable(false);
	_sprite->setPhysicsBody(_physicsBody);
	speed = Vec2(0, 0);
}

bool Enemy::isSpeedZero() {
	return speed.isZero();
}

void Enemy::setJumpVector(int vec) {
	JUMP_VEC = vec;
}

void Enemy::setMoveVector(int vec) {
	MOVE_VEC = vec;
}

int Enemy::getJumpVector() {
	return JUMP_VEC;
}

int Enemy::getMoveVector() {
	return MOVE_VEC;
}

Enemy::~Enemy() {
	delete & _sprite;
	delete & _physicsBody;
}
