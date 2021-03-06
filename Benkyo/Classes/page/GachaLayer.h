//
//  GachaLayer.h
//  CCBer
//
//  Created by B02582 on 2013/07/12.
//
//

#import "CCBAnimationManager.h"

#ifndef __CCBer__GachaLayer__
#define __CCBer__GachaLayer__

#include "cocos2d.h"
#include "cocos-ext.h"

class GachaLayer :
public cocos2d::CCLayer
, public cocos2d::extension::CCBMemberVariableAssigner
, public cocos2d::extension::CCBSelectorResolver

{
    virtual bool init();
    virtual bool onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode *pNode);
    virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName);
    virtual cocos2d::extension::SEL_CCControlHandler onResolveCCBCCControlSelector(CCObject* pTarget, const char* pSelectorName);
    
    cocos2d::extension::CCControlButton* goNextBtn;
    

    public:
        CREATE_FUNC(GachaLayer);
        void goNext();
    
};

class GachaBuilderLoader : public cocos2d::extension::CCLayerLoader {
    
    public:
        CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(GachaBuilderLoader, loader);
       
        
    protected:
        CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(GachaLayer);
};



#endif /* defined(__CCBer__GachaLayer__) */



