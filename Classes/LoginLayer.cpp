//
//  LoginLayer.cpp
//  MyCppGame
//
//  Created by apple on 15-3-10.
//
//

#include "LoginLayer.h"
#include "LordDeskLayer.h"
#include "UIManager.h"


LoginLayer::LoginLayer()
{
    
}

LoginLayer::~LoginLayer()
{
    
}

bool LoginLayer::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    return true;
}

cocos2d::extension::Control::Handler LoginLayer::onResolveCCBCCControlSelector(
                                                                                   cocos2d::Ref * pTarget,
                                                                                   const char* pSelectorName){
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "LoginHandler", LoginLayer::onStartGameHandler);
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "onSettingHandler", LoginLayer::onSettingHandler);
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "onExitGameHandler", LoginLayer::onExitGameHandler);
    
}

void LoginLayer::onStartGameHandler(cocos2d::Ref *pSender, cocos2d::extension::Control::EventType type)
{
    printf("StartGameLayer on StartGameHandler is clicked\n");
    LordDeskLayer* layer = createInterface(LordDeskLayer*, "ccb/LordDeskLayer.ccbi");
    UIManager::getInstance().getUISystem()->addToModuleContianer(layer);
    
}

void LoginLayer::onSettingHandler(cocos2d::Ref *pSender, cocos2d::extension::Control::EventType type)
{
    printf("onSettingHandler on onSettingHandler is clicked\n");
}

void LoginLayer::onExitGameHandler(cocos2d::Ref *pSender, cocos2d::extension::Control::EventType type)
{
    printf("onExitGameHandler on onExitGameHandler is clicked\n");
    Director::getInstance()->end();
    
    exit(0);
}


void LoginLayer::onNodeLoaded(cocos2d::Node * pNode, cocosbuilder::NodeLoader * pNodeLoader)
{
    
}
