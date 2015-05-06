#include "GamePause.h"

Scene* GamePause::scene(RenderTexture* sqr)
{
	Scene *scene = Scene::create();
	GamePause *layer = GamePause::create();
	scene->addChild(layer, 1);

	Size visibleSize = Director::sharedDirector()->getVisibleSize();
	Sprite *back_spr = Sprite::createWithTexture(sqr->getSprite()->getTexture());
	back_spr->setPosition(ccp(visibleSize.width / 2, visibleSize.height / 2));  
	back_spr->setFlipY(true);
	scene->addChild(back_spr);
	return scene;
}

bool GamePause::init()
{
	if (!Layer::init()){
		return false;
	}

	Size visibleSize = Director::sharedDirector()->getVisibleSize();
	Point origin = Director::sharedDirector()->getVisibleOrigin();

	MenuItemImage *pContinueItem = MenuItemImage::create(
		"continueNormal.png",
		"continueNormal.png",
		this, menu_selector(GamePause::menuContinueCallback));

	pContinueItem->setPosition(ccp(visibleSize.width / 2, visibleSize.height / 2 + 30));
	Menu* pMenu = Menu::create(pContinueItem, NULL);
	pMenu->setPosition(Point::ZERO);
	this->addChild(pMenu, 2);

	return true;
}

void GamePause::menuContinueCallback(Object* pSender)
{
	Director::sharedDirector()->popScene();
}