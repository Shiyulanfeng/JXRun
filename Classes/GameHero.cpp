//
//  GameHero.cpp
//  JXRun
//
//  Created by The9 on 14-6-27.
//
//

#include "GameHero.h"
#include "MainScene.h"
#include "MenuScene.h"

GameHero* GameHero::createHero()
{
    GameHero *ret = new GameHero();
    if (ret && ret->init())
    {
        ret->initHero();
        ret->autorelease();
        return ret;
    }
    else
    {
        CC_SAFE_DELETE(ret);
        return nullptr;
    }

}

bool GameHero::initHero()
{
    Size size = Director::getInstance()->getWinSize();
    
    score = 0;
    runLength = 0.f;
    
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    frameCache->addSpriteFramesWithFile("luoli1.plist");
    this->initWithSpriteFrameName("s_1.png");
    
    Vector<SpriteFrame*> animFramesArray;
    for (int i = 1; i < 9; ++i) {
        char name[64];
        sprintf(name, "s_%d.png", i);
        SpriteFrame *frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(name);
        animFramesArray.pushBack(frame);
    }
    Animation *animation = Animation::createWithSpriteFrames(animFramesArray, 0.1f);
    Animate *animate = Animate::create(animation);
    RepeatForever *repeat = RepeatForever::create(animate);
    this->runAction(repeat);
    
    
    auto scoreLabel = Label::createWithSystemFont("分数:", "HelVetica-Blod", 24);
    scoreLabel->setPosition(Point(size.width- 150, size.height - 20));
    MainScene::getMainScene()->addChild(scoreLabel);
     
    
    //debuging

    string strScore = Convert2String(score);
    Label *scoreInLabel = Label::createWithSystemFont(strScore, "HelVetica-Blod", 24);
    scoreInLabel->setPosition(Point(size.width-100, size.height-20));
    scoreInLabel->setColor(Color3B(255, 255, 0));
    MainScene::getMainScene()->addChild(scoreInLabel, 10, 11);

    
    auto runLabel = Label::createWithSystemFont("距离:", "HelVetica-Blod", 24);
    runLabel->setPosition(Point(size.width - 150, size.height - 50));
    MainScene::getMainScene()->addChild(runLabel);
    
    string strLengthCount = Convert2String(runLength);
    strLengthCount += "/300";
    auto lengthInLabel = Label::createWithSystemFont(strLengthCount.c_str(), "HelVetica-Blod", 24);
    lengthInLabel->setPosition(Point(size.width - 80, size.height- 50));
    lengthInLabel->setColor(Color3B::RED);
    MainScene::getMainScene()->addChild(lengthInLabel, 10, 12);
    
    this->scheduleUpdate();
    
    return true;
}

void GameHero::update(float dt)
{
    count++;
    if (count>= 10) {
        this->addLength(1);
        count = 0;
    }
    Point pos = MainScene::getMainScene()->getHero()->getPosition();
    if (pos.x < - this->getContentSize().width || pos.y < - this->getContentSize().height) {
        isDead = true;
    }
    if (isDead) {
        MainScene::getMainScene()->lostGame();
        this->unscheduleUpdate();
    }
}

void GameHero::addScore(float _value)
{
    score += _value;
    string strScore =  Convert2String(score);
    Label *temp = (Label*)MainScene::getMainScene()->getChildByTag(11);
    temp->setString(strScore);
    
    if (runLength>= 299) {
        int oleScore = atoi(UserDefault::getInstance()->getStringForKey("user_score","0").c_str());
        if (score>=oleScore) {
            UserDefault::getInstance()->setStringForKey("user_score", Convert2String(score));
            UserDefault::getInstance()->flush();
        }
    }
}

void GameHero::addLength(float _value)
{
    runLength += _value;
    string strLength = Convert2String(runLength);
    strLength += "/300";
    
    Label *temp = (Label*)MainScene::getMainScene()->getChildByTag(12);
    temp->setString(strLength);
    
    if (isDead) {
        int oldLength = atoi(UserDefault::getInstance()->getStringForKey("user_length","0").c_str());
        if (runLength>oldLength) {
            UserDefault::getInstance()->setStringForKey("user_length", Convert2String(runLength));
            UserDefault::getInstance()->flush();
        }
    }
    if (runLength> 299) {
        MainScene::getMainScene()->winGame();
        this->unscheduleUpdate();
    }
}

