//
//  LoginLayer.h
//  MyCppGame
//
//  Created by apple on 15-3-10.
//
//

#ifndef __MyCppGame__LoginLayer__
#define __MyCppGame__LoginLayer__

#include "UIBase.h"

USING_NS_CC;

class LoginLayer : public UIBase
{
public:
    LoginLayer();
    virtual ~LoginLayer();
    
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(LoginLayer, create);
    
    virtual cocos2d::extension::Control::Handler onResolveCCBCCControlSelector(
                                                                               cocos2d::Ref * pTarget,
                                                                               const char* pSelectorName);
    
    virtual bool init();
    virtual void onNodeLoaded(cocos2d::Node * pNode, cocosbuilder::NodeLoader * pNodeLoader);
    
private:
    void onStartGameHandler(cocos2d::Ref *pSender, cocos2d::extension::Control::EventType type);
    void onSettingHandler(cocos2d::Ref *pSender, cocos2d::extension::Control::EventType type);
    void onExitGameHandler(cocos2d::Ref *pSender, cocos2d::extension::Control::EventType type);
    
};


LAYER_LOADER(LoginLayer);

#endif /* defined(__MyCppGame__LoginLayer__) */
