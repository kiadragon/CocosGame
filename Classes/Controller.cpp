#include "cocos2d.h"
#include "Controller.h"
#include "Player.h"
#include "HelloWorldScene.h"
#include "AppDelegate.h"

USING_NS_CC;

Button* Controller::getLeftBtn() {
	leftBtn = Button::create("left_arrow-128.png");
	leftBtn->setScale(0.6);
	leftBtn->addTouchEventListener([&](Ref* pSender, Widget::TouchEventType type) {
		if (type == Widget::TouchEventType::BEGAN) {
			player->moveLeft();
			player->isMovingLeft = true;
		}
		if (type == Widget::TouchEventType::ENDED || type == Widget::TouchEventType::CANCELED) {
			player->setHorizontalSpeed(0);
			player->isMovingLeft = false;
		}
	});
	Size s = Director::getInstance()->getVisibleSize();
	leftBtn->setPosition(Vec2(s.width / 10, s.height / 9));

	return leftBtn;
}

Button* Controller::getRightBtn() {
	rightBtn = Button::create("right_arrow-128.png");
	rightBtn->setScale(0.6);
	rightBtn->addTouchEventListener([&](Ref* pSender, Widget::TouchEventType type) {
		if (type == Widget::TouchEventType::BEGAN) {
			player->moveRight();
			player->isMovingRight = true;
		}
		if (type == Widget::TouchEventType::ENDED || type == Widget::TouchEventType::CANCELED) {
			player->setHorizontalSpeed(0);
			player->isMovingRight = false;
		}
	});
	Size s = Director::getInstance()->getVisibleSize();
	rightBtn->setPosition(Vec2(s.width / 5, s.height / 9));

	return rightBtn;
}

EventListenerTouchOneByOne* Controller::controlPlayerJump() {
	auto listener = EventListenerTouchOneByOne::create();

	listener->onTouchBegan = [&](Touch* touch, Event* event) {
		if (player->getSpeed().y < 0.1 && player->getSpeed().y > -0.1) {
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
