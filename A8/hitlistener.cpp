#include "hitlistener.h"
#include <iostream>

HitListener::HitListener()
{

}

void HitListener::BeginContact(b2Contact* contact) {
    std::cout << "hit" << std::endl;
    emit sendCollision();
}

//void HitListener::EndContact(b2Contact* contact) {
//    //std::cout << "hit" << std::endl;

//}

//void HitListener::PreSolve(b2Contact* contact,
//  const b2Manifold* oldManifold) {
//    //std::cout << "hit" << std::endl;

//}

//void HitListener::PostSolve(b2Contact* contact,
//  const b2ContactImpulse* impulse) {
//    //std::cout << "hit" << std::endl;

//}
