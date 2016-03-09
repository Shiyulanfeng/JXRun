//
//  GameWin.cpp
//  JXRun
//
//  Created by the 9 on 14-7-5.
//
//

#include "GameWin.h"
#include "MainScene.h"
#include "MenuScene.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;
USING_NS_CC;

Scene* GameWin::scene()
{

    auto scene = Scene::create();
    
    auto layer = GameWin::create();
    
    scene->addChild(layer);
    
    return scene;
}

bool GameWin::init()
{

    if ( !Layer::init() )
    {
        return false;
    }
    
    Size size = Director::getInstance()->getVisibleSize();
 
    auto WinLabel = LabelTTF::create("You Win", "Arial", 40);
    WinLabel->setPosition(Point(size.width/2,size.height/2 + 40));
    WinLabel->setColor(Color3B::RED);
    MainScene::getMainScene()->addChild(WinLabel);
    
    auto backGame = MenuItemFont::create("Again", CC_CALLBACK_1(GameWin::menuBackGameCallback, this));
    auto backMenu = MenuItemFont::create("Menu", CC_CALLBACK_1(GameWin::menuBackMenuCallback, this));
    
    auto menu = Menu::create(backGame, backMenu, NULL);
    menu->alignItemsHorizontallyWithPadding(50);
    menu->setPosition(Point(size.width/2, size.height/2));
    this->addChild(menu, 100);
    
    return true;
}


void GameWin::menuBackGameCallback(Ref* pSender)
{
    this->removeChildByTag(100);
    this->removeFromParent();
    Director::getInstance()->replaceScene(MainScene::Scene());
    Director::getInstance()->resume();
}

void GameWin::menuBackMenuCallback(Ref* pSender)
{
    SimpleAudioEngine::getInstance()->stopBackgroundMusic();
    Director::getInstance()->resume();
    Director::getInstance()->replaceScene(MenuScene::createScene());
}

