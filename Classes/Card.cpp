//
//  Card.cpp
//  MyCppGame
//
//  Created by apple on 15-3-14.
//
//

#include "Card.h"


Card::Card()
:m_cardValue(0)
,m_cardType(0)
,m_cardBg(NULL)
,m_isSelected(false)
,m_isMoved(false)
{
    
}

Card::~Card()
{
    
}

Card* Card::create(int cardId)
{
    Card* pRect = new Card();
    if (pRect && pRect->init(cardId)) {
        pRect->autorelease();
        
        return pRect;
    }
    
    delete pRect;
    pRect = NULL;
    
    return pRect;
}

Card* Card::create(CardData *cardData)
{
    Card* pRect = new Card();
    if (pRect && pRect->init(cardData->cardId)) {
        pRect->autorelease();
        
        return pRect;
    }
    
    delete pRect;
    pRect = NULL;
    
    return pRect;
}

bool Card::init(int cardId)
{
    m_cardBg = Sprite::create("bg/newbg_cardFront.png");
    this->addChild(m_cardBg);
    
    this->m_cardId = cardId;
    
    if (this->m_cardId == 52) {
        this->m_cardValue = 16;
    }
    else if (this->m_cardId == 53)
    {
        this->m_cardValue = 17;
    }
    else
    {
        this->m_cardValue = this->m_cardId % 13 +3;
        this->m_cardType = floor(this->m_cardId / 13) +1;
    }
    
    if (true){
        char cardV[100];
        sprintf(cardV, "shape/newshape_b%d.png",this->m_cardValue);
        Sprite* value = Sprite::create(cardV);
        value->setAnchorPoint(Vec2(0.5f,0.0f));
        m_cardBg->addChild(value);
        value->setScale(0.75f);
        value->setPosition(20,m_cardBg->getBoundingBox().size.height-value->getBoundingBox().size.height-10);
        
        
        if (this->m_cardValue != 16 && this->m_cardValue != 17) {
            sprintf(cardV, "shape/newshape_cardType%d.png",this->m_cardType);
            Sprite* cardType = Sprite::create(cardV);
            cardType->setScale(0.75f);
            m_cardBg->addChild(cardType,2);
            cardType->setPosition(20,m_cardBg->getBoundingBox().size.height-cardType->getBoundingBox().size.height-34);
        }
        
    }
   
    
    this->setContentSize(m_cardBg->getContentSize());
    
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = std::bind(&Card::onTouchBegin, this, std::placeholders::_1, std::placeholders::_2);
    listener->onTouchMoved = std::bind(&Card::onTouchMove, this, std::placeholders::_1, std::placeholders::_2);
    listener->onTouchEnded = std::bind(&Card::onTouchEnd, this, std::placeholders::_1, std::placeholders::_2);
    listener->onTouchCancelled = std::bind(&Card::onTouchCancel,this, std::placeholders::_1, std::placeholders::_2);
    listener->setSwallowTouches(true);
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
    return true;
}


bool Card::onTouchBegin(cocos2d::Touch *touch, cocos2d::Event *event)
{
    auto location = touch->getLocation();
    location = this->convertTouchToNodeSpace(touch);
    if (m_cardBg->getBoundingBox().containsPoint(location)) {
        printf("touch the card id: %d\n",this->m_cardId);
        return true;
    }
    return false;
}

void Card::onTouchMove(cocos2d::Touch *touch, cocos2d::Event *event)
{
    m_isMoved = true;
}

void Card::onTouchEnd(cocos2d::Touch *touch, cocos2d::Event *event)
{
    if (m_isMoved) {
        m_isMoved = false;
        return ;
    }
    this->m_isSelected = !this->m_isSelected;
    
    if (this->m_isSelected) {
        this->setPositionY(this->getPositionY() + 30);
    }
    else
    {
        this->setPositionY(this->getPositionY() - 30);
    }
}

void Card::onTouchCancel(cocos2d::Touch *touch, cocos2d::Event *event)
{
    
}

