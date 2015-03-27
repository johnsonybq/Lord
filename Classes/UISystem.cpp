//
//  UISystem.cpp
//  MyCppGame
//
//  Created by apple on 15-3-14.
//
//

#include "UISystem.h"

UISystem::UISystem():m_boxLayer(NULL)
,m_commonLayer(NULL)
//,m_boxNewLayer(NULL)
,m_topBoxLayer(NULL)
,m_moduleLayer(NULL)
,m_floatTipLayer(NULL)
,m_toolTipLayer(NULL)
,m_guildLayer(NULL)
{
    
}


UISystem::~UISystem()
{
    
}

bool UISystem::init()
{
    if (!Layer::init()) {
        return false;
    }
    
    m_boxLayer = Layer::create();
    this->addChild(m_boxLayer, UI_BOX_LAYER_ZORDER);
    
    m_moduleLayer = Layer::create();
    this->addChild(m_moduleLayer, UI_MODULE_LAYER_ZORDER);
    
    m_commonLayer = Layer::create();
    this->addChild(m_commonLayer, UI_COMMON_LAYER_ZORDER);
    
    m_guildLayer = Layer::create();
    this->addChild(m_guildLayer, UI_GUIDE_LAYER_ZORDER);
    
    m_toolTipLayer = Layer::create();
    this->addChild(m_toolTipLayer, UI_TOOLTIP_LAYER_ZORDER);
    
    return true;
}

void UISystem::addToCommonContainer(cocos2d::Node *node)
{
    CCASSERT( node != nullptr, "Argument must be non-nil");
    
    m_commonLayer->addChild(node);
}

void UISystem::addToGuideContainer(cocos2d::Node *node)
{
    CCASSERT( node != nullptr, "Argument must be non-nil");
    
    m_guildLayer->addChild(node);
}

void UISystem::addToModuleContianer(Node *node)
{
    CCASSERT(node != NULL, "child node can not be null");
    
    m_moduleLayer->removeAllChildrenWithCleanup(true);
    clearAllBox();
    m_moduleLayer->addChild(node);
}

void UISystem::addToTooltipContainer(cocos2d::Node *node)
{
    CCASSERT(node != nullptr, "child node can not be null");
    
    m_toolTipLayer->addChild(node);
}

void UISystem::clearAllBox()
{
    this->m_boxLayer->removeAllChildrenWithCleanup(true);
}