#include "Floor.h"
#include "Cocos2d.h"

USING_NS_CC;

Floor::Floor(const std::string str) : Actor(str){
	initPhysicsBody();
	_physicsBody->setDynamic(false);
}

Floor::Floor(const std::string str, float x, float y) : Actor(str) {
	initPhysicsBody();
	this->setPosition(x, y);
}

Floor::Floor(int width, int height){
	_sprite = Sprite::create();
	initPhysicsBody(width, height);
}

void Floor::initPhysicsBody() {

	_physicsBody = PhysicsBody::createEdgeBox(_sprite->getContentSize(), PHYSICSBODY_MATERIAL_DEFAULT, 3);
	_physicsBody->setDynamic(false);
	_physicsBody->getShape(0)->setFriction(0);
	_physicsBody->getShape(0)->setRestitution(0);
	_physicsBody->getShape(0)->setMass(0);
	_sprite->setPhysicsBody(_physicsBody);
}

void Floor::initPhysicsBody(int width, int height) {
	_physicsBody = PhysicsBody::createBox(Size(width, height), PHYSICSBODY_MATERIAL_DEFAULT);
	_physicsBody->setDynamic(false);
	_physicsBody->getShape(0)->setFriction(0);
	_physicsBody->getShape(0)->setRestitution(0);
	_physicsBody->getShape(0)->setMass(0);
	_sprite->setPhysicsBody(_physicsBody);

}

Floor::~Floor() {
	delete & _sprite;
	delete & _physicsBody;
}