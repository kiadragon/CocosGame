#include "cocos2d.h"
#include "Controller.h"
#include "Player.h"
#include "HelloWorldScene.h"
#include "AppDelegate.h"
#include <vector>
USING_NS_CC;

EventListenerAcceleration* Controller::controlPlayer() {
	auto listener = EventListenerAcceleration::create([&](Acceleration* acc, Event* event) {
		if (acc->x > 0.5 && !player->isMove) {
			player->moveRight();
			player->isMove = true;
		}
		else if (acc->x <= -0.5 && !player->isMove) {
			player->moveLeft();
			player->isMove = true;
		}
		else if (acc->x > -0.5 && acc->x < 0.5 && player->isMove){
			player->isMove = false;
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
		} else if (player->jumpFlag <= 2){
			CCLOG("jumpflag:%d", player->jumpFlag);
			player->jumpFlag++;
			player->jump();
		}
		return true;
	};
	return listener;
}
