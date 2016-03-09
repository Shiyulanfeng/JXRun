//
//  GameLost.h
//  JXRun
//
//  Created by the 9 on 14-7-5.
//
//

#ifndef __JXRun__GameLost__
#define __JXRun__GameLost__

#include "cocos2d.h"
USING_NS_CC;

class GameLost : public Layer
{
public:
    
    static cocos2d::Scene* scene();
    
    virtual bool init();
    
    void menuBackGameCallback(Ref* pSender);
    
    void menuBackMenuCallback(Ref* pSender);
    
    CREATE_FUNC(GameLost);
};


#endif /* defined(__JXRun__GameLost__) */
