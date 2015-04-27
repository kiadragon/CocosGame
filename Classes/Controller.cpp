#include "cocos2d.h"
#include "Controller.h"
#include "Player.h"
#include "HelloWorldScene.h"
#include "AppDelegate.h"
USING_NS_CC;

EventListenerAcceleration* Controller::controlPlayer() {
	auto listener = EventListenerAcceleration::create([&](Acceleration* acc, Event* event) {
		if (acc->x > 0.5 && !player->isMovingRight && !player->isMovingLeft) {
			player->moveRight();
			player->isMovingLeft = true;
		} else if (acc->x <= -0.5 && !player->isMovingRight && !player->isMovingLeft) {
			player->moveLeft();
			player->isMovingRight = true;
		} else if (acc->x > -0.5 && acc->x < 0.5 && (player->isMovingRight || player->isMovingLeft)){
			player->isMovingLeft = false;
			player->isMovingRight = false;
			player->setHorizontalSpeed(0);
		}
	});
	return listener;
}

EventListenerTouchOneByOne* Controller::controlPlayerJump() {
	auto listener = EventListenerTouchOneByOne::create();

	listener->onTouchBegan = [&](Touch* touch, Event* event) {
		if (player->getSpeed().y == 0) {
			player->jumpFlag = 0;
		}
		if (player->getSpeed().y > 0 && player->jumpFlag == 2) {
			return true;
		} else if (player->jumpFlag < 2){
			player->jumpFlag++;
			player->jump();
		}
		return true;
	};
	return listener;
}
