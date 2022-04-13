#include "model.h"
#include <iostream>
#include <QFile>
#include <QTextStream>
#include <QImage>
#include <QPixmap>


Model::Model(QObject *parent)
    : QObject{parent}
{
    loadInfoQ();
    spearImage.load(":/spear.png");
    isShot = false;
}

Model::~Model(){
    delete world;
}


void Model::setUpWorld(QString water){

    if(water.contains("Salt"))
        waterType = TypeOfWater::TOW_SaltWater;
    if(water.contains("Fresh"))
        waterType = TypeOfWater::TOW_FreshWater;
    if(water.contains("Smooth"))
        waterType = TypeOfWater::TOW_SmoothWater;

    // Define the gravity vector.
    b2Vec2 gravity(0.0f, 0.0f);
    // Construct a world object, which will hold and simulate the rigid bodies.
    world = new b2World(gravity);
    // Create contact listener
    contactListener = new HitListener();
    world->SetContactListener(contactListener);
    connect(contactListener,
            &HitListener::sendCollision,
            this,
            &Model::notifyCollision);
    //Call to initialize the fishes (bodies)
    spearX = 400;
    spearY = 75;
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
    bodySpearDef.position.Set(4.00f, 0.75f);
    spear = world->CreateBody(&bodySpearDef);

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

void Model::startTimer(int x, int y){
    isShot = true;
    float velocityX = 0;
    float velocityY = 0;
    float angle = 0;

    if(y > 75){
        velocityX = x - 400;
        velocityY = y - 75;
        angle = -atan(x/y)*180 / M_PI;
    }
    else if(x <= 400){
        velocityX = -1;
        velocityY = 0;
        angle = 90;
    }
    else{
        velocityX = 1;
        velocityY = 0;
        angle = -90;
    }

    // normolize the velocity
    b2Vec2 velocity(velocityX*sqrt(50/(pow(velocityX,2)+pow(velocityY,2))), velocityY*sqrt(50/(pow(velocityX,2)+pow(velocityY,2))));
    spear->SetLinearVelocity(velocity);
    spear->SetTransform(spear->GetPosition(), angle);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Model::updateSpear);
    timer->start(100);
}

void Model::notifyCollision()
{
    emit sendCollision();
}

void Model::updateSpear(){
    int initX = spearX - 75;
    int initY = spearY - 75;

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

    emit setUpSpear(initX, initY, spearX - 75, spearY - 75);
}

void Model::setSpearLabel(int x, int y){
    if(!isShot){
        QImage rotated;
        QPixmap spearPix;

        if(y > 75){
            double deltaX = x - 400;
            double deltaY = y - 75;
            double radian = -atan(deltaX/deltaY);
            double angle = radian*180 / M_PI;

            rotated = spearImage.transformed(QTransform().rotate(angle));
            spearPix = QPixmap::fromImage(rotated.scaled(150*(sin(abs(radian)) + cos(abs(radian))),150*(sin(abs(radian)) + cos(abs(radian)))));
        }
        else if(x <= 400){
            rotated = spearImage.transformed(QTransform().rotate(90));
            spearPix = QPixmap::fromImage(rotated.scaled(150, 150));
        }
        else{
            rotated = spearImage.transformed(QTransform().rotate(-90));
            spearPix = QPixmap::fromImage(rotated.scaled(150, 150));
        }

        emit sendSpearLabel(spearPix);
    }
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
           //Changed this since it was reading white space
          if(count == -1){
               count++;
           }
          else if(count == 0)
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

          }
          else if(line.contains("filepath"))
          {
              line = line.trimmed().split(" ")[1];
              test.insert("filepath", line);
              fishQA.insert(currentFish, test);
              count = -1;
              test.clear();
          }
       }

       inputFile.close();
    }

    //for testing purposes
    int count = 1;
    for(QMap<QString,QString> str: fishQA.values())
    {
        std::cout << count++ << std::endl;
//        std::cout << str.value("What is my Name?").toStdString() << std::endl;
//        std::cout << str.value("How big can I get?").toStdString() << std::endl;
//        std::cout << str.value("Where can you find me?").toStdString() << std::endl;
        std::cout << str.value("filepath").toStdString() <<std::endl;
    }
}



//***********Quiz************************
//Once the Spear has crashed with a fish, the you call this method
void Model::getFish(){
    loadInfoQ();

    //Set up a randum number for the fish
    int randNum = rand()%10;
    //Assign a random fish to our current fish depending on the water we are at
   if(waterType == TypeOfWater::TOW_FreshWater){
        currFish = freshFish[randNum];
   }
   else if(waterType == TypeOfWater::TOW_SmoothWater){
        currFish = smoothFish[randNum];
   }
   else if(waterType == TypeOfWater::TOW_SaltWater){
        currFish = saltFish[randNum];
   }

    //Read the picture file
    QString fishPic = fishQA.value(currFish).value("filepath");


    //Check if is in the list of catched fish
    if(catchedFish.contains(currFish)){
        QString question;
        QString answer;

        //if it is then check how many times it has been catched
        //and get the %4 num to get the questionString
        int questionNum = catchedFish[currFish] % 4; //returns 0,1,2,3
        //update the value
        catchedFish[currFish]++;

        //Get the question and aswer
        switch(questionNum){
        case 0:
            question = "What is my Name?";
            answer = fishQA.value(currFish).value(question);
            break;
        case 1:
            question = "How big can I get?";
            answer = fishQA.value(currFish).value(question);
            break;
        case 2:
            question = "Where can you find me?";
            answer = fishQA.value(currFish).value(question);
            break;
        case 3:
            question = "Am I an endangered species?";
            answer = fishQA.value(currFish).value(question);
            break;
        }

        //send to method to get two other random values of fish
        QString randAsnw1 = getRandAnswers(questionNum,question, answer);
        QString randAsnw2 = getRandAnswers(questionNum, question, answer);
        emit updateQuiz(question, answer, randAsnw1, randAsnw2,  fishPic, currFish);
    }
    //If it is not catched
    else{
        catchedFish.insert(currFish, 1);
       //send all infomation of the fish
        //TODO: send picture of fish file name
        QString question1 = "What is my Name?";
        QString answer1 = fishQA.value(currFish).value(question1);

        QString question2  = "How big can I get?";
        QString answer2 = fishQA.value(currFish).value(question2);

        QString question3  = "Where can you find me?";
        QString answer3 = fishQA.value(currFish).value(question3);

        QString question4  = "Am I an endangered species?";
        QString answer4 = fishQA.value(currFish).value(question4);

        emit updateInformation(question1, answer1, question2, answer2,
                               question3, answer3, question4, answer4,
                               currFish, fishPic);

        }

}


//Helper method that gets a random answer based on the question
QString Model::getRandAnswers(int questionNum, QString question,  QString answer){
   int randNum = rand()%10;
   QString randFish;
   QString randAnsw;

   //TODO: check that is not the same fish
    if(waterType == TypeOfWater::TOW_SaltWater)
       randFish = saltFish[randNum];
    else if(waterType == TypeOfWater::TOW_SmoothWater)
       randFish = smoothFish[randNum];
    else if(waterType == TypeOfWater::TOW_FreshWater)
       randFish = freshFish[randNum];


    switch(questionNum){
    case 0:
        randAnsw = fishQA.value(randFish).value(question);
        break;
    case 1:
        randAnsw = fishQA.value(randFish).value(question);
        break;
    case 2:
       randAnsw = fishQA.value(randFish).value(question);
        break;
    case 3:
        randAnsw = fishQA.value(randFish).value(question);
        break;
    }
    return randAnsw;
}


