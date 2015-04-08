#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "Player.h"
#include "Swordsman.h"
USING_NS_CC;

class HelloWorld : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
	//void createFloor(int w, int h, Layer* l);
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
	void onEnter();
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

private:
	cocos2d::Sprite* duang;
	float _screenHeight;
	float _screenWidth;
	cocos2d::Size visibleSize;
	cocos2d::PhysicsBody* duangBody;
	Player* player;
	Swordsman* swordsman;


};

#endif // __HELLOWORLD_SCENE_H__
