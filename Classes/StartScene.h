#ifndef _START_SCENE_H_
#define _START_SCENE_H_

#include <cocos2d.h>
#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace ui;

class StartScene : public Scene {
public:
	static cocos2d::Scene* createScene();
	virtual bool init();

	void StartGameCallBack(Ref *pSender, Widget::TouchEventType type);
	void SettingCallBack(Ref *pSender, Widget::TouchEventType type);
	void CloseGameCallBack(Ref *pSender, Widget::TouchEventType type);

	void menuStartCallback(cocos2d::Ref* pSender);
	void menuExitCallback(cocos2d::Ref* pSender);
	void menuHelpCallback(cocos2d::Ref* pSender);
	void menuSetCallback(cocos2d::Ref* pSender);
	void menuMoreCallback(cocos2d::Ref* pSender);
	CREATE_FUNC(StartScene);
};

#endif