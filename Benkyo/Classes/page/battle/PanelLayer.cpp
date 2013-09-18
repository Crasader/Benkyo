//
//  ModalLayer.cpp
//  Modal
//
//  Created by Akihiro Matsuura on 5/22/13.
//  Copyright 2013 Syuhari, Inc. All rights reserved.
//
//

#include "PanelLayer.h"
#include <ccTypes.h>
#include "cocos2d.h"
#include "BattleScene.h"

USING_NS_CC;

bool PanelLayer::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    
    CCLayerColor* panelBg = CCLayerColor::create(ccc4(51, 51, 51, 255),size.width,200);
    panelBg->setPosition(ccp(0,0));
    this->addChild(panelBg);
    
    CCLayerColor* exBarBg = CCLayerColor::create(ccc4(68, 68, 68, 255),500,20);
    exBarBg->setPosition(ccp(70,50));
    this->addChild(exBarBg);
    
    CCLayerColor* hpBarBg = CCLayerColor::create(ccc4(68, 68, 68, 255),500,20);
    hpBarBg->setPosition(ccp(70,120));
    this->addChild(hpBarBg);
    
    exBar = CCLayerColor::create(ccc4(63, 255, 255, 255),500,20);
    exBar->setPosition(ccp(70,50));
    staminaBar = CCLayerColor::create(ccc4(255, 0, 0, 255),500,20);
    staminaBar->setPosition(ccp(70,120));
    
    exBar->setTag(1);
    staminaBar->setTag(2);
    
    this->addChild(exBar);
    this->addChild(staminaBar);
    
    CCLayerColor* barCover = CCLayerColor::create(ccc4(51, 51, 51, 255),70,200);
    barCover->setPosition(ccp(0,0));
    this->addChild(barCover);
    
    
    // クリック用のボタン
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                                          "image/ui/common_ui_mainButton_up.png",
                                                          "image/ui/common_ui_mainButton_down.png",
                                                          this,
                                                          menu_selector(PanelLayer::testBtnHandler));
    
    // 表示位置を指定
    pCloseItem->setPosition(ccp(350,430));
    // CCMenuItemImage から CCMenuを作成
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    // CCMenuとしての位置は(0,0)を指定
    pMenu->setPosition(-150,130);
    
    this->addChild(pMenu);
    
    return true;
}

void PanelLayer::setExBar(int value)
{
    CCLOG("setExBar : %i",value);
    
    int sa = 100 - value;
    
    int newBarX = sa * 5 * -1 + 70;
    
    CCLOG("newBarX : %i",newBarX);
    
    CCLayerColor*myre = (CCLayerColor *)PanelLayer::getChildByTag(1);
    myre->runAction(
        CCSequence::create(
              CCDelayTime::create(0.300f),
              CCEaseExponentialInOut::create(CCMoveTo::create(0.5f, ccp(newBarX, 50))),
              NULL
        )
    );
    
}

void PanelLayer::testBtnHandler(CCObject* pSender)
{
    CCLOG("panelLayer btn handler, Dispatch Observer");
//    BattleScene::skipAnimation();
    
    CCNotificationCenter::sharedNotificationCenter()->postNotification("ober");
}
    

