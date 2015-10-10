#pragma once

#include "cocos2d.h"

USING_NS_CC;

class HelloWorld : public Scene
{
public:
	CREATE_FUNC(HelloWorld);
    virtual bool init();  
    void menuCloseCallback(cocos2d::Ref* pSender);
	void update(float delta);

	Label* l;
	Size visibleSize;
	Point origin;
};
