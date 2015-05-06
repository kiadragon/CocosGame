#ifndef __GAMEPAUSE_H__
#define __GAMEPAUSE_H__

#include "cocos2d.h"

USING_NS_CC;

class GamePause : public Layer {
public:
	virtual bool init();
	static Scene* scene(RenderTexture* sqr);
	CREATE_FUNC(GamePause);
	void menuContinueCallback(Object* pSender);
};

#endif