#ifndef HITLISTENER_H
#define HITLISTENER_H

#include <Box2D/Box2D.h>
#include <QObject>
#include <vector>


class HitListener: public QObject, public b2ContactListener
{
    Q_OBJECT

public:
    HitListener();
    bool destroy = false;
    std::vector<b2Body*> getBodyVector();
    bool getDestroy();
    void setDestroy(bool);
    //create some vector that holds
    std::vector<b2Body*> bodiesToRemove;
    virtual void BeginContact(b2Contact* contact);
    virtual void EndContact(b2Contact* contact);
    virtual void PreSolve(b2Contact* contact, const b2Manifold* oldManifold);
//    virtual void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse);

signals:
    void sendCollision();

};

#endif // HITLISTENER_H
