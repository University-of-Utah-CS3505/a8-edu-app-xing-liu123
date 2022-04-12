#ifndef HITLISTENER_H
#define HITLISTENER_H

#include <Box2D/Box2D.h>


class HitListener: public b2ContactListener
{
public:
    HitListener();

    virtual void BeginContact(b2Contact* contact);
    virtual void EndContact(b2Contact* contact);
    virtual void PreSolve(b2Contact* contact, const b2Manifold* oldManifold);
    virtual void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse);
};

#endif // HITLISTENER_H
