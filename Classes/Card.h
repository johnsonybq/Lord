//
//  Card.h
//  MyCppGame
//
//  Created by apple on 15-3-14.
//
//

#ifndef __MyCppGame__Card__
#define __MyCppGame__Card__

#include "Common.h"


struct CardData
{
    int cardId;
    int cardType;
    int cardValue;
    
    CardData()
    {
        cardId = 0;
        cardValue = 0;
        cardType = 0;
    }
    
    void init(int cardId)
    {
        this->cardId = cardId;
        
        if (this->cardId == 52) {
            this->cardValue = 16;
        }
        else if (this->cardId == 53)
        {
            this->cardValue = 17;
        }
        else
        {
            this->cardValue = this->cardId % 13 +3;
            this->cardType = floor(this->cardId / 13) +1;
        }
    }
};

class Card : public Layer
{
public:
    Card();
    ~Card();
    
    static Card* create(int cardId);
    
    static Card* create(CardData* cardData, int playerId);
    
    virtual bool init(int cardId, int playerId);
    virtual bool init(int cardId);
    
    virtual bool onTouchBegin(Touch* touch, Event* event);
    virtual void onTouchMove(Touch* touch, Event* event);
    virtual void onTouchEnd(Touch* touch, Event* event);
    virtual void onTouchCancel(Touch* touch, Event* event);
    
private:
    int                 m_cardValue;
    int                 m_cardType;
    Sprite*             m_cardBg;
    int                 m_cardId;
    bool                m_isMoved;
    bool                m_isSelected;
    int                 m_playerId;
};

#endif /* defined(__MyCppGame__Card__) */
