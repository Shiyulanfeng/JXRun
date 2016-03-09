//
//  AboutScene.h
//  JXRun
//
//  Created by The9 on 14-6-27.
//
//

#ifndef __JXRun__AboutScene__
#define __JXRun__AboutScene__

#include "cocos2d.h"
USING_NS_CC;

class AboutScene : public cocos2d::Layer
{
public:
    
    static cocos2d::Scene* Scene();
    
    virtual bool init();
    
    void menuBackCallback(Ref* pSender);
    
    CREATE_FUNC(AboutScene);
};

#endif /* defined(__JXRun__AboutScene__) */
