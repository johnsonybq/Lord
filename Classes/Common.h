//
//  Common.h
//  NinjaVillage
//
//  Created by apple on 15-1-21.
//
//

#ifndef NinjaVillage_Common_h
#define NinjaVillage_Common_h

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;


enum  CARD_TYPE
{
    SINGLE_CARD =1,         //单牌
    DOUBLE_CARD,            //对子
    THREE_CARD  ,           //3不带
    BOMB_CARD,              //炸弹
    THREE_ONE_CARD,         //3带1
    THREE_TEO_CARD,         //3带2
    BOMB_TWO_CARD,          //四个带2张单牌
    BOMB_TWOOO_CARD,        //四个带2对
    CONNECT_CARD,           //连牌
    COMPANY_CARD,           //连队
    AIRCRAFT_CARD,          //飞机不带
    AIRCRAFT_SINGLE_CARD,   //飞机带单牌
    AIRCRAFT_DOUBLE_CARD,   //飞机带对子
    ERROR_CARD              //错误的牌型
};


template <class Interface, class Counterpart = Interface>
class Singleton{
public:
    static Interface &getInstance()
    {
        static Interface instance;
        return instance;
    }
};

#endif
