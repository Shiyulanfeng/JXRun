//
//  ScoreScene.h
//  JXRun
//
//  Created by the 9 on 14-7-7.
//
//

#ifndef __JXRun__ScoreScene__
#define __JXRun__ScoreScene__

#include "cocos2d.h"
USING_NS_CC;

class ScoreScene : public Layer
{
public:
    
    static Scene* Scene();
    
    virtual bool init();
    
    void menuBackCallback(Ref* pSender);
    
    CREATE_FUNC(ScoreScene);
};

#endif /* defined(__JXRun__ScoreScene__) */
