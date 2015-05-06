#include "HelloWorldScene.h"
#include "cocos2d.h"
#include "ui\CocosGUI.h"
#include "Player.h"
#include "Floor.h"
#include "Controller.h"
#include "MapReader.h"
#include "ControlSwordsman.h"
#include "Fireball.h"
#include "GamePause.h"

USING_NS_CC;
using namespace ui;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
	auto scene = Scene::createWithPhysics();
	scene->getPhysicsWorld()->setGravity(Vec2(0, -1000.0f));
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    // 'layer' is an autorelease object
	auto layer = HelloWorld::create();
    // add layer as a child to scene
    scene->addChild(layer);
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() ) {
        return false;
    }
	Device::setAccelerometerEnabled(true);
    visibleSize = Director::getInstance()->getVisibleSize();
	_screenWidth = visibleSize.width;
	_screenHeight = visibleSize.height;
	gameTime = 30;

    Vec2 origin = Director::getInstance()->getVisibleOrigin();

 //   /////////////////////////////
 //   // 2. add a menu item with "X" image, which is clicked to quit the program
 //   //    you may modify it.

	auto pauseItem = MenuItemImage::create(
		"continueNormal.png",
		"continueSelected.png",
		CC_CALLBACK_1(HelloWorld::menuPauseCallback, this));
	pauseItem->setPosition(Vec2(pauseItem->getContentSize().width , _screenHeight - pauseItem->getContentSize().height));

    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
	closeItem->setPosition(Vec2(closeItem->getContentSize().width + pauseItem->getContentSize().width,
		_screenHeight - closeItem->getContentSize().height));

	// create menu, it's an autorelease object
	auto menu = Menu::create(pauseItem, closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	// map
	// new Map and set Scale
	mapReader = new MapReader("forest", 1);
	_tileMap = mapReader->getMap();

	//set background and border
	mapReader->getBackground()->setPosition(mapReader->getBackground()->getContentSize().width / 2, mapReader->getBackground()->getContentSize().height / 2);
	auto wallBody = PhysicsBody::createEdgeBox(mapReader->getBackground()->getContentSize(), PHYSICSBODY_MATERIAL_DEFAULT, 10);
	wallBody->getShape(0)->setRestitution(0);
	mapReader->getBackground()->setPhysicsBody(wallBody);
	this->addChild(mapReader->getBackground());

	Array* floorArray = mapReader->getFloorArray();
	for (int i = 0; i < floorArray->count(); i++) {
		Floor *floor = (Floor*)floorArray->getObjectAtIndex(i);
		this->addChild(floor->getSprite());
	}

	player = new Player("duang.png");
	player->setPosition(_screenWidth / 4, _screenHeight * 2 / 3);
	this->addChild(player->getSprite());

	controller = new Controller(player);
	auto jumpListener = controller->controlPlayerJump();
	Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(jumpListener, 1);

	//control left or right
	this->addChild(controller->getRightBtn());
	this->addChild(controller->getLeftBtn());

	swordsman = new Swordsman("Swordsman");
	swordsman->setPosition(_screenWidth * 3 / 4, _screenHeight * 2 / 3);
	this->addChild(swordsman->getSprite());

	_controlSwordsman = new ControlSwordsman(swordsman);
	schedule(schedule_selector(HelloWorld::updateSwordsman), 0.5);
	schedule(schedule_selector(HelloWorld::update));

	Fireball* fireball = new Fireball("right", _screenWidth / 10, _screenHeight * 2 / 3);
	this->addChild(fireball->getSprite());
	Fireball* fireball1 = new Fireball("right", _screenWidth / 2, _screenHeight * 2 / 3);
	this->addChild(fireball1->getSprite());

	CountTime = LabelTTF::create(gameTime.asString(), "Arial", 40);
	CountTime->setColor(Color3B(255, 0, 0));
	CountTime->setPosition(_screenWidth* 0.9, _screenHeight * 0.93);
	this->addChild(CountTime);

    return true;
}

void HelloWorld::updateSwordsman(float s) {
	_controlSwordsman->SwordsmanAI(player->jumpFlag, player->isMovingLeft,
		player->isMovingRight, player->getSprite()->getPosition());
}

void HelloWorld::update(float s) {
	if (player->isMovingLeft) {
		player->setHorizontalSpeed(-200);
	}
	else if (player->isMovingRight) {
		player->setHorizontalSpeed(200);
	}
}

void HelloWorld::updatePerSecond(float s) {
	gameTime = gameTime.asInt() - 1;
	CountTime->setString(gameTime.asString());
}

void HelloWorld::onEnter() {
	Layer::onEnter();
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void HelloWorld::menuPauseCallback(CCObject* pSender)
{  
	RenderTexture *renderTexture = RenderTexture::create(_screenWidth, _screenHeight);

	renderTexture->begin();
	this->getParent()->visit();
	renderTexture->end();

	Director::sharedDirector()->pushScene(GamePause::scene(renderTexture));
}

