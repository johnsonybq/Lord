//
//  LordDeskLayer.h
//  MyCppGame
//
//  Created by Apple mac on 15/3/15.
//
//

#ifndef __MyCppGame__LordDeskLayer__
#define __MyCppGame__LordDeskLayer__


#include "Common.h"
#include "UIBase.h"
#include <vector>
#include "LordMediator.h"
#include "Player.h"

using namespace std;

#define CARD_TOTAL          54
#define PLAYER_NUM          3
#define PLAYER_CARDS        17
#define DIZHU_CARD          3


class LordDeskLayer : public UIBase
{
public:
    LordDeskLayer();
    ~LordDeskLayer();
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(LordDeskLayer, create);
    
    virtual bool init();
    
    void fenpai();
    void randDZ();
    
    virtual void onEnter();
    virtual void onExit();
    
private:
    int                        m_deskPokes[CARD_TOTAL] = {0};
    vector<int>                m_personPokes[PLAYER_NUM];
    int                        m_threePokes[DIZHU_CARD] = {0};
    LordMediator               *m_mediator;
    int                        m_boss;
    Player                     *m_player0;
    Player                     *m_player1;
    Player                     *m_player2;
    
};

LAYER_LOADER(LordDeskLayer);

#endif /* defined(__MyCppGame__LordDeskLayer__) */
