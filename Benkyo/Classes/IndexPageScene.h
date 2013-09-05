#ifndef __IndexPage_SCENE_H__
#define __IndexPage_SCENE_H__

#include "cocos2d.h"
#include "cocos-ext.h"

class IndexPage : public cocos2d::CCLayer, public cocos2d::extension::CCTableViewDataSource, public cocos2d::extension::CCTableViewDelegate
{
private:
    cocos2d::CCArray* m_pRecipes;
    void nextScene(int nIndex);
    int m_iTouchIndex;
public:
    virtual bool init();
    virtual ~IndexPage();
    static cocos2d::CCScene* scene();
    CREATE_FUNC(IndexPage);
    
    virtual void scrollViewDidScroll(cocos2d::extension::CCScrollView* view) {};
    virtual void scrollViewDidZoom(cocos2d::extension::CCScrollView* view) {}
    virtual void tableCellTouched(cocos2d::extension::CCTableView* table, cocos2d::extension::CCTableViewCell* cell);
    virtual cocos2d::CCSize cellSizeForTable(cocos2d::extension::CCTableView *table);
    virtual cocos2d::extension::CCTableViewCell* tableCellAtIndex(cocos2d::extension::CCTableView *table, unsigned int idx);
    virtual unsigned int numberOfCellsInTableView(cocos2d::extension::CCTableView *table);
};

#endif // __IndexPage_SCENE_H__
