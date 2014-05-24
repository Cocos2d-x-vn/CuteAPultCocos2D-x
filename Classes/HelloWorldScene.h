#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

// When you import this file, you import all the cocos2d classes
#include "cocos2d.h"
#include "Box2D/Box2D.h"

class HelloWorld : public cocos2d::Layer {
public:
    ~HelloWorld();
    HelloWorld();

    virtual bool init();

    // returns a Scene that contains the HelloWorld as the only child
    static cocos2d::Scene* scene();

    CREATE_FUNC(HelloWorld);

    // a selector callback
    virtual void menuCloseCallback(cocos2d::Ref* pSender);

    // adds a new sprite at a given coordinate
    virtual void onDraw();
    void tick(float dt);
    virtual bool onTouchBegan(cocos2d::Touch* touches, cocos2d::Event* event);
    virtual void onTouchMoved(cocos2d::Touch* touches, cocos2d::Event* event);
    virtual void onTouchEnded(cocos2d::Touch* touches, cocos2d::Event* event);
    
    void createBullets(int count);
    bool attachBullet();
    void resetBullet();
    void resetGame();

    void createTargets();
    void createTarget(const char *imageName, cocos2d::Point position,
            float rotation, bool isCircle, bool isStatic, bool isEnemy);

private:
    std::vector<b2Body *> m_bullets;
    std::vector<b2Body *> m_targets;
    std::vector<b2Body *> m_enemies;

    unsigned m_currentBullet;
    b2World* m_world;
    b2Body* m_groundBody;
    b2Fixture *m_armFixture;
    b2Body *m_armBody;
    b2RevoluteJoint *m_armJoint;
    b2MouseJoint *m_mouseJoint;

    b2Body *m_bulletBody;
    b2WeldJoint *m_bulletJoint;

    bool m_releasingArm;
};


#endif // __HELLOWORLD_SCENE_H__
