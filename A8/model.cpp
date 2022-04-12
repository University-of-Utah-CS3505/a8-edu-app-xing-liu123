#include "model.h"
#include <iostream>
#include <QFile>
#include <QTextStream>


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
    // Create contact listener
    contactListener = new HitListener();
    world->SetContactListener(contactListener);
    //Call to initialize the fishes (bodies)
    spearX = 400;
    spearY = 0;
    initFish1();
    initFish2();
    initFish3();
    initSpear();
    emit startTime();
}


//Initialize the fish to be at the top with the slowest velocity.
void Model::initFish1(){
    // Define the dynamic body (fish). We set its position and call the body factory.
    b2BodyDef bodyDef1;
    bodyDef1.type = b2_dynamicBody;
    bodyDef1.position.Set(0.0f, 3.0f); //-> Starting position of the fish
    fish1 = world->CreateBody(&bodyDef1);

    //Give velocity to body (Slow)
    b2Vec2 velocity1(4.0f, 0.0f);
    fish1->SetLinearVelocity(velocity1);

    // Define another box shape for our dynamic body.
    b2PolygonShape dynamicFish;
    dynamicFish.SetAsBox(1.0f, 0.1f);


    // Define the dynamic body fixture.
    b2FixtureDef fixtureDefFish;

    fixtureDefFish.shape = &dynamicFish;


    // Set the box density to be non-zero, so it will be dynamic.
    fixtureDefFish.density = 0.1f;

    // Override the default friction.
    fixtureDefFish.friction = 0.3f;

    // Set the bounciness
    fixtureDefFish.restitution = 0.0f;

    // Add the shape to the body.
    fish1->CreateFixture(&fixtureDefFish);

}


//Initialize the fish to be in the middle with the medium velocity.
void Model::initFish2(){
    // Define the dynamic body (fish). We set its position and call the body factory.
    b2BodyDef bodyDef2;
    bodyDef2.type = b2_dynamicBody;
    bodyDef2.position.Set(0.0f, 4.0f); //-> Starting position of the fish
    fish2 = world->CreateBody(&bodyDef2);

    //Give velocity to body (Medium)
    b2Vec2 velocity2(6.0f, 0.0f);
    fish2->SetLinearVelocity(velocity2);

    // Define another box shape for our dynamic body.
    b2PolygonShape dynamicFish;
    dynamicFish.SetAsBox(1.0f, 0.1f);


    // Define the dynamic body fixture.
    b2FixtureDef fixtureDefFish;

    fixtureDefFish.shape = &dynamicFish;


    // Set the box density to be non-zero, so it will be dynamic.
    fixtureDefFish.density = 0.1f;

    // Override the default friction.
    fixtureDefFish.friction = 0.3f;

    // Set the bounciness
    fixtureDefFish.restitution = 0.0f;

    // Add the shape to the body.
    fish2->CreateFixture(&fixtureDefFish);
}

//Initialize the fish to be at the buttom with the fastest velocity..
void Model::initFish3(){
    // Define the dynamic body (fish). We set its position and call the body factory.
    b2BodyDef bodyDef3;
    bodyDef3.type = b2_dynamicBody;
    bodyDef3.position.Set(0.0f, 5.0f); //-> Starting position of the fish
    fish3 = world->CreateBody(&bodyDef3);

    //Give velocity to body (Fast)
    b2Vec2 velocity3(8.0f, 0.0f);
    fish3->SetLinearVelocity(velocity3);

    // Define another box shape for our dynamic body.
    b2PolygonShape dynamicFish;
    dynamicFish.SetAsBox(1.0f, 0.1f);


    // Define the dynamic body fixture.
    b2FixtureDef fixtureDefFish;

    fixtureDefFish.shape = &dynamicFish;


    // Set the box density to be non-zero, so it will be dynamic.
    fixtureDefFish.density = 0.1f;

    // Override the default friction.
    fixtureDefFish.friction = 0.3f;

    // Set the bounciness
    fixtureDefFish.restitution = 0.0f;

    // Add the shape to the body.
    fish3->CreateFixture(&fixtureDefFish);
}

void Model::initSpear(){
    b2BodyDef bodySpearDef;
    bodySpearDef.type = b2_dynamicBody;
    bodySpearDef.position.Set(4.0f, 0.0f);
    spear = world->CreateBody(&bodySpearDef);

    b2Vec2 velocity(0.0f, 5.0f);
    spear->SetLinearVelocity(velocity);

    // Define another box shape for our dynamic body.
    b2PolygonShape dynamicSpear;
    dynamicSpear.SetAsBox(1.0f, 1.0f);


    // Define the dynamic body fixture.
    b2FixtureDef fixtureDef;

    fixtureDef.shape = &dynamicSpear;


    // Set the box density to be non-zero, so it will be dynamic.
    fixtureDef.density = 1.0f;

    // Override the default friction.
    fixtureDef.friction = 0.3f;

    // Set the bounciness
    fixtureDef.restitution = 0.0f;

    // Add the shape to the body.
    spear->CreateFixture(&fixtureDef);
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
    if(fish1->GetPosition().x > 9){
        b2Vec2 pos(-1.0f, 3.0f);
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
    if(fish2->GetPosition().x > 9){
        b2Vec2 pos(-1.0f, 4.0f);
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
    if(fish3->GetPosition().x > 9){
        b2Vec2 pos(-1.0f, 5.0f);
        fish3->SetTransform(pos,fish3->GetAngle());
    }

    // Now print the position and angle of the body.
    b2Vec2 position = fish3->GetPosition();
    emit setUpFish3(position.x, position.y);
}

void Model::startTimer(){
    QTimer *timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &Model::updateSpear);
        timer->start(100);
}

void Model::updateSpear(){

    int initX = spearX;
    int initY = spearY;

    // Prepare for simulation. Typically we use a time step of 1/60 of a
    // second (60Hz) and 10 iterations. This provides a high quality simulation
    // in most game scenarios.
    float32 timeStep = 1.0f / 60.0f;
    int32 velocityIterations = 6;
    int32 positionIterations = 2;

    // Instruct the world to perform a single step of simulation.
    // It is generally best to keep the time step and iterations fixed.
    world->Step(timeStep, velocityIterations, positionIterations);

    // Now print the position and angle of the body.
    b2Vec2 finalPos = spear->GetPosition();
    spearX= finalPos.x*100;
    spearY = finalPos.y*100;

    std::cout << "Initial: " << initX << " " << initY <<" Final: "<< spearX <<" " << spearY << std::endl;

    emit setUpSpear(initX, initY, spearX, spearY);
}

void Model::loadInfoQ(){
    QFile inputFile(QString(":/fishQuestionAnswers.txt"));
    if (inputFile.open(QIODevice::ReadOnly))
    {
       QTextStream in(&inputFile);

       int count = 0;
       QString line;
       QString currentFish;
       QMap<QString,QString> test;
       while (!in.atEnd())
       {
           line = in.readLine();
          if(count == 0)
          {
              currentFish = line;
              count++;
          }

          else if(line.contains("What is my Name?"))
          {
              line = line.trimmed().split(":")[1];
              test.insert("What is my Name?", line);
              count++;
          }
          else if(line.contains("How big can I get?"))
          {
              line = line.trimmed().split(":")[1];
              test.insert("How big can I get?", line);
              count++;
          }
          else if(line.contains("Where can you find me?"))
          {
              line = line.trimmed().split(":")[1];
              test.insert("Where can you find me?", line);
              count++;
          }
          else if(line.contains("Am I an endangered species?"))
          {
              line = line.trimmed().split(":")[1];
              test.insert("Am I an endangered species?", line);
              fishQA.insert(currentFish, test);
              count = 0;
              test.clear();
          }
       }

       inputFile.close();
    }

    //for testing purposes
//    for(QMap<QString,QString> str: fishQA.values())
//    {
//        std::cout << str.value("What is my Name?").toStdString() << std::endl;
//        std::cout << str.value("How big can I get?").toStdString() << std::endl;
//        std::cout << str.value("Where can you find me?").toStdString() << std::endl;
//    }
}
