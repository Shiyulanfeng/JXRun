//
//  GameHero.h
//  JXRun
//
//  Created by The9 on 14-6-27.
//
//

#ifndef __JXRun__GameHero__
#define __JXRun__GameHero__

#include "cocos2d.h"
USING_NS_CC;
using namespace std;

template <typename T>
string Convert2String(const T & value) {
    stringstream ss;
    ss<<value;
    return ss.str();
}

class GameHero : public Sprite
{
public:
    
    int runLength;
    bool isDead;
    int count;
    int score;
    
    void addLength(float _value);
    void addScore(float _value);
    void update(float dt);
    
    static GameHero* createHero();
    
    virtual bool initHero();
    
    CREATE_FUNC(GameHero);

};


#endif /* defined(__JXRun__GameHero__) */
