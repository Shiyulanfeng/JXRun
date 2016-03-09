//
//  GameStar.h
//  JXRun
//
//  Created by The9 on 14-6-27.
//
//

#ifndef __JXRun__GameStar__
#define __JXRun__GameStar__

#include "cocos2d.h"
USING_NS_CC;

class GameStar : public Node
{
public:
    
    static GameStar* createStar();
    
    virtual bool initStar();
    
    CREATE_FUNC(GameStar);
    
};

#endif /* defined(__JXRun__GameStar__) */
