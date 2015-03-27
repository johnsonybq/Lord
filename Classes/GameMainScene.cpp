//
//  GameMainScene.cpp
//  MyCppGame
//
//  Created by apple on 15-3-14.
//
//
#include "LoginLayer.h"
#include "UIManager.h"
#include "GameMainScene.h"


GameMainScene::GameMainScene()
{
    
}

GameMainScene::~GameMainScene()
{
    
}

bool GameMainScene::init()
{
    m_uiContainer = UISystem::create();
    this->addChild(m_uiContainer);
    UIManager::getInstance().setUISystem(m_uiContainer);
    
    LoginLayer* node = createInterface(LoginLayer*, "ccb/LoginLayer.ccbi");
    UIManager::getInstance().getUISystem()->addToModuleContianer(node);
    
    return true;
}