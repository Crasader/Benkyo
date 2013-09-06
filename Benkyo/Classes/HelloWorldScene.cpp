#include "HelloWorldScene.h"

using namespace cocos2d;


CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

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
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    // ここで画像を入れてみた、サイズも自動的に調整してくれることが確認できたい
    //    CCSprite* testSp1 = CCSprite::create("image/quest/04ev_210181.png");
    //    testSp1->setPosition(ccp(320, 480));
    //    this->addChild(testSp1);
    
    CCLayerColor* myLc = CCLayerColor::create(ccc4(250, 0, 0, 255),sizeConverter(320),(100));
    this->addChild(myLc);
    
    myLc->setPosition(ccp(0, 0));
    
    myLc->runAction(
                    CCSequence::create(
                                       CCDelayTime::create(0.500f),
                                       CCEaseExponentialInOut::create(CCMoveTo::create(0.8f, HelloWorld::positionConverter(0,0))),
                                       CCEaseExponentialInOut::create(CCMoveTo::create(0.8f, HelloWorld::positionConverter(0,860))),
                                       CCEaseExponentialInOut::create(CCMoveTo::create(0.8f, HelloWorld::positionConverter(540,860))),
                                       NULL
                                       )
                    );
    
    
    return true;
}



// 変換関数を作ろうと思ったけど、いらないみたい
CCPoint HelloWorld::positionConverter(int myX ,int myY)
{
    //    CCSize size = CCDirector::sharedDirector()->getVisibleSize();
    
    //    if( size.width < 640 ){
    //        myX = int(myX / 2);
    //        myY = int(myY / 2);
    //    }
    
    return ccp(myX,myY);
}

int HelloWorld::sizeConverter(int mySize)
{
    //    CCSize size = CCDirector::sharedDirector()->getVisibleSize();
    //    if( size.width < 640 ){
    //        mySize = int(mySize / 2);
    //    }
    
    return mySize;
}
