#include "MoreScene.h"

Scene* MoreScene::createScene()
{
	auto scene = Scene::create();
	auto Layer = MoreScene::create();
	scene->addChild(Layer);
	return scene;
}

bool MoreScene::init()
{
	bool ret = false;
	Size size = Director::getInstance()->getVisibleSize();
	// Vec2 origin = Director::getInstance()->getVisibleOrigin();

	do {
		Size visibleSize = Director::getInstance()->getVisibleSize();
		auto background = Sprite::create("background.png");
		addChild(background);
		background->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
		background->setScale(visibleSize.width, visibleSize.height);
		auto returnItem = MenuItemImage::create(
			"returnNormal.png",
			"returnSelected.png",
			CC_CALLBACK_1(MoreScene::menuReturnCallback, this)
			);

		returnItem->setPosition(Vec2(size.width - returnItem->getContentSize().width, returnItem->getContentSize().height / 2));

		auto menu = Menu::create(returnItem, NULL);
		menu->setPosition(Point::ZERO);
		addChild(menu, 1);
		ret = true;

	} while (0);

	return ret;
}

void MoreScene::menuReturnCallback(Ref* pSender)
{
	Director::getInstance()->popScene();
}