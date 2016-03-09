//
//  GameStar.cpp
//  JXRun
//
//  Created by The9 on 14-6-27.
//
//

#include "GameStar.h"

GameStar* GameStar::createStar()
{
    GameStar *ret = new GameStar();
    if (ret && ret->init())
    {
        ret->initStar();
        ret->autorelease();
        return ret;
    }
    else
    {
        CC_SAFE_DELETE(ret);
        return nullptr;
    }

}

bool GameStar::initStar()
{
    Sprite *star = Sprite::create("star.png");
    star->setVisible(true);
    this->addChild(star,1);
    return true;
}


