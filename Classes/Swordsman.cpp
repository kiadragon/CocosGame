#include "cocos2d.h"
#include "Swordsman.h"
#include "Enemy.h"
USING_NS_CC;


Swordsman::Swordsman(const std::string str) : Enemy(str) {
	initPhysicsBody();
	initAnimate();
	idleAnimate();
}

Swordsman::Swordsman(const std::string str, float x, float y) : Enemy(str) {
	initPhysicsBody();
	setPosition(x, y);

	initAnimate();
	idleAnimate();
}

void Swordsman::moveLeft() {
	speed = Vec2(-MOVE_VEC, 0);
	if (isSpeedZero()) {
		idleAnimate();
		isMove = false;
		return;
	}
	if (isFaceRight) {
		_sprite->setFlippedX(true);
		isFaceRight = false;
	}

	if (!isMove) {
		runAnimate();
		isMove = true;
	}
	_physicsBody->setVelocity(speed);
}

void Swordsman::moveRight() {

	
	speed = Vec2(MOVE_VEC, 0);
	if (isSpeedZero()) {
		idleAnimate();
		isMove = false;
		return;
	}
	if (!isFaceRight) {
		_sprite->setFlippedX(false);
		isFaceRight = true;
	}

	if (!isMove) {
		runAnimate();
		isMove = true;
	}

	_physicsBody->setVelocity(speed);
}

void Swordsman::jump() {
	// one jump
	if (_physicsBody->getVelocity().y == 0) {
		_physicsBody->setVelocity(_physicsBody->getVelocity() + Vec2(0, JUMP_VEC));
		runAnimate();
	}
}




void Swordsman::idleAnimate() {
	currentAnimate = Animate::create(idleAnimation);
	_sprite->runAction(currentAnimate);
}

void Swordsman::runAnimate() {
	_sprite->stopAllActions();
	_sprite->runAction(Animate::create(runAnimation));
}

void Swordsman::attackAnimate() {
	currentAnimate = Animate::create(attackAnimation);
	_sprite->stopAllActions();

	_sprite->runAction(currentAnimate);
}

void Swordsman::stiffAnimate() {
	currentAnimate = Animate::create(stiffAnimation);
	_sprite->stopAllActions();

	_sprite->runAction(currentAnimate);
}


void Swordsman::initIdleAnimation() {
	idleAnimation = Animation::create();
	idleAnimation->retain();
	for (int i = 1; i < 5; i++) {
		idleAnimation->addSpriteFrameWithFile((std::string)StringUtils::format("Swordsman/idle_%d.png", i));
	}
	idleAnimation->setDelayPerUnit(0.18f);
	idleAnimation->setLoops(-1);
}

void Swordsman::initRunAnimation() {
	runAnimation = Animation::create();
	runAnimation->retain();
	for (int i = 1; i < 5; i++) {
		runAnimation->addSpriteFrameWithFile((std::string)StringUtils::format("Swordsman/move_%d.png", i));
	}
	runAnimation->setDelayPerUnit(0.18f);
	runAnimation->setLoops(-1);
}

void Swordsman::initAttackAnimation() {
	attackAnimation = Animation::create();
	attackAnimation->retain();
	for (int i = 1; i < 7; i++) {
		attackAnimation->addSpriteFrameWithFile((std::string)StringUtils::format("Swordsman/attack_%d.png", i));
	}
	attackAnimation->setDelayPerUnit(0.18f);
	attackAnimation->setLoops(-1);
}

void Swordsman::initStiffAnimation() {
	stiffAnimation = Animation::create();
	stiffAnimation->retain();
	for (int i = 1; i < 4; i++) {
		stiffAnimation->addSpriteFrameWithFile((std::string)StringUtils::format("Swordsman/fall_%d.png", i));
	}
	stiffAnimation->setDelayPerUnit(0.18f);
	stiffAnimation->setLoops(-1);
}

void Swordsman::initAnimate() {
	initIdleAnimation();
	initRunAnimation();
	initAttackAnimation();
	initStiffAnimation();
}