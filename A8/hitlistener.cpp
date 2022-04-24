#include "hitlistener.h"
#include <iostream>

/**
 * @brief HitListener::HitListener
 * Hitlistener class that detects collision between two different
 * b2 body, fixture, id.  Can then use that information to to determine
 * which objects have collided and act accordingly
 */
HitListener::HitListener()
{
}

/**
 * @brief HitListener::getBodyVector
 * Vector of all bodies that are awaiting destruction after the world steps
 * so that it will delete accordingly
 * @return list of objects to be destroyed
 */
std::vector<b2Body*> HitListener::getBodyVector()
{
    return bodiesToRemove;
}

/**
 * @brief HitListener::getDestroy
 * Getter for the destroyed bodies for the current step
 * @return True if needs to destroy | False if not
 */
bool HitListener::getDestroy()
{
    return destroy;
}

/**
 * @brief HitListener::setDestroy
 * Setter for the destroyed bodies for the current step
 * @param incomingBool - set Boolean
 */
void HitListener::setDestroy(bool incomingBool)
{
    destroy = incomingBool;
}

/**
 * @brief HitListener::BeginContact
 * Used to represent collision as soon as two bodies make contact
 * has a contactt parameter that contains both those bodies. that
 * are sent from the model. Has options for detecting three of the
 * fishes displayed in othe game.
 * @param contact
 */
void HitListener::BeginContact(b2Contact* contact) {
    // fishes
    void* fixtureUserDataA = contact->GetFixtureA()->GetUserData();
    // spear
    void* fixtureUserDataB = contact->GetFixtureB()->GetUserData();

    // if the fixture is an object and that object is fish 1
    if(contact->GetFixtureA() != nullptr && (int)(size_t) fixtureUserDataA == 1){
        std::cout << "hit fish 1" << std::endl;
    }
    // if the fixture is an object and that object is fish 2
    if(contact->GetFixtureA() != nullptr && (int)(size_t) fixtureUserDataA == 2){
        std::cout << "hit fish 2" << std::endl;
    }
    // if the fixture is an object and that object is fish 3
    if(contact->GetFixtureA() != nullptr && (int)(size_t) fixtureUserDataA == 3){
        std::cout << "hit fish 3" << std::endl;
    }
    destroy = true;
    emit sendCollision();
}
