//
//  Player.h
//  MyCppGame
//
//  Created by Apple mac on 15/3/15.
//
//

#ifndef __MyCppGame__Player__
#define __MyCppGame__Player__

#include "Common.h"
#include "Card.h"

#include "vector"

#define TURNCOOLDOWN    30                          //出牌倒计时

class Player : public Layer
{
public:
    Player();
    ~Player();
    
    virtual bool init(int index);
    static Player *create(int index);
    void setCardList(std::vector<int> &pokesList);
    int getCardCount();
    
private:
    void sortCard();
    void initCard();
    
    
private:
    std::vector<int>                m_cardIdList;           //玩家手中上牌
    std::vector<Card*>              m_cardList;
    std::vector<CardData*>          m_cardDataList;
    unsigned int                    m_index;                //玩家的INDEX
    bool                            m_isLord;               //是否是地主
    bool                            m_isTurn;               //是否到自己这一回合
    unsigned int                    m_leftTime;             //剩余的倒计时时间
    Vec2                            m_position;             //玩家的位置
};

#endif /* defined(__MyCppGame__Player__) */
