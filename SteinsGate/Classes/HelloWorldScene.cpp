#include "HelloWorldScene.h"

USING_NS_CC;

bool HelloWorld::init()
{
    if ( !Scene::init() )
        return false;
    
    visibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();

    auto closeItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    closeItem->setAnchorPoint(Point::ANCHOR_BOTTOM_RIGHT);
	closeItem->setPosition(Point(origin.x + visibleSize.width, origin.y));

    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);

	this->scheduleUpdate();
    
    return true;
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

void HelloWorld::update(float delta)
{
	time_t now;  
	struct tm *w;
	time(&now);  
	w=localtime(&now);
	int s = w->tm_sec;
	int m = w->tm_min;
	int h = w->tm_hour;

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	SYSTEMTIME stime;  
	GetLocalTime(&stime);
	s = stime.wSecond;
	m = stime.wMinute;
	h = stime.wHour;
#endif

	this->removeChild(l);
	char text[32];
	sprintf(text, "%02d.%02d.%02d", h, m, s);
	l = Label::createWithBMFont("fonts/sg.fnt", text);
	l->setAnchorPoint(Point::ANCHOR_MIDDLE);
	l->setPosition(Point(origin.x + visibleSize.width/2, origin.y + visibleSize.height*0.7));
	l->setScale(visibleSize.height*0.15/l->getBoundingBox().size.height);
	addChild(l, 9999);
}