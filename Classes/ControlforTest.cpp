#include "cocos2d.h"
#include "ControlforTest.h"

#if(CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#include <windows.h>
#define KEY_DOWN(vk_code) (GetAsyncKeyState(vk_code) & 0x8000 ? 1 : 0)
#define KEY_UP(vk_code) (GetAsyncKeyState(vk_code) & 0x8000 ? 0 : 1)
#endif

USING_NS_CC;

EventListenerTouchOneByOne* ControlforTest::controlPlayer() {
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = [&](Touch* touch, Event* event) {
		Size visibleSize = Director::getInstance()->getVisibleSize();
		float x = visibleSize.width / 2;
		float y = visibleSize.height;
		Vec2 location = touch->getLocationInView();

		if (location.x >= x) {
			player->getPhysicsBody()->setVelocity(player->getPhysicsBody()->getVelocity() + Vec2(200, 0));
		}
		else if (location.x < x) {
			player->getPhysicsBody()->setVelocity(player->getPhysicsBody()->getVelocity() + Vec2(-200, 0));
		}
		return true;
	};

	listener->onTouchEnded = [&](Touch* touch, Event* event) {
		Vec2 tempV = player->getPhysicsBody()->getVelocity();
		tempV.x = 0;
		player->getPhysicsBody()->setVelocity(tempV);
	};
	return listener;
}

Button* ControlforTest::getButton() {
	float x = Director::getInstance()->getVisibleSize().width;
	float y = Director::getInstance()->getVisibleSize().height;
	_button = Button::create("CloseSelected.png");
	_button->setPosition(Point(x * 6 / 7, y * 3 / 7));
	_button->addTouchEventListener([&](Ref* pSender, Widget::TouchEventType type) {
		if (type == Widget::TouchEventType::ENDED) {
			player->getPhysicsBody()->setVelocity(player->getPhysicsBody()->getVelocity() + Vec2(0, 400));
		}
	});
	return _button;
}