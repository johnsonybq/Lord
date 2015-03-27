#include "AppDelegate.h"
#include "HelloWorldScene.h"
#include "UIManager.h"
#include "GameMainScene.h"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
//        glview = GLViewImpl::create("Lord");
        glview = GLView::create("Lord");
        director->setOpenGLView(glview);
    }
    Size screenSize = director->getOpenGLView()->getFrameSize();
    
    Size designSize = Size(960, 640);
    double asp = screenSize.width / screenSize.height;
    designSize.height = designSize.width / asp;
    
    director->getOpenGLView()->setDesignResolutionSize(designSize.width, designSize.height, ResolutionPolicy::NO_BORDER);
    
    auto size1 = director->getOpenGLView()->getDesignResolutionSize();
    

    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);

    // create a scene. it's an autorelease object
    UIManager::getInstance().init();
    
    auto scene = GameMainScene::create();
//    auto scene = HelloWorld::createScene();
    
    
    printf("screen size is (%f,%f)\n",size1.width,size1.height);

    // run
    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
