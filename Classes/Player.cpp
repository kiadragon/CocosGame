#include "Player.h"
#include "Cocos2d.h"
USING_NS_CC;
Player::Player() : Actor() {
	initPhysicsBody();
}

Player::Player(const std::string str) : Actor(str) {
	initPhysicsBody();
}

Player::Player(const std::string str, float x, float y) : Actor(str) {
	initPhysicsBody();
	setPosition(x, y);
}

void Player::initPhysicsBody() {

	_physicsBody = PhysicsBody::createBox(_sprite->getContentSize(), PHYSICSBODY_MATERIAL_DEFAULT, Point::ZERO);
	_physicsBody->getShape(0)->setFriction(0);
	_physicsBody->getShape(0)->setMass(0);
	_physicsBody->setDynamic(true);
	_physicsBody->setRotationEnable(false);
	_sprite->setPhysicsBody(_physicsBody);
}

void Player::moveLeft() {
	_physicsBody->getVelocity();
	_physicsBody->setVelocity(_physicsBody->getVelocity() + Vec2(-200, 0));
}

void Player::moveRight() {
	_physicsBody->setVelocity(_physicsBody->getVelocity() + Vec2(200, 0));
}

void Player::jump() {
	_physicsBody->setVelocity(_physicsBody->getVelocity() + Vec2(0, 400));
}

void Player::setJumpVector(int vec) {
	JUMP_VEC = vec;
}

void Player::setMoveVector(int vec) {
	MOVE_VEC = vec;
}

int Player::getJumpVector() {
	return JUMP_VEC;
}

int Player::getMoveVector() {
	return MOVE_VEC;
}

Player::~Player() {
	delete & _sprite;
	delete & _physicsBody;
}
