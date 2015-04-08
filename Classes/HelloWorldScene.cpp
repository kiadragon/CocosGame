#include "HelloWorldScene.h"
#include "cocos2d.h"
#include "ui\CocosGUI.h"
#include "Player.h"
#include "Floor.h"
USING_NS_CC;
using namespace ui;

//void createFloor(int w, int h, Layer* l) {
//	auto floor1 = Sprite::create("floor.png");
//	auto floorBody = PhysicsBody::createEdgeBox(floor1->getContentSize(), PHYSICSBODY_MATERIAL_DEFAULT, 3);
//	floorBody->setDynamic(false);
//	floorBody->getShape(0)->setFriction(0);
//	floorBody->getShape(0)->setMass(0);
//	floor1->setPosition(w, h);
//	floor1->setPhysicsBody(floorBody);
//	l->addChild(floor1);
//}

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

void HelloWorld::onEnter() {
	Layer::onEnter();

	//wall
	auto wall = Sprite::create();
	auto wallBody = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);
	wall->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	wall->setPhysicsBody(wallBody);
	this->addChild(wall);

	Floor* f1 = new Floor("floor.png");
	f1->setPosition(_screenWidth / 5, _screenHeight / 4);
	Floor* f2 = new Floor("floor.png", _screenWidth * 4 / 5, _screenHeight / 4);
	Floor* f3 = new Floor("floor.png", _screenWidth / 2, _screenHeight / 2);
	this->addChild(f1->getSprite());
	this->addChild(f2->getSprite());
	this->addChild(f3->getSprite());
	//duang = Sprite::create("duang.png");
	//duangBody = PhysicsBody::createBox(duang->getContentSize(), PHYSICSBODY_MATERIAL_DEFAULT, Point::ZERO);
	//duangBody->setDynamic(true);
	//duangBody->getShape(0)->setRestitution(0);
	//duangBody->getShape(0)->setFriction(0);
	////duangBody->getShape(0)->setMass(0);
	//duang->setPhysicsBody(duangBody);
	//duang->setPosition(_screenWidth/4, _screenHeight*2/3);

	player = new Player("duang.png");
	player->setPosition(_screenWidth / 4, _screenHeight * 2 / 3);
	this->addChild(player->getSprite());

	swordsman = new Swordsman("Swordsman");
	swordsman->setPosition(_screenWidth * 3 / 4, _screenHeight * 2 / 3);
	this->addChild(swordsman->getSprite());

	auto gameListener = EventListenerTouchOneByOne::create();
	gameListener->onTouchBegan = [&](Touch* touch, Event* event) {
		auto target = event->getCurrentTarget();
		Vec2 location = touch->getLocation();
		Vec2 locationInNode = target->convertToNodeSpace(location);
		if ((int)locationInNode.x > _screenWidth / 2) {
			swordsman->moveRight();
		} else if ((int)locationInNode.x < _screenWidth / 2) {
			swordsman->moveLeft();
		}
		return true;
	};

	//gameListener->onTouchEnded = [&](Touch* touch, Event* event) {
	//	Vec2 tempV = duangBody->getVelocity();
	//	tempV.x = 0;
	//	duangBody->setVelocity(tempV);
	//};

	
	//auto JumpListener = EventListenerTouchOneByOne::create();
	//JumpListener->onTouchBegan = [&](Touch* touch, Event* event) {
	//	auto target = event->getCurrentTarget();
	//	tempLocation = touch->getLocation();
	//	return true;
	//};

	//JumpListener->onTouchEnded = [&](Touch* touch, Event* event) {
	//	auto target = event->getCurrentTarget();
	//	Vec2 location = touch->getLocation();
	//	if (location.y > tempLocation.y) {
	//		duangBody->setVelocity(duangBody->getVelocity() + Vec2(0, 200));
	//	}
	//};

	//gameListener->onTouchMoved = [&](Touch* touch, Event* event) {
	//	CCLOG("www");
	//	duangBody->setVelocity(Vec2(200, 0));
	//};

	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(gameListener, this);

	auto jumpButton = Button::create("up.png");

	jumpButton->setPosition(Point(_screenWidth*6/7, _screenHeight*6/7));
	jumpButton->addTouchEventListener([&](Ref* psender, Widget::TouchEventType type) {
		if (type == Widget::TouchEventType::ENDED) {
			swordsman->jump();
		}
		//cclog("upupupup!!");
	});
	this->addChild(jumpButton);
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

