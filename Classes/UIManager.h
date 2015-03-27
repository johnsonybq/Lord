//
//  UIManager.h
//  NinjaVillage
//
//  Created by apple on 15-1-21.
//
//

#ifndef __NinjaVillage__UIManager__
#define __NinjaVillage__UIManager__

#include "Common.h"
#include <list>
#include "cocosbuilder/CocosBuilder.h"
#include "UISystem.h"

#define REGISTER_LOADER(clazzName) \
wndLoaders.push_back(std::make_pair(#clazzName, clazzName##Loader:: loader()));

#define createInterface(__node__,res) \
dynamic_cast<__node__>(UIManager::getInstance().createNodeByCCB(res));

class UIManager : public Singleton<UIManager>
{
    friend Singleton;
public:
    void                init();                     //初始化
    
    Node* createNodeByCCB(const std::string &ccbFileName, Ref *pOwner = NULL);
    
    void setUISystem(UISystem* uicontainer);
    UISystem* getUISystem();
    
private:
    
    void                createUILoader();           //创建所有的UILoader
    void                registerUILoader();         //注册所有的UILoader
private:
    typedef std::list<std::pair<std::string, cocosbuilder::LayerLoader*>> LAYERLOADERLIST;
    LAYERLOADERLIST                                     wndLoaders;
    cocosbuilder::NodeLoaderLibrary                     *ccbLoaderLib;
    
    UISystem*                                            m_uiContainer;

};

#endif /* defined(__NinjaVillage__UIManager__) */
