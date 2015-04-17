#include <cocos2d.h>
#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace ui;

class SetScene : public Scene {
public:
	static cocos2d::Scene* createScene();
	virtual bool init();

	void menuReturnCallback(cocos2d::Ref* pSender);
	CREATE_FUNC(SetScene);


};