//
//  GameFloor.cpp
//  JXRun
//
//  Created by The9 on 14-6-30.
//
//

#include "GameFloor.h"
#include "MainScene.h"
USING_NS_CC;

GameFloor* GameFloor::createFloor()
{
    GameFloor *ret = new GameFloor();
    if (ret && ret->initWithFile("road_5.png"))
    {

        ret->autorelease();
        return ret;
    }
    else
    {
        CC_SAFE_DELETE(ret);
        return nullptr;
    }
    
}

bool GameFloor::initFloor()
{


    return true;
}