//
//  Player.cpp
//  MyCppGame
//
//  Created by Apple mac on 15/3/15.
//
//

#include "Player.h"


Player::Player()
{
    
}

Player::~Player()
{
    
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
        m_cardList.push_back(data);
    }
    
    sortCard();
    
    for (int i= 0; i<length; i++) {
        Card* card = Card::create(m_cardList[i]);
        this->addChild(card,5);
        card->setPosition((card->getContentSize().width / 3) * i +100, 80.0f);
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
            if (m_cardList[l]->cardValue < m_cardList[j]->cardValue) {
                CardData* temp = m_cardList[l];
                m_cardList[l] = m_cardList[j];
                m_cardList[j] = temp;
            }
            else if (m_cardList[l]->cardValue == m_cardList[j]->cardValue)
            {
                if (m_cardList[l]->cardType < m_cardList[j]->cardType) {
                    CardData* temp = m_cardList[l];
                    m_cardList[l] = m_cardList[j];
                    m_cardList[j] = temp;
                }
            }
        }
    }
}