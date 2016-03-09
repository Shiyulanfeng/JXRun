//
//  GameMap.h
//  JXRun
//
//  Created by The9 on 14-6-27.
//
//

#ifndef __JXRun__GameMap__
#define __JXRun__GameMap__

#include "cocos2d.h"
#include "GameStar.h"
USING_NS_CC;

typedef enum
{
    Tag_one,
    Tag_two
}Tag_Map;

class GameMap : public Layer
{
public:
    
    static GameMap* createMap(const char *fileName);
    
    void initMap(const char *fileName);
    
    CREATE_FUNC(GameMap);
    
    Vector<GameStar*> starArray;
    
    void update(float dt);
    
    void onExit();
};

#endif /* defined(__JXRun__GameMap__) */
