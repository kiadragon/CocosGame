#include "HelloWorldScene.h"
#include "cocos2d.h"
#include "ui\CocosGUI.h"
#include "Player.h"
#include "Floor.h"
#include "Controller.h"
#include "MapReader.h"
#include "ControlSwordsman.h"
#include "Fireball.h"
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
	//CCLOG("FIRST:%lf   %lf", _screenWidth, _screenHeight);


 //   Vec2 origin = Director::getInstance()->getVisibleOrigin();

 //   /////////////////////////////
 //   // 2. add a menu item with "X" image, which is clicked to quit the program
 //   //    you may modify it.

 //   // add a "close" icon to exit the progress. it's an autorelease object
 //   auto closeItem = MenuItemImage::create(
 //                                          "CloseNormal.png",
 //                                          "CloseSelected.png",
 //                                          CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
 //   
	//closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
 //                               origin.y + closeItem->getContentSize().height/2));

 //   // create menu, it's an autorelease object
 //   auto menu = Menu::create(closeItem, NULL);
 //   menu->setPosition(Vec2::ZERO);
 //   this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...



    return true;
}

void HelloWorld::updateSwordsman(float s) {
	_controlSwordsman->SwordsmanAI(player->jumpFlag, player->isMovingLeft, player->isMovingRight, player->getSprite()->getPosition());
}

void HelloWorld::onEnter() {
	Layer::onEnter();

	// map
	// new Map and set Scale
	auto mapReader = new MapReader("forest",1.5);
	this->addChild(mapReader->getBackground());
	this->addChild(mapReader->getMap());
	//wall
	auto wall = Sprite::create();
	auto wallBody = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);
	wall->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	wall->setPhysicsBody(wallBody);
	this->addChild(wall);
	Array* floorArray = mapReader->getFloorArray();
	for (int i = 0; i < floorArray->count(); i++) {
		Floor *floor = (Floor*)floorArray->getObjectAtIndex(i);
		this->addChild(floor->getSprite());
	}

	player = new Player("duang.png");
	player->setPosition(_screenWidth / 4, _screenHeight * 2 / 3);
	this->addChild(player->getSprite());

	auto controller = new Controller(player);
	auto gameListener = controller->controlPlayer();
	auto jumpListener = controller->controlPlayerJump();
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(gameListener, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(jumpListener, 1);

	swordsman = new Swordsman("Swordsman");
	swordsman->setPosition(_screenWidth * 3 / 4, _screenHeight * 2 / 3);
	this->addChild(swordsman->getSprite());
	
	_controlSwordsman = new ControlSwordsman(swordsman);
	schedule(schedule_selector(HelloWorld::updateSwordsman), 0.5);

	Fireball* fireball = new Fireball("right", _screenWidth / 10, _screenHeight * 2 / 3);
	this->addChild(fireball->getSprite());
	Fireball* fireball1 = new Fireball("right", _screenWidth / 2, _screenHeight * 2 / 3);
	this->addChild(fireball1->getSprite());
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

