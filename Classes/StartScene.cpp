#include "HelloWorldScene.h"
#include "StartScene.h"
#include "SetScene.h"
#include "HelpScene.h"
#include "MoreScene.h"

Scene* StartScene::createScene()
{
	auto scene = Scene::create();
	auto Layer = StartScene::create();
	scene->addChild(Layer);

	return scene;
}

bool StartScene::init()
{
	bool ret = false;

	// Vec2 origin = Director::getInstance()->getVisibleOrigin();

	do {
		Size visibleSize = Director::getInstance()->getVisibleSize();
		auto background = Sprite::create("background.png");
		addChild(background);
		background->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
		background->setScale(visibleSize.width, visibleSize.height);
		// 创建开始按钮
		auto startItem = MenuItemImage::create(
			"startNormal.png",
			"startSelected.png",
			CC_CALLBACK_1(StartScene::menuStartCallback, this));

		auto exitItem = MenuItemImage::create(
			"exitNormal.png",
			"exitSelected.png",
			CC_CALLBACK_1(StartScene::menuExitCallback, this));

		auto helpItem = MenuItemImage::create(
			"helpNormal.png",
			"helpSelected.png",
			CC_CALLBACK_1(StartScene::menuHelpCallback, this));

		auto setItem = MenuItemImage::create(
			"setNormal.png",
			"setSelected.png",
			CC_CALLBACK_1(StartScene::menuSetCallback,this));

		auto moreItem = MenuItemImage::create(
			"moreNormal.png",
			"moreSelected.png",
			CC_CALLBACK_1(StartScene::menuMoreCallback, this)
			);

		startItem->setPosition(Vec2(visibleSize.width / 2, visibleSize.height*0.85));
		exitItem->setPosition(Vec2(visibleSize.width / 2, visibleSize.height*0.55));
		setItem->setPosition(Vec2(visibleSize.width / 2, visibleSize.height*0.75));
		helpItem->setPosition(Vec2(visibleSize.width / 2, visibleSize.height*0.65));
		moreItem->setPosition(Vec2(visibleSize.width / 2, visibleSize.height*0.45));
		
		
		auto menu = Menu::create(startItem,exitItem,setItem,helpItem,moreItem,NULL);
		menu->setPosition(Point::ZERO);
		addChild(menu, 1);
		ret = true;

	} while (0);

	return ret;
}

void StartScene::menuStartCallback(Ref* pSender)
{
	// 创建场景
	auto scene = HelloWorld::createScene();

	// 切换场景
	Director::getInstance()->pushScene(scene);
}

void StartScene::menuExitCallback(Ref* pSender)
{
	Director::getInstance()->end();
}

void StartScene::menuHelpCallback(Ref* pSender)
{
	auto scene = HelpScene::createScene();
	Director::getInstance()->pushScene(scene);
}

void StartScene::menuSetCallback(Ref* pSender)
{
	auto scene = SetScene::createScene();
	Director::getInstance()->pushScene(scene);
}

void StartScene::menuMoreCallback(Ref* pSender)
{
	auto scene = MoreScene::createScene();
	Director::getInstance()->pushScene(scene);
}