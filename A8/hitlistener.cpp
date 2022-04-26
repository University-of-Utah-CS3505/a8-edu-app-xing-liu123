/**
 * Team: BAGJL
 * Students: Brittney Morales, Adriana Salazar, Xing Liu, Jinwen Lei, Gonzalo Tello
 * Course: CS3505
 * Date: April 26, 2022
 *
 **/

#include "hitlistener.h"

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

    destroy = true;

    emit sendCollision();
}
