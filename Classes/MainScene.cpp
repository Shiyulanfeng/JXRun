//
//  MainScene.cpp
//  JXRun
//
//  Created by The9 on 14-6-27.
//
//

#include "MainScene.h"
#include "GameFloor.h"
#include "GameLost.h"
#include "GameWin.h"
#include "MenuScene.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;
USING_NS_CC;

static MainScene *mainScene = NULL;
Scene* MainScene::Scene()
{
    auto scene = Scene::create();
    
    auto layer = MainScene::create();
    
    scene->addChild(layer);
    
    return scene;
}

bool MainScene::init()
{
    
    if ( !Layer::init() )
    {
        return false;
    }
    
    winSize = Director::getInstance()->getWinSize();
    mainScene = this;
    
    floorCount = 16;
    
    forceX = 300;
    forceY = 30;
    
    xSpeed = 5;
    ySpeed = 30;
    
    speedFix = 0.01;
    
    constXspeed = xSpeed;
    constYspeed = ySpeed;
    
    isJump = false;
    isCollistionWithStar = false;
    isPlaySound = MenuScene::getSound();
    accelerate = 0.94;
    
    GameMap *sky =GameMap::createMap("back_1.png");
    this->addChild(sky, 0);
    GameMap *map =GameMap::createMap("back_5.png");
    this->addChild(map, 0);
    
    hero = GameHero::createHero();
    SpriteBatchNode *batchNode = SpriteBatchNode::create("luoli1.png");
    batchNode->addChild(hero, 3);
    HeroWidth = hero->getContentSize().width;
    HeroHeight = hero->getContentSize().height;
    this->addChild(batchNode,3);
    
    hero->setPosition(Point(-20, winSize.height/2 ));
    MoveBy *moveBy = MoveBy::create(1, Point(80, 0));
    hero->runAction(moveBy);
    
    GameFloor *floor = GameFloor::create();
    floorWidth = floor->getContentSize().width;
    floorHeight = floor->getContentSize().height;
    
    SimpleAudioEngine::getInstance()->preloadBackgroundMusic("background.mp3");
    SimpleAudioEngine::getInstance()->preloadEffect("gold.caf");
    if (isPlaySound) {
        SimpleAudioEngine::getInstance()->playBackgroundMusic("background.mp3");
    }
    
    this->initFloorsAndStars();
    
    this->scheduleUpdate();
    
    return true;
}

void MainScene::initFloorsAndStars()
{
    int num = 0;
    int count = 0;
    
    isFrontBlank = false;
    
    for (int i = 0; i < floorCount; i++) {
        GameFloor *floor = GameFloor::createFloor();
        this->addChild(floor);
        floorArray.pushBack(floor);
        
        GameStar *star = GameStar::createStar();
        this->addChild(star);
        starArray.pushBack(star);
    }
    while (num < floorCount) {
        count++;
        if (num < floorCount/2) {
            floorArray.at(num)->setPosition(Point(count*35, winSize.height/2 - 100));
            GameFloor *floortemp = floorArray.at(num);
            
            starArray.at(num)->setPosition(Point(count*35, floortemp->getPositionY() + 80));
            num++;
        }else{
            randomNum = this->getRandomNumber(0, 2);
            if (randomNum == 0) {
                isFrontBlank = true;
                continue;
            }
            if (isFrontBlank) {
                floorArray.at(num)->setPosition(Point(count*35, this->getRandomNumber(winSize.height/2 - 100, 180)));
                float y =floorArray.at(num)->getPositionY() + this->getRandomNumber(50, 150);
                starArray.at(num)->setPosition(Point(count*35, y));
                isFrontBlank = false;
            }else{
                floorArray.at(num)->setPosition(Point(count*35, floorArray.at(num - 1)->getPositionY()));
                float y = floorArray.at(num)->getPositionY() + this->getRandomNumber(50, 150);
                starArray.at(num)->setPosition(Point(count*35, y));
            }
            num++;
        }
    }
}

void MainScene::update(float dt)
{
    this->updateFloorsAndStars();
    this->isStar();
    this->jumpDown();
}



