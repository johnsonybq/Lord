//
//  PopupLayer.h
//  MyCppGame
//
//  Created by Apple mac on 15/3/12.
//
//

#ifndef __MyCppGame__PopupLayer__
#define __MyCppGame__PopupLayer__

#include "cocos2d.h"
#include "cocos-ext.h"

using namespace cocos2d;
using namespace cocos2d::extension;

class PopupLayer : public LayerColor
{
public:
    PopupLayer();
    ~PopupLayer();
    
    
    virtual bool init();
    
    CREATE_FUNC(PopupLayer);
    
    static PopupLayer* create(const char* backgroundImage, Size diagonSize);
    
    bool onTouchBegan(Touch *touch, Event* event);
    void onTouchMoved(Touch *touch, Event* event);
    void onTouchEnded(Touch *touch, Event* event);
    
    void setTitle(const char* title, int fontsize = 20);
    
    void setContentText(const char* text, int fontsize = 20, int padding = 50, int paddintTop = 100);
    
    void setCallbackFunc(Ref* target, SEL_CallFuncN callfun);
    
    bool addButton(const char* normalImage, const char* selectedImage, const char* title, int tag = 0);
    
    virtual void onEnter();
    
    virtual void onExit();
    
    void backgroundFinish();
    
    
private:
    void buttonCallBack(Ref *pSender);
    
    int m_contentPadding;
    
    int m_contentPaddintTop;
    
    Size m_dialogContentSize;
    
    Ref* m_callbackListener;
    
    SEL_CallFuncN m_callback;
    
    CC_SYNTHESIZE_RETAIN(Menu*, m_pMenu, MenuButton);
    
    CC_SYNTHESIZE_RETAIN(Sprite*, m_sfBackGround, SpriteBackGround);
    
    CC_SYNTHESIZE_RETAIN(Scale9Sprite*, m__s9BackGround, Sprite9BackGround);
    
    CC_SYNTHESIZE_RETAIN(LabelTTF*, m__ltTitle, LabelTitle);
    
    CC_SYNTHESIZE_RETAIN(LabelTTF*, m__ltContentText, LabelContentText);
};



#endif /* defined(__MyCppGame__PopupLayer__) */
