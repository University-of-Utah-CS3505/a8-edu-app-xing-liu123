#include "model.h"


Model::Model(QObject *parent)
    : QObject{parent}
{

}

Model::~Model(){
    delete world;
}


void Model::setUpWorld(){
    // Define the gravity vector.
    b2Vec2 gravity(0.0f, 0.0f);
    // Construct a world object, which will hold and simulate the rigid bodies.
    world = new b2World(gravity);
    //Call to initialize the fishes (bodies)
    initFish1();
    initFish2();
    initFish3();
    emit startTime();
}


//Initialize the fish to be at the top with the slowest velocity.
void Model::initFish1(){
    // Define the dynamic body (fish). We set its position and call the body factory.
    b2BodyDef bodyDef1;
    bodyDef1.type = b2_dynamicBody;
    bodyDef1.position.Set(3.0f, 0.0f); //-> Starting position of the fish
    fish1 = world->CreateBody(&bodyDef1);

    //Give velocity to body (Slow)
    b2Vec2 velocity1(0.0f, 4.0f);
    fish1->SetLinearVelocity(velocity1);

}


//Initialize the fish to be in the middle with the medium velocity.
void Model::initFish2(){
    // Define the dynamic body (fish). We set its position and call the body factory.
    b2BodyDef bodyDef2;
    bodyDef2.type = b2_dynamicBody;
    bodyDef2.position.Set(4.0f, 0.0f); //-> Starting position of the fish
    fish2 = world->CreateBody(&bodyDef2);

    //Give velocity to body (Medium)
    b2Vec2 velocity2(0.0f, 6.0f);
    fish2->SetLinearVelocity(velocity2);
}

//Initialize the fish to be at the buttom with the fastest velocity..
void Model::initFish3(){
    // Define the dynamic body (fish). We set its position and call the body factory.
    b2BodyDef bodyDef3;
    bodyDef3.type = b2_dynamicBody;
    bodyDef3.position.Set(5.0f, 0.0f); //-> Starting position of the fish
    fish3 = world->CreateBody(&bodyDef3);

    //Give velocity to body (Fast)
    b2Vec2 velocity3(0.0f, 8.0f);
    fish3->SetLinearVelocity(velocity3);
}


void Model::updateFish1(){
    // Prepare for simulation. Typically we use a time step of 1/60 of a
    // second (60Hz) and 10 iterations. This provides a high quality simulation
    // in most game scenarios.
    float32 timeStep = 1.0f / 60.0f;
    int32 velocityIterations = 6;
    int32 positionIterations = 2;

    // Instruct the world to perform a single step of simulation.
    // It is generally best to keep the time step and iterations fixed.
    world->Step(timeStep, velocityIterations, positionIterations);


    //When the position of the fish is outside our window it will start again
    if(fish1->GetPosition().y > 9){
        b2Vec2 pos(3.0f, -1.0f);
        fish1->SetTransform(pos,fish1->GetAngle());
    }

    // Now print the position and angle of the body.
    b2Vec2 position = fish1->GetPosition();
    emit setUpFish1(position.x, position.y);

}

void Model::updateFish2(){
    // Prepare for simulation. Typically we use a time step of 1/60 of a
    // second (60Hz) and 10 iterations. This provides a high quality simulation
    // in most game scenarios.
    float32 timeStep = 1.0f / 60.0f;
    int32 velocityIterations = 6;
    int32 positionIterations = 2;

    // Instruct the world to perform a single step of simulation.
    // It is generally best to keep the time step and iterations fixed.
    world->Step(timeStep, velocityIterations, positionIterations);

    //When the position of the fish is outside our window it will start again
    if(fish2->GetPosition().y > 9){
        b2Vec2 pos(4.0f, -1.0f);
        fish2->SetTransform(pos,fish2->GetAngle());
    }

    // Now print the position and angle of the body.
    b2Vec2 position = fish2->GetPosition();
    emit setUpFish2(position.x, position.y);
}


void Model::updateFish3(){
    // Prepare for simulation. Typically we use a time step of 1/60 of a
    // second (60Hz) and 10 iterations. This provides a high quality simulation
    // in most game scenarios.
    float32 timeStep = 1.0f / 60.0f;
    int32 velocityIterations = 6;
    int32 positionIterations = 2;

    // Instruct the world to perform a single step of simulation.
    // It is generally best to keep the time step and iterations fixed.
    world->Step(timeStep, velocityIterations, positionIterations);

    //When the position of the fish is outside our window it will start again
    if(fish3->GetPosition().y > 9){
        b2Vec2 pos(5.0f, -1.0f);
        fish3->SetTransform(pos,fish3->GetAngle());
    }

    // Now print the position and angle of the body.
    b2Vec2 position = fish3->GetPosition();
    emit setUpFish3(position.x, position.y);
}
