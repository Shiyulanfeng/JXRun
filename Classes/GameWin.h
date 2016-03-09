//
//  GameWin.h
//  JXRun
//
//  Created by the 9 on 14-7-5.
//
//

#ifndef __JXRun__GameWin__
#define __JXRun__GameWin__

#include "cocos2d.h"
USING_NS_CC;

class GameWin : public Layer
{
public:

    static cocos2d::Scene* scene();
    
    virtual bool init();
    
    void menuBackGameCallback(Ref* pSender);
    
    void menuBackMenuCallback(Ref* pSender);
    
    CREATE_FUNC(GameWin);
};

#endif /* defined(__JXRun__GameWin__) */
