//
//  GameLost.cpp
//  JXRun
//
//  Created by the 9 on 14-7-5.
//
//

#include "GameLost.h"
#include "MainScene.h"
#include "MenuScene.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;
USING_NS_CC;

Scene* GameLost::scene()
{
    
    auto scene = Scene::create();
    
    auto layer = GameLost::create();
    
    scene->addChild(layer);
    
    return scene;
}

bool GameLost::init()
{
    
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size size = Director::getInstance()->getWinSize();
    
    auto loseSprite = Sprite::create("gameover.png");
    loseSprite->setPosition(Point(size.width/2,size.height/2 + 50));
//    loseSprite->setColor(Color3B::RED);
    MainScene::getMainScene()->addChild(loseSprite);
    
    auto backGame = MenuItemFont::create("Again", CC_CALLBACK_1(GameLost::menuBackGameCallback, this));
    auto backMenu = MenuItemFont::create("Menu", CC_CALLBACK_1(GameLost::menuBackMenuCallback, this));
    
    auto menu = Menu::create(backGame, backMenu, NULL);
    menu->alignItemsHorizontallyWithPadding(50);
    menu->setPosition(Point(size.width/2, size.height/2));
    this->addChild(menu, 100);
    
    return true;
}


void GameLost::menuBackGameCallback(Ref* pSender)
{
    this->removeChildByTag(100);
    this->removeFromParent();
    Director::getInstance()->replaceScene(MainScene::Scene());
    Director::getInstance()->resume();
}

void GameLost::menuBackMenuCallback(Ref* pSender)
{
    SimpleAudioEngine::getInstance()->stopBackgroundMusic();
    Director::getInstance()->resume();
    Director::getInstance()->replaceScene(MenuScene::createScene());
}

