//
//  GameFloor.h
//  JXRun
//
//  Created by The9 on 14-6-30.
//
//

#ifndef __JXRun__GameFloor__
#define __JXRun__GameFloor__

#include "cocos2d.h"
USING_NS_CC;

class GameFloor : public Sprite
{
public:
    
    static GameFloor* createFloor();
    
    virtual bool initFloor();
    
    void menuBackCallback(Ref* pSender);
    
    CREATE_FUNC(GameFloor);
};

#endif /* defined(__JXRun__GameFloor__) */
