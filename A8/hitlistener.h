#ifndef HITLISTENER_H
#define HITLISTENER_H

#include <Box2D/Box2D.h>
#include <QObject>


class HitListener: public QObject, public b2ContactListener
{
    Q_OBJECT

public:
    HitListener();

    virtual void BeginContact(b2Contact* contact);
//    virtual void EndContact(b2Contact* contact);
//    virtual void PreSolve(b2Contact* contact, const b2Manifold* oldManifold);
//    virtual void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse);

signals:
    void sendCollision();

};

#endif // HITLISTENER_H
