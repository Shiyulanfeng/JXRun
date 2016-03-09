//
//  MenuScene.h
//  JXRun
//
//  Created by The9 on 14-6-27.
//
//

#ifndef __JXRun__MenuScene__
#define __JXRun__MenuScene__

#include "cocos2d.h"
USING_NS_CC;

class MenuScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    MenuItemImage *soundItem;
    static bool getSound();
    void menuNewGameCallback(Ref* pSender);
    void menuAboutCallback(Ref* pSender);
    void menuSoundCallback(Ref* pSender);
    void menuScoreCallback(Ref* pSender);
    CREATE_FUNC(MenuScene);
};


#endif /* defined(__JXRun__MenuScene__) */
