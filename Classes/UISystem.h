//
//  UISystem.h
//  MyCppGame
//
//  Created by apple on 15-3-14.
//
//

#ifndef __MyCppGame__UISystem__
#define __MyCppGame__UISystem__

#include "cocos2d.h"

USING_NS_CC;

static const int UI_MODULE_LAYER_ZORDER     = 100;                  //游戏模块层
static const int UI_COMMON_LAYER_ZORDER     = 200;                  //common层
//static const int UI_BOX_NEW_LAYER_ZORDER    = 350;                  //新弹窗层
static const int UI_BOX_LAYER_ZORDER        = 200;                  //弹窗层
static const int UI_TOOLTIP_LAYER_ZORDER    = 300;                  //toolTip层
static const int UI_GUIDE_LAYER_ZORDER      = 400;                  //引导层
static const int UI_TOP_BOX_ZORDER          = 450;                  //top_box层
static const int UI_TIP_LAYER_ZORDER        = 500;                  //top_tip层

class UISystem : public Layer
{
public:
    UISystem();
    ~UISystem();
    
    CREATE_FUNC(UISystem);
    
    virtual bool init();
    
    void addToGuideContainer(Node* node);
    
    void addToTooltipContainer(Node* node);
    
    void addToModuleContianer(Node* node);
    
    void addToCommonContainer(Node* node);
    
    void clearAllBox();
    
private:
    
    Layer*                          m_moduleLayer;
    Layer*                          m_floatTipLayer;
    Layer*                          m_toolTipLayer;
    Layer*                          m_boxLayer;
    Layer*                          m_guildLayer;
    Layer*                          m_topBoxLayer;
    Layer*                          m_commonLayer;
};

#endif /* defined(__MyCppGame__UISystem__) */