void MainScene::updateFloorsAndStars()
{
    for (int i =0; i<floorArray.size(); i++) {
        GameFloor *floor = floorArray.at(i);
        floor->setPosition(Point(floor->getPositionX()-forceX * speedFix, floor->getPositionY()));
    }
    for (int i = 0; i<starArray.size(); i++) {
        GameStar *star = starArray.at(i);
        star->setPosition(Point(star->getPositionX()-forceX * speedFix, star->getPositionY()));
    }
    
    if (floorArray.at(0)->getPositionX() <-50) {
        int num = floorArray.size()-1;
        float posx = floorArray.at(num)->getPositionX();        

        floorArray.pushBack(floorArray.at(0));
        
        floorArray.eraseObject(floorArray.at(0));
        
        starArray.pushBack(starArray.at(0));
        starArray.eraseObject(starArray.at(0));
        

        randomNum = this->getRandomNumber(0, 2);
        if (randomNum == 0) {
            isFrontBlank = true;
            randomNum = this->getRandomNumber(1, 4);
        }
        
        GameStar *star = starArray.at(num);

        
        star->setVisible(true);
        if (isFrontBlank) {
           
            floorArray.at(num)->setPosition(Point(posx + randomNum*35 + 35, this->getRandomNumber(winSize.height/2 -100,170)));
            starArray.at(num)->setPosition(Point(posx + randomNum*35 + 35, floorArray.at(num)->getPositionY() + this->getRandomNumber(50, 150)));
            isFrontBlank = false;
        }else{
     
            floorArray.at(num)->setPosition(Point(posx + 35 , floorArray.at(num - 1)->getPositionY()));
            starArray.at(num)->setPosition(Point(posx +  35, floorArray.at(num)->getPositionY() + this->getRandomNumber(50, 150)));
        }
        randomNum = this ->getRandomNumber(0, 2);
        if (randomNum == 0) {
            star->setVisible(false);
        }
    }
}

bool MainScene::isStar()
{
    bool aFlag = false;
    for (int i = 0; i < starArray.size(); i++) {
        Rect box = starArray.at(i)->boundingBox();
        if (hero->boundingBox().intersectsRect(box)) {
            if (starArray.at(i)->isVisible() == true) {
                starArray.at(i)->setVisible(false);
                hero->addScore(1);
                
                if (isPlaySound) {
                    SimpleAudioEngine::getInstance()->playEffect("gold.caf");
                }
            }
        }
    }
    return aFlag;
}

void MainScene::jumpDown()
{
    isColliWithSide = false;
    ySpeed -= accelerate;

    for (int i=0; i<4; i++) {
        Rect box =  floorArray.at(i)->boundingBox();

        if ((hero->boundingBox().intersectsRect(box)
             && abs((hero->getPositionY() - floorArray.at(i)->getPositionY())) < (HeroHeight/2+floorHeight/2-30))
            )
        {
            isColliWithSide = true;
        }
        

        if(hero->boundingBox().intersectsRect(box)  &&
           abs(hero->getPositionX() - floorArray.at(i)->getPositionX())<(HeroWidth/2 + floorWidth/2-10) &&
           abs(hero->getPositionY() - floorArray.at(i)->getPositionY()) <= (HeroHeight/2 + floorHeight/2)
           )
        {
            isCollistionWithStar = true;
            collNum = i;
            ySpeed = -4;
            break;
        }else{
            if (i == 3) {
                isCollistionWithStar = false;
            }
        }
    }
    if (isCollistionWithStar) {
        
        if (isColliWithSide == false) {
            
            hero->setPositionY(floorArray.at(collNum)->getPositionY() + HeroHeight/2 + floorHeight/2);
        }else{
            hero->setPosition(hero->getPosition() + Point(-forceX * speedFix, 0));
        }
        
        this->eventListenter();
        if (jumpNum == 1) {
            jumpNum =0;
        }
    }
    else{
        hero->setPosition(hero->getPosition()+Point(0, ySpeed));
        if (jumpNum >= 2) {
            jumpNum = 0;
            _eventDispatcher->removeAllEventListeners();
        }
    }
}

void MainScene::eventListenter()
{
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->setEnabled(true);
    listener->onTouchBegan = [=](Touch *touch,Event *event){
        ySpeed = 15;
        ySpeed -=accelerate;
        
        jumpNum++;
        
        hero->setPosition(hero->getPosition()+ Point(0, ySpeed));
        
        return true;
    };
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
 
}

#pragma mark --aaaaaaaaaaaa--
Vector<GameFloor*>MainScene::getArrayForFloors()
{
    return floorArray;
}

Vector<GameStar*>MainScene::getArrayForStars()
{
    return starArray;
}

void MainScene::winGame()
{
    Director::getInstance()->pause();
    GameWin *win = GameWin::create();
    this->addChild(win, 13);
}

void MainScene::lostGame()
{
    Director::getInstance()->pause();
    GameLost *lost = GameLost::create();
    this->addChild(lost, 14);
}

GameHero *MainScene::getHero()
{
    return hero;
}

MainScene* MainScene::getMainScene()
{
    return mainScene;
}

int MainScene::getRandomNumber(int from,int to)
{
    return (int)(from + (arc4random()%(to - from + 1)));
}