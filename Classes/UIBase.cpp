//
//  UIBase.cpp
//  NinjaVillage
//
//  Created by apple on 15-1-20.
//
//

#include "UIBase.h"

UIBase::UIBase()
{
    
}

UIBase::~UIBase()
{
    
}

cocos2d::SEL_MenuHandler UIBase::onResolveCCBCCMenuItemSelector(cocos2d::Ref *pTarget, const char *pSelectorName)
{
    return nullptr;
}

cocos2d::extension::Control::Handler UIBase::onResolveCCBCCControlSelector(cocos2d::Ref *pTarget, const char *pSelectorName)
{
    return nullptr;
}

bool UIBase::onAssignCCBMemberVariable(cocos2d::Ref *target, const char *memberVariableName, cocos2d::Node *node)
{
    auto targetNode = mVariables.find(memberVariableName);
    if (targetNode == mVariables.end()) {
        mVariables.insert(VARIABLE_MAP::value_type(memberVariableName, node));
    }
    
    return true;
}

void UIBase::onNodeLoaded(cocos2d::Node * pNode, cocosbuilder::NodeLoader * pNodeLoader)
{
    
}

