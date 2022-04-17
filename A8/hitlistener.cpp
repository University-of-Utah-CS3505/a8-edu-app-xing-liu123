#include "hitlistener.h"
#include <iostream>

HitListener::HitListener()
{

}

std::vector<b2Body*> HitListener::getBodyVector()
{
    return bodiesToRemove;
}

bool HitListener::getDestroy()
{
    return destroy;
}

void HitListener::setDestroy(bool incomingBool)
{
    destroy = incomingBool;
}

void HitListener::BeginContact(b2Contact* contact) {
    // fishes
    void* fixtureUserDataA = contact->GetFixtureA()->GetUserData();
    // spear
    void* fixtureUserDataB = contact->GetFixtureB()->GetUserData();

    // if the fixture is an object and that object is fish 1
    if(contact->GetFixtureA() != nullptr && (int)(size_t) fixtureUserDataA == 1){
        //TODO
        std::cout << "hit fish 1" << std::endl;
    }
    // if the fixture is an object and that object is fish 2
    if(contact->GetFixtureA() != nullptr && (int)(size_t) fixtureUserDataA == 2){
        //TODO
        std::cout << "hit fish 2" << std::endl;
    }
    // if the fixture is an object and that object is fish 3
    if(contact->GetFixtureA() != nullptr && (int)(size_t) fixtureUserDataA == 3){
        //TODO
        std::cout << "hit fish 3" << std::endl;
    }
    destroy = true;
    emit sendCollision();
}

void HitListener::EndContact(b2Contact* contact) {

}

void HitListener::PreSolve(b2Contact* contact,
  const b2Manifold* oldManifold) {
//    //std::cout << "hit" << std::endl;
//    b2Fixture* fixtureA = contact->GetFixtureA();
//    b2Fixture* fixtureB = contact->GetFixtureB();
//    //b2Body* fABody = fixtureA->GetBody();
//    b2Body* fBBody = fixtureB->GetBody();
//    //bodiesToRemove.push_back(fABody);
//    bodiesToRemove.push_back(fBBody);

//    emit sendCollision();
}

//void HitListener::PostSolve(b2Contact* contact,
//  const b2ContactImpulse* impulse) {
//    //std::cout << "hit" << std::endl;

//}
