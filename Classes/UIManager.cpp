//
//  UIManager.cpp
//  NinjaVillage
//
//  Created by apple on 15-1-21.
//
//

#include "UIManager.h"
#include "LoginLayer.h"
#include "LordDeskLayer.h"

void UIManager::init()
{
    ccbLoaderLib = cocosbuilder::NodeLoaderLibrary::newDefaultNodeLoaderLibrary();
    ccbLoaderLib->retain();
    
    createUILoader();
    registerUILoader();
    
}

void UIManager::createUILoader()
{
    REGISTER_LOADER(LoginLayer);
    REGISTER_LOADER(LordDeskLayer);
}

void UIManager::setUISystem(UISystem *uicontainer)
{
    m_uiContainer = uicontainer;
}

UISystem* UIManager::getUISystem()
{
    return m_uiContainer;
}

void UIManager::registerUILoader()
{
    auto itrLoader = wndLoaders.begin();
    
    for (; itrLoader != wndLoaders.end() ; ++itrLoader) {
        auto uiLoader = *itrLoader;
        ccbLoaderLib->registerNodeLoader(uiLoader.first.c_str(), uiLoader.second);
    }
}

Node* UIManager::createNodeByCCB(const std::string &pCCBFileName,Ref *pOwner)
{
    cocosbuilder::CCBReader * ccbReader = new cocosbuilder::CCBReader(ccbLoaderLib);
    ccbReader->autorelease();
    Node* node = ccbReader->readNodeGraphFromFile(pCCBFileName.c_str(), pOwner);
    return node;
}