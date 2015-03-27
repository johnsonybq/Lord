//
//  GameMainScene.h
//  MyCppGame
//
//  Created by apple on 15-3-14.
//
//

#ifndef __MyCppGame__GameMainScene__
#define __MyCppGame__GameMainScene__

#include "cocos2d.h"
#include "UISystem.h"

USING_NS_CC;

class GameMainScene : public Scene
{
public:
    GameMainScene();
    ~GameMainScene();
    
    CREATE_FUNC(GameMainScene);
    
    virtual bool init();
    
private:
    UISystem*                       m_uiContainer;
};

#endif /* defined(__MyCppGame__GameMainScene__) */
