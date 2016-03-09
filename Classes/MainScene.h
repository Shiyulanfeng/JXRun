//
//  MainScene.h
//  JXRun
//
//  Created by The9 on 14-6-27.
//
//

#ifndef __JXRun__MainScene__
#define __JXRun__MainScene__

#include "cocos2d.h"
#include "GameMap.h"
#include "GameHero.h"
#include "GameStar.h"
#include "GameFloor.h"
USING_NS_CC;

enum ROLE_STATE {
    ROLE_INVAILD_STATE = 0,
    ROLE_RUN,
    ROLE_JUMP_UP,
    ROLE_JUMP_DOWN
};


typedef  enum COLL_STATE {
    isOriginal = 0,
    isOnFloor ,
    isJumpUp,
    isJumpDown
}playerState;

class MainScene : public cocos2d::Layer
{
public:
    
    Size winSize;//屏幕大小
    
    float playerRigthtX;//人物前边框的x坐标
    float playerBottomY;//人物下边框的y坐标
    
    float floorTopY;//地面上边框的y坐标
    float floorLeftX;//地面后边框的x坐标
    
    float floorHeight;//地面高度
    float floorWidth;//地面宽度
    
    float HeroWidth;//人物宽度
    float HeroHeight;//人物高度
    
    int collNum;//发生碰撞的数组元素下标
    
    int jumpNum;//用来记录跳跃次数
    
    bool isJump;//是否跳起
    bool isCollistionWithStar;//是否与地面发生碰撞
    bool isColliWithSide;
    bool isSound;
    bool isFrontBlank;
    float forceX;
    float speedFix;
    float forceY;
    float scaleFix;
    float accelerate;
    bool isPlaySound;
    Size sizep;
    
    int randomNum;
    
    
    GameHero *hero;
    
    static cocos2d::Scene* Scene();
    
    virtual bool init();
    
    void menuCloseCallback(Ref* pSender);
    
    static MainScene* getMainScene();
    void update(float dt);
    void initFloorsAndStars();
    void updateFloorsAndStars();
    GameHero* getHero();
    void eventListenter();
    int getRandomNumber(int from,int to);
    bool isStar();
    void jumpDown();
    void winGame();
    void lostGame();
    
    CC_SYNTHESIZE(ROLE_STATE, currentRoleState, CurrentRoleState);
    
    CC_SYNTHESIZE(float, xSpeed, XSpeed);
    CC_SYNTHESIZE(float, ySpeed, YSpeed);
    
    CC_SYNTHESIZE(float, constXspeed, ConstXspeed);
    CC_SYNTHESIZE(float, constYspeed, ConstYspeed);
    
    Vector<GameStar*> starArray;
    Vector<GameStar*>getArrayForStars();
    
    int floorCount;
    Vector<GameFloor*> floorArray;
    Vector<GameFloor*>getArrayForFloors();
    
    CREATE_FUNC(MainScene);
};


#endif /* defined(__JXRun__MainScene__) */
