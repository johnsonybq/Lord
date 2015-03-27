//
//  UIBase.h
//  NinjaVillage
//
//  Created by apple on 15-1-20.
//
//

#ifndef __NinjaVillage__UIBase__
#define __NinjaVillage__UIBase__

#include "cocos2d.h"
#include "cocos-ext.h"
#include "cocosbuilder/CocosBuilder.h"
#include <map>

#define LAYER_LOADER(__TYPE__)\
    class __TYPE__##Loader : public cocosbuilder::LayerLoader {\
    public:\
        CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(__TYPE__##Loader, loader);\
    protected:\
        CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(__TYPE__);\
}

USING_NS_CC;
USING_NS_CC_EXT;

class UIBase
    : public cocos2d::Layer
    , public cocosbuilder::CCBSelectorResolver
    , public cocosbuilder::CCBMemberVariableAssigner
    , public cocosbuilder::NodeLoaderListener
{
public:
    UIBase();
    virtual ~UIBase();
    
    virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::Ref * pTarget, const char* pSelectorName);
    virtual cocos2d::extension::Control::Handler onResolveCCBCCControlSelector(cocos2d::Ref * pTarget, const char* pSelectorName);
    virtual bool onAssignCCBMemberVariable(cocos2d::Ref* target, const char* memberVariableName, cocos2d::Node* node);
    virtual void onNodeLoaded(cocos2d::Node * pNode, cocosbuilder::NodeLoader * pNodeLoader);
    
    
    template <class T>
    T* getVariable(const char* name){
        VARIABLE_MAP::iterator pRet = mVariables.find(name);
        if (pRet != mVariables.end())
        {
            return dynamic_cast<T*>(pRet->second);
        }
        return NULL;
    }
    
private:
    typedef std::map<std::string, cocos2d::Node*> VARIABLE_MAP;
    VARIABLE_MAP mVariables;
};

#endif /* defined(__NinjaVillage__UIBase__) */
