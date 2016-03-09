//
//  GameMap.cpp
//  JXRun
//
//  Created by The9 on 14-6-27.
//
//

#include "GameMap.h"
USING_NS_CC;

GameMap *GameMap::createMap(const char *fileName)
{
    GameMap *ret = new GameMap();
    if (ret && ret->init())
    {
        ret->initMap(fileName);
        ret->autorelease();
        return ret;
    }
    else
    {
        CC_SAFE_DELETE(ret);
        return nullptr;
    }
}

void GameMap::initMap(const char *fileName)
{
    
    Size size = Director::getInstance()->getVisibleSize();
    auto bg1 = Sprite::create(fileName);
    bg1->setAnchorPoint(Point(0, 0));
    bg1->setPosition(Point(0, 0));
    this->addChild(bg1, 0, Tag_one);
    
    auto bg2 = Sprite::create(fileName);
    bg2->setAnchorPoint(Point(0, 0));
    bg2->setPosition(Point(bg2->getContentSize().width, 0));
    this->addChild(bg2, 0, Tag_two);
    
/*
    for(int i = 0;i < 7;i ++){
        Sprite* roaddi;
        Sprite* plant;
        if(bg1shu[i] != -1){
            Sprite* road;
            switch(bg1shu[i]){
                case 0:
                    plant = CCSprite::create("back_2.png");
                    plant->setAnchorPoint(Point(1,0));
                    plant->setPosition(Point(64 * i + 64,119));
                    bg1->addChild(plant,1);
                    road = CCSprite::create("road_2.png");
                    road->setAnchorPoint(Point(0,1));
                    road->setPosition(Point(64 * i,128));
                    roaddi = CCSprite::create("road_3.png");
                    roaddi->setAnchorPoint(Point(0,0));
                    roaddi->setPosition(Point(64 * i,0));
                    bg1->addChild(roaddi,1);
                    break;
                case 1:
                    road = Sprite::create("road_1.png");
                    road->setAnchorPoint(Point(0,0));
                    road->setPosition(Point(64 * i,54));
                    roaddi = Sprite::create("road_4.png");
                    roaddi->setAnchorPoint(Point(0,1));
                    roaddi->setPosition(Point(64 * i,54));
                    bg1->addChild(roaddi,1);
                    break;
                case 2:
                    plant = Sprite::create("enemy.png");
                    plant->setAnchorPoint(Point(1,0));
                    plant->setPosition(Point(64 * i + 64,122));
                    bg1->addChild(plant,1);
                    road = Sprite::create("road_1.png");
                    road->setFlippedX(true);
                    road->setAnchorPoint(Point(0,0));
                    road->setPosition(Point(64 * i,55));
                    roaddi = CCSprite::create("road_4.png");
                    roaddi->setFlippedX(true);
                    roaddi->setAnchorPoint(Point(0,1));
                    roaddi->setPosition(Point(64 * i,55));
                    bg1->addChild(roaddi,1);
                    break;
                case 3:
                    road = CCSprite::create("road_5.png");
                    road->setAnchorPoint(Point(0,0));
                    road->setPosition(Point(64 * i,0));
                    break;
                    
            }
            bg1->addChild(road,1);
        }
        if(bg2shu[i] != -1){
            Sprite* road1;
            switch(bg2shu[i]){
                case 0:
                    road1 = Sprite::create("road_2.png");
                    road1->setAnchorPoint(Point(0,0));
                    road1->setPosition(Point(64 * i,0));
                    roaddi = CCSprite::create("road_3.png");
                    
                    roaddi->setAnchorPoint(Point(0,1));
                    roaddi->setPosition(Point(64 * i,0));
                    bg2->addChild(roaddi,1);
                    break;
                case 1:
                    plant = Sprite::create("back_3.png");
                    plant->setAnchorPoint(Point(0.6,0));
                    plant->setPosition(Point(64 * i + 128,115));
                    bg2->addChild(plant,1);
                    road1 = CCSprite::create("road_1.png");
                    road1->setAnchorPoint(Point(0,0));
                    road1->setPosition(Point(64 + 64 * i,50));
                    roaddi = CCSprite::create("road_4.png");
                    
                    roaddi->setAnchorPoint(Point(0,1));
                    roaddi->setPosition(Point(64 + 64 * i,50));
                    bg2->addChild(roaddi,1);
                    break;
                case 2:
                    road1 = Sprite::create("road_1.png");
                    road1->setFlippedX(true);
                    road1->setAnchorPoint(Point(0,0));
                    road1->setPosition(Point(64 * i -128,50));
                    roaddi = CCSprite::create("road_4.png");
                    roaddi->setFlippedX(true);
                    roaddi->setAnchorPoint(Point(0,1));
                    roaddi->setPosition(Point(64 * i- 128,50));
                    bg2->addChild(roaddi,1);
                    break;
                case 3:
                    road1 = CCSprite::create("road_5.png");
                    road1->setAnchorPoint(Point(0,0));
                    road1->setPosition(Point(64 * i + 64,62));
                    break;
                    
            }
            bg2->addChild(road1,1);
        }
    }
    */
 
    this->scheduleUpdate();
    
}

void GameMap::update(float dt)
{
    Size size = Director::getInstance()->getWinSize();
    
    Sprite *bg1 = (Sprite*)getChildByTag(Tag_one);
    if (bg1->getPositionX() <= - bg1->getContentSize().width) {
        bg1->setPosition(Point(bg1->getContentSize().width - 2.5f, 0));
    }else{
        bg1->setPosition(bg1->getPosition() + Point(-2, 0));
    }
    
    Sprite *bg2 = (Sprite*)getChildByTag(Tag_two);
    
    if (bg2->getPositionX() <= - bg2->getContentSize().width) {
        bg2->setPosition(Point(bg2->getContentSize().width - 2.5f, 0));
    }else{
        bg2->setPosition(bg2->getPosition() + Point(-2, 0));
    }
}

void GameMap::onExit()
{
    this->unscheduleUpdate();
    Layer::onExit();
}
