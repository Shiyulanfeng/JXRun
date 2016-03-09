//
//  MenuScene.cpp
//  JXRun
//
//  Created by The9 on 14-6-27.
//
//

#include "MenuScene.h"
#include "MainScene.h"
#include "AboutScene.h"
#include "ScoreScene.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;
USING_NS_CC;
static bool isSound = true;
Scene* MenuScene::createScene()
{
    auto scene = Scene::create();
    
    auto layer = MenuScene::create();
    
    scene->addChild(layer);
    
    return scene;
}

bool MenuScene::init()
{
    
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    //菜单背景
    Sprite *bg = Sprite::create("MainMenu.png");
    bg->setScale(0.5);
    bg->setPosition(Point(visibleSize.width/2, visibleSize.height/2));
    this->addChild(bg, 0);
    //开始按钮
    auto newGameItem = MenuItemImage::create("newgameA.png","newgameB.png",CC_CALLBACK_1(MenuScene::menuNewGameCallback, this));
    newGameItem->setPosition(Point(visibleSize.width / 2 + 40, visibleSize.height / 2 - 20));

    auto aboutItem = MenuItemImage::create("aboutA.png","aboutB.png",CC_CALLBACK_1(MenuScene::menuAboutCallback, this));
    aboutItem->setPosition(Point(visibleSize.width / 2 + 40, visibleSize.height/2 - 60));
    //分数
    auto scoreItem = MenuItemImage::create("score.png","score.png",CC_CALLBACK_1(MenuScene::menuScoreCallback, this));
    scoreItem->setPosition(Point(visibleSize.width / 2 + 40, visibleSize.height/2 - 100));
    //声音按钮
    soundItem = MenuItemImage::create("sound-on-A.png","sound-on-B.png",CC_CALLBACK_1(MenuScene::menuSoundCallback, this));
    soundItem->setPosition(Point(40, 40));
    
    auto menu = Menu::create(newGameItem,aboutItem,scoreItem,soundItem, NULL);
    menu->setPosition(Point(0, 0));
    this->addChild(menu, 1);
    
    SimpleAudioEngine::getInstance()->preloadBackgroundMusic("background.mp3");
    SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(0.5);
    SimpleAudioEngine::getInstance()->playBackgroundMusic("background.mp3");
    isSound = true;
    
    return true;
}

void MenuScene::menuNewGameCallback(Ref* pSender)
{
    Director::getInstance()->replaceScene(TransitionPageTurn::create(0.5, MainScene::Scene(), false));
}

void MenuScene::menuAboutCallback(Ref* pSender)
{
    Director::getInstance()->replaceScene(TransitionPageTurn::create(0.5, AboutScene::Scene(), false));
}

void MenuScene::menuScoreCallback(Ref* pSender)
{
    Director::getInstance()->replaceScene(TransitionPageTurn::create(0.5, ScoreScene::Scene(), false));
}

void MenuScene::menuSoundCallback(Ref* pSender)
{
    if (!isSound) {
        soundItem->setNormalImage(Sprite::create("sound-on-A.png"));
        soundItem->setDisabledImage(Sprite::create("sound-on-B.png"));
        SimpleAudioEngine::getInstance()->playBackgroundMusic("background.mp3",true);
        isSound = true;
    }else{
        soundItem->setNormalImage(Sprite::create("sound-off-A.png"));
        soundItem->setDisabledImage(Sprite::create("sound-off-B.png"));
        SimpleAudioEngine::getInstance()->stopBackgroundMusic();
        isSound = false;
    }
}

bool MenuScene::getSound()
{
    return isSound;
}

