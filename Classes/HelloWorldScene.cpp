#include "HelloWorldScene.h"
#include "LoginLayer.h"
#include "UIManager.h"
#include "Common.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
//    UIsystem
    
    LoginLayer* node = dynamic_cast<LoginLayer*>(UIManager::getInstance().createNodeByCCB("ccb/LoginLayer.ccbi"));
    this->addChild(node);
    UIManager::getInstance().getUISystem()->addToModuleContianer(node);
    
    unsigned long length = 0;
    
    Data data = FileUtils::getInstance()->getDataFromFile("config/chinese.lang");
    
    unsigned char* buffer = data.getBytes();
    
    length = data.getSize();
    
//    unsigned char *buffer = CCFileUtils::sharedFileUtils()->getFileData(filePath, "r", &length);
//    return_false_if_zero(length);
    
    // 将Bomb的表头做个处理
//    unsigned char *contentBegin = buffer;
    
//    printf("the buffer is :\n%s\n",buffer);
    
    unsigned char *newBuffer = buffer + length - 100;
    
    data.clear();
    
//    printf("the buffer is :\n%s\n",newBuffer);
//    
//    printf("the buffer length is :\n%d\n",length);
    
    std::string path = FileUtils::getInstance()->fullPathForFilename("ccb/LoginLayer.ccbi");
    printf("output the LoginLayer full Path is %s\n",path.c_str());
    
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
