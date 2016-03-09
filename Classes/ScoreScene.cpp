//
//  ScoreScene.cpp
//  JXRun
//
//  Created by the 9 on 14-7-7.
//
//

#include "ScoreScene.h"
#include "MenuScene.h"
USING_NS_CC;
using namespace std;
Scene* ScoreScene::Scene()
{
    auto scene = Scene::create();
    
    auto layer = ScoreScene::create();
    
    scene->addChild(layer);
    
    return scene;
}

bool ScoreScene::init()
{
    
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size size = Director::getInstance()->getWinSize();
    
    Sprite *bg = Sprite::create("back_1.png");
    bg->setPosition(Point(size.width / 2, size.height / 2));
    this->addChild(bg, 0);
    
    string scoreStr = "";
    string score = UserDefault::getInstance()->getStringForKey("user_score","0").c_str();
    
    if (atoi(score.c_str())!=0) {
        scoreStr+=score;
    }else{
        scoreStr="0";
    }
    
    Label *ttfScore = Label::createWithSystemFont(scoreStr.c_str(), "Helvetica", 23);
    ttfScore->setPosition(Point(size.width/2 -50, size.height/2+40));
    ttfScore->setColor(Color3B(255,0,0));
    this->addChild(ttfScore);
    

    Label *ttback = Label::createWithSystemFont("返回主菜单", "Helvetica", 23);
    ttback->setColor(Color3B(255,255,0));
    MenuItemLabel *menuLabel = MenuItemLabel::create(ttback, CC_CALLBACK_1(ScoreScene::menuBackCallback, this));

    Menu *menu = Menu::create(menuLabel, NULL);
    menu->setPosition(Point(size.width/2, size.height/2-30));
    this->addChild(menu);

    return true;
}

void ScoreScene::menuBackCallback(Ref* pSender)
{
    Director::getInstance()->replaceScene(TransitionPageTurn::create(0.5f, MenuScene::createScene(), true));
}