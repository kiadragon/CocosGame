#include "Actor.h"
#include <iostream>

Actor::Actor() {
	_sprite = Sprite::create();
}

Actor::Actor(const std::string image) {
	_sprite = Sprite::create(image);
}

void Actor::setPhysicsBody(PhysicsBody* p) {
	_physicsBody = p;
}

PhysicsBody* Actor::getPhysicsBody() {
	return _physicsBody;
}

void Actor::setSprite(Sprite* sp) {
	_sprite = sp;
}

Sprite* Actor::getSprite() {
	if (_sprite) return _sprite;
	else return NULL;
}

void Actor::setPosition(float x, float y) {
	_sprite->setPosition(x, y);
}
