#include "IndexPageScene.h"
#include "QuestScene.h"
#include "GachaScene.h"
#include "Recipe26.h"
#include "BattleScene.h"
#include "ScrollScene.h"
#include "EffectScene.h"
#include "TouchTestScene.h"
#include "ReadCcbiScene.h"
#include "ParticleTestScene.h"
#include "SpriteSheetScene.h"
#include "Page1Scene.h"
#include "Page2Scene.h"
#include "SinglePage.h"
#include "HelloWorldScene.h"
#include <iomanip>

USING_NS_CC;
USING_NS_CC_EXT;

CCScene* IndexPage::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    IndexPage *layer = IndexPage::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

IndexPage::~IndexPage()
{
    CC_SAFE_RELEASE(m_pRecipes);
}

bool IndexPage::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
    
    m_pRecipes = CCArray::createWithContentsOfFile("indexList.plist");
    m_pRecipes->retain();

    CCTableView* tableView = CCTableView::create(this, visibleSize);
    tableView->setDirection(kCCScrollViewDirectionVertical);
    tableView->setVerticalFillOrder(kCCTableViewFillTopDown);
    tableView->setPosition(origin);
    tableView->setDelegate(this);
    this->addChild(tableView);
    tableView->reloadData();
    
    return true;
}

void IndexPage::tableCellTouched(CCTableView* table, CCTableViewCell* cell)
{
    CCDictionary* pRecipe = (CCDictionary*)m_pRecipes->objectAtIndex(cell->getIdx());
    CCString* pNo   = (CCString*)pRecipe->objectForKey("page");
    
    this->nextScene(pNo->intValue());
}

CCSize IndexPage::cellSizeForTable(CCTableView *table)
{
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    float height = visibleSize.height/10;
    return CCSizeMake(visibleSize.width, height);
}

CCTableViewCell* IndexPage::tableCellAtIndex(CCTableView *table, unsigned int idx)
{
    CCDictionary* pRecipe = (CCDictionary*)m_pRecipes->objectAtIndex(idx);
    CCString* pName = (CCString*)pRecipe->objectForKey("name");
    
    int indexNum = idx +1;
    CCString* string = CCString::createWithFormat("No. %i %s", indexNum, pName->getCString());
    
    CCTableViewCell *cell = table->dequeueCell();
    if (!cell) {
        cell = new CCTableViewCell();
        cell->autorelease();
        
        CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
        
        int fontSize = CCEGLView::sharedOpenGLView()->getDesignResolutionSize().height/420.0f * 12;
        CCLabelTTF *label = CCLabelTTF::create(string->getCString(), "Helvetica", fontSize, CCSizeMake(visibleSize.width, visibleSize.height/5), kCCTextAlignmentCenter);
        label->setPosition(ccp(0,-110));
		label->setAnchorPoint(CCPointZero);
        label->setTag(123);
        cell->addChild(label);
    }
    else
    {
        CCLabelTTF *label = (CCLabelTTF*)cell->getChildByTag(123);
        label->setString(string->getCString());
    }
    
    
    return cell;
}

unsigned int IndexPage::numberOfCellsInTableView(CCTableView *table)
{
    return m_pRecipes->count();
}

void IndexPage::nextScene(int nIndex)
{
    CCLOG ("Width trick: %*d \n", 5, nIndex);
    
    CCScene* scene = NULL;
    
    switch (nIndex) {
        case 1:
            scene = QuestScene::create(); 
            break;
        case 2:
            scene = Recipe26::scene();
            break;
        case 3:
            scene = BattleScene::scene();
            break;
        case 4:
            scene = ScrollScene::scene();
            break;
        case 5:
            scene = EffectScene::scene();
            break;
        case 6:
            scene = TouchTestScene::scene();
            break;
        case 7:
            scene = ReadCcbiScene::scene();
            break;
        case 8:
            scene = ParticleTestScene::scene();
            break;
        case 9:
            scene = SpriteSheetScene::scene();
            break;
        case 10:
            scene = Page1Scene::scene();
            break;
        case 11:
            scene = HelloWorld::scene();
            break;
        default:
            break;
    }

    if (scene!=NULL) {
        CCDirector::sharedDirector()->replaceScene(scene);
    }else{
        
    }
     
     
}