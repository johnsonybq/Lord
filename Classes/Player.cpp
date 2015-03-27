//
//  Player.cpp
//  MyCppGame
//
//  Created by Apple mac on 15/3/15.
//
//

#include "Player.h"
#include <math.h>


Player::Player()
{
    
}

Player::~Player()
{
    m_cardList.clear();
    m_cardIdList.clear();
    m_cardDataList.clear();
}

bool Player::init(int index)
{
    m_index = index;
    
    return true;
}

Player* Player::create(int index)
{
    Player *player = new Player();
    if (player && player->init(index)) {
        player->autorelease();
        
        return player;
    }
    else
    {
        delete player;
        player = NULL;
    }
    
    return player;
}

void Player::initCard()
{
    int length = getCardCount();
    for (int i= 0; i<length; i++) {
        CardData* data = new CardData();
        data->init(m_cardIdList[i]);
        m_cardDataList.push_back(data);
    }
    
    sortCard();
    
    for (int i= 0; i<length; i++) {
        Card* card = Card::create(m_cardDataList[i], m_index);
        m_cardList.push_back(card);
        this->addChild(card,5);
        
        if (m_index == 1) {
            card->setPosition((card->getContentSize().width / 3) * i, 0.0f);
        }
        else if (m_index == 0)
        {
            float posX = 5 * cos(3.1415926 * 55/180) * i;
            float posY = 5 * sin(3.1415926 * 55/180) * i;
            card->setPosition(-posX, -posY);
        }
        else if (m_index == 2)
        {
            float posX = 5 * cos(3.1415926 * 55/180) * i;
            float posY = 5 * sin(3.1415926 * 55/180) * i;
            card->setPosition(posX, -posY);
            card->setScaleX(-1.0f);
        }
    }
}


void Player::setCardList(std::vector<int> &pokesList)
{
    m_cardIdList = pokesList;
    initCard();
}

int Player::getCardCount()
{
    return (int)m_cardIdList.size();
}

void Player::sortCard()
{
    int count = getCardCount();
    
    for (int l = 0; l < count; l++) {
        for (int j = l+1; j<count; j++) {
            if (m_cardDataList[l]->cardValue < m_cardDataList[j]->cardValue) {
                CardData* temp = m_cardDataList[l];
                m_cardDataList[l] = m_cardDataList[j];
                m_cardDataList[j] = temp;
            }
            else if (m_cardDataList[l]->cardValue == m_cardDataList[j]->cardValue)
            {
                if (m_cardDataList[l]->cardType < m_cardDataList[j]->cardType) {
                    CardData* temp = m_cardDataList[l];
                    m_cardDataList[l] = m_cardDataList[j];
                    m_cardDataList[j] = temp;
                }
            }
        }
    }
}