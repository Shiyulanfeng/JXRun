//
//  AboutScene.cpp
//  JXRun
//
//  Created by The9 on 14-6-27.
//
//

#include "AboutScene.h"
#include "MenuScene.h"
USING_NS_CC;

Scene* AboutScene::Scene()
{
    auto scene = Scene::create();
    
    auto layer = AboutScene::create();
    
    scene->addChild(layer);
    
    return scene;
}

bool AboutScene::init()
{
    
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    Sprite *bg = Sprite::create("back_1.png");
    bg->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
    this->addChild(bg, 0);
    
    Sprite *kuang = Sprite::create("tb.png");
    kuang->setScale(0.5f);
    kuang->setRotation(90);
    kuang->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
    this->addChild(kuang, 2);
    
    char inf[400];
    sprintf(inf, "name:loli run\n\n program:shuoquan man\n\n art design:zuyi li\n\n company:hz books\n\n powered by cocos2D-x");
    auto myLabel = LabelTTF::create(inf, "Marker Felt", 20);
    myLabel->setAnchorPoint(Point(0, 0));
    myLabel->setColor(Color3B(0, 0, 0));
    myLabel->setDimensions(Size(480, 320));//设置label标签所显示的区域大小
    myLabel->setPosition(Point(0, -50));
    this->addChild(myLabel);
    //关于标签
    Sprite *aboutTitle = Sprite::create("about.png");
    aboutTitle->setScale(0.5f);
    aboutTitle->setPosition(Point(visibleSize.width / 2, visibleSize.height - 20));
    this->addChild(aboutTitle, 3);
    //返回
    auto backItem = MenuItemImage::create("backA.png","backB.png",CC_CALLBACK_1(AboutScene::menuBackCallback, this));
    backItem->setScale(0.5);
    backItem->setPosition(Point(visibleSize.width - 20, visibleSize.height - 20));
    
    auto menu = Menu::create(backItem, NULL);
    menu->setPosition(Point(0, 0));
    this->addChild(menu, 3);
    
    return true;
}

void AboutScene::menuBackCallback(Ref* pSender)
{
    Director::getInstance()->replaceScene(TransitionPageTurn::create(0.5f, MenuScene::createScene(), true));
}

