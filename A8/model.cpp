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
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Model::updateSpear);
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
    //NOTE: Call get fish directly, rather than going to the vew to send it to the model again
    connect(contactListener,
            &HitListener::sendCollision,
            this,
            &Model::getFish);
    //Call to initialize the fishes (bodies)
    spearX = 400;
    spearY = 75;
    fish1X = 55;
    fish1Y = 300;
    fish2X = 55;
    fish2Y = 400;
    fish3X = 55;
    fish3Y = 500;
    initFish1();
    initFish2();
    initFish3();
    initSpear();
    timer->start(25);
}


//Initialize the fish to be at the top with the slowest velocity.
void Model::initFish1(){
    // Define the dynamic body (fish). We set its position and call the body factory.
    b2BodyDef bodyDef1;
    bodyDef1.type = b2_dynamicBody;
    bodyDef1.position.Set(0.55f, 3.0f); //-> Starting position of the fish
    fish1 = world->CreateBody(&bodyDef1);
    fish1->SetUserData((void*)1);

    //Give velocity to body (Slow)
    b2Vec2 velocity1(4.0f, 0.0f);
    fish1->SetLinearVelocity(velocity1);

    // Define another box shape for our dynamic body.
    b2PolygonShape dynamicFish;
    dynamicFish.SetAsBox(0.05f, 0.05f);


    // Define the dynamic body fixture.
    b2FixtureDef fixtureDefFish;

    fixtureDefFish.shape = &dynamicFish;


    // Set the box density to be non-zero, so it will be dynamic.
    fixtureDefFish.density = 0.1f;

    // Override the default friction.
    fixtureDefFish.friction = 0.3f;

    // Set the bounciness
    fixtureDefFish.restitution = 0.0f;
    fixtureDefFish.userData = (void*) 1;

    // Add the shape to the body.
    fish1->CreateFixture(&fixtureDefFish);

}


//Initialize the fish to be in the middle with the medium velocity.
void Model::initFish2(){
    // Define the dynamic body (fish). We set its position and call the body factory.
    b2BodyDef bodyDef2;
    bodyDef2.type = b2_dynamicBody;
    bodyDef2.position.Set(0.55f, 4.0f); //-> Starting position of the fish
    fish2 = world->CreateBody(&bodyDef2);

    //Give velocity to body (Medium)
    b2Vec2 velocity2(6.0f, 0.0f);
    fish2->SetLinearVelocity(velocity2);

    // Define another box shape for our dynamic body.
    b2PolygonShape dynamicFish;
    dynamicFish.SetAsBox(0.05f, 0.05f);


    // Define the dynamic body fixture.
    b2FixtureDef fixtureDefFish;

    fixtureDefFish.shape = &dynamicFish;

    // Set the box density to be non-zero, so it will be dynamic.
    fixtureDefFish.density = 0.1f;

    // Override the default friction.
    fixtureDefFish.friction = 0.3f;

    // Set the bounciness
    fixtureDefFish.restitution = 0.0f;
    fixtureDefFish.userData = (void*) 2;


    // Add the shape to the body.
    fish2->CreateFixture(&fixtureDefFish);
}

//Initialize the fish to be at the buttom with the fastest velocity..
void Model::initFish3(){
    // Define the dynamic body (fish). We set its position and call the body factory.
    b2BodyDef bodyDef3;
    bodyDef3.type = b2_dynamicBody;
    bodyDef3.position.Set(0.55f, 5.0f); //-> Starting position of the fish
    fish3 = world->CreateBody(&bodyDef3);

    //Give velocity to body (Fast)
    b2Vec2 velocity3(8.0f, 0.0f);
    fish3->SetLinearVelocity(velocity3);

    // Define another box shape for our dynamic body.
    b2PolygonShape dynamicFish;
    dynamicFish.SetAsBox(0.05f, 0.05f);

    // Define the dynamic body fixture.
    b2FixtureDef fixtureDefFish;

    fixtureDefFish.shape = &dynamicFish;


    // Set the box density to be non-zero, so it will be dynamic.
    fixtureDefFish.density = 0.1f;

    // Override the default friction.
    fixtureDefFish.friction = 0.3f;

    // Set the bounciness
    fixtureDefFish.restitution = 0.0f;
    fixtureDefFish.userData = (void*) 3;


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
    dynamicSpear.SetAsBox(0.01f, 0.575f);


    // Define the dynamic body fixture.
    b2FixtureDef fixtureDef;

    fixtureDef.shape = &dynamicSpear;

    // Set the box density to be non-zero, so it will be dynamic.
    fixtureDef.density = 1.0f;

    // Override the default friction.
    fixtureDef.friction = 0.3f;

    // Set the bounciness
    fixtureDef.restitution = 0.0f;
    fixtureDef.userData = (void*) 4;

    // Add the shape to the body.
    spear->CreateFixture(&fixtureDef);

}


void Model::shotSpear(int x, int y){
    isShot = true;
    float velocityX = 0;
    float velocityY = 0;
    float angle = 0;

    QImage rotated;
    QPixmap spearPix;

    if(y > 75){
        velocityX = x - 400;
        velocityY = y - 75;
        double radian = -atan(velocityX/velocityY);

        angle = radian*180 / M_PI;

        rotated = spearImage.transformed(QTransform().rotate(angle));
        spearPix = QPixmap::fromImage(rotated.scaled(150*(sin(abs(radian)) + cos(abs(radian))),150*(sin(abs(radian)) + cos(abs(radian)))));
    }
    else if(x <= 400){
        velocityX = -1;
        velocityY = 0;
        angle = 90;
        rotated = spearImage.transformed(QTransform().rotate(90));
        spearPix = QPixmap::fromImage(rotated.scaled(150, 150));
    }
    else{
        velocityX = 1;
        velocityY = 0;
        angle = -90;
        rotated = spearImage.transformed(QTransform().rotate(-90));
        spearPix = QPixmap::fromImage(rotated.scaled(150, 150));
    }


    emit sendSpearLabel(spearPix);

    // normolize the velocity
    b2Vec2 velocity(velocityX*sqrt(50/(pow(velocityX,2)+pow(velocityY,2))), velocityY*sqrt(50/(pow(velocityX,2)+pow(velocityY,2))));
    spear->SetLinearVelocity(velocity);
    spear->SetTransform(spear->GetPosition(), angle);
}

void Model::updateSpear(){
    int initXSpear = spearX - 75;
    int initYSpear = spearY - 75;
    int initXFish1 = fish1X - 55;
    int initYFish1 = fish1Y - 40;
    int initXFish2 = fish2X - 55;
    int initYFish2 = fish2Y - 40;
    int initXFish3 = fish3X - 55;
    int initYFish3 = fish3Y - 40;

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


    if(spearX <= 925 && spearX >= -125 && spearY <= 725 && spearY >= -125 ){
        emit setUpSpear(initXSpear, initYSpear, spearX - 75, spearY - 75);

    }
    else{
        emit setUpSpear(325, 0, 325, 0);
//        timer->stop();

        initSpear();
        spearX = 400;
        spearY = 75;


        QPixmap spearPix = QPixmap::fromImage(spearImage.scaled(150, 150));;

        emit resetSpear(spearPix);
        isShot = false;
    }

    //When the position of the fish is outside our window it will start again
    if(fish1->GetPosition().x > 9){
        b2Vec2 pos(-1.0f, 3.0f);
        fish1->SetTransform(pos,fish1->GetAngle());
    }

    // Now print the position and angle of the body.
    b2Vec2 posFish1 = fish1->GetPosition();
    fish1X= posFish1.x*100;
    fish1Y = posFish1.y*100;

    if(fish1X < initXFish1){
        emit setUpFish1(-125, 260, fish1X - 55, fish1Y - 40);
    }
    else{
        emit setUpFish1(initXFish1, initYFish1, fish1X - 55, fish1Y - 40);
    }

    //When the position of the fish is outside our window it will start again
    if(fish2->GetPosition().x > 9){
        b2Vec2 pos(-1.0f, 4.0f);
        fish2->SetTransform(pos,fish2->GetAngle());
    }

    // Now print the position and angle of the body.
    b2Vec2 posFish2 = fish2->GetPosition();
    fish2X= posFish2.x*100;
    fish2Y = posFish2.y*100;

    if(fish2X < initXFish2){
        emit setUpFish2(-125, 360, fish2X - 55, fish2Y - 40);
    }
    else{
        emit setUpFish2(initXFish2, initYFish2, fish2X - 55, fish2Y - 40);
    }

    //When the position of the fish is outside our window it will start again
    if(fish3->GetPosition().x > 9){
        b2Vec2 pos(-1.0f, 5.0f);
        fish3->SetTransform(pos,fish3->GetAngle());
    }

    // Now print the position and angle of the body.
    b2Vec2 posFish3 = fish3->GetPosition();
    fish3X= posFish3.x*100;
    fish3Y = posFish3.y*100;

    if(fish3X < initXFish3){
        emit setUpFish3(-125, 460, fish3X - 55, fish3Y - 40);
    }
    else{
        emit setUpFish3(initXFish3, initYFish3, fish3X - 55, fish3Y - 40);
    }
}

void Model::setSpearLabel(int x, int y){
    if(!isShot){
        QImage rotated;
        QPixmap spearPix;

        if(y > 75){
            double velocityX = x - 400;
            double velocityY = y - 75;
            double radian = -atan(velocityX/velocityY);
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
//        std::cout << count++ << std::endl;
        //        std::cout << str.value("What is my Name?").toStdString() << std::endl;
        //        std::cout << str.value("How big can I get?").toStdString() << std::endl;
        //        std::cout << str.value("Where can you find me?").toStdString() << std::endl;
//        std::cout << str.value("filepath").toStdString() <<std::endl;
    }
}



//***********Quiz************************
//Once the Spear has crashed with a fish, the you call this method
void Model::getFish(){
    //loadInfoQ();

    int randNum = rand()%10;
    QString currFish;
    QString waterL;

    if(waterType == TypeOfWater::TOW_SaltWater){
        currFish = saltFish[randNum];
        waterL = "s";
    }
    else if(waterType == TypeOfWater::TOW_SmoothWater){
        currFish = smoothFish[randNum];
         waterL = "r";
    }
    else if(waterType == TypeOfWater::TOW_FreshWater){
        currFish = freshFish[randNum];
         waterL = "p";
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
        QString randAsnw1 = getRandAnswer(questionNum,question, answer);
        QString randAsnw2 = getRandAnswer(questionNum, question, answer);
        emit updateQuiz(question, answer, randAsnw1, randAsnw2,  fishPic, currFish);
    }
    //If it is not catched
    else{
        catchedFish.insert(currFish, 1);
        //send all infomation of the fish
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

        //Information to set up journal
         emit updateJournal(randNum, waterL, answer1, answer2,
                            answer3, answer4, currFish, fishPic);


    }

}


//Helper method that gets a random answer based on the question
QString Model::getRandAnswer(int questionNum, QString question,  QString answer){
    //get a random fish
    QString randFish = getRandFish();
    QString randAnsw;

    //Based on our question number (The question we did)
    //We will get the answer of
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

    //if my answer is the same as my current answer, then repeat method
    return randAnsw != answer? randAnsw: getRandAnswer(questionNum, question, answer);
}

//Checks user answer
void Model::checkAnswer(QString question, QString userAnswer){

    QString correctAnswer = fishQA.value(currFish).value(question);

    if(correctAnswer == userAnswer)
        emit answerResult(true);
    else
        emit answerResult(false);
}

//Helper method to get a random fish from the water type we are currently in
QString Model::getRandFish(){
    int randNum = rand()%10;
    QString randFish;

    if(waterType == TypeOfWater::TOW_SaltWater)
        randFish = saltFish[randNum];
    else if(waterType == TypeOfWater::TOW_SmoothWater)
        randFish = smoothFish[randNum];
    else if(waterType == TypeOfWater::TOW_FreshWater)
        randFish = freshFish[randNum];

    //if my fish is the same as my current fish, then repeat method
    return randFish != currFish? randFish: getRandFish();
}

//*********** Code for Testing *********************

//TESTING Code for quiz and Information WIndow
//INFORMATION TESTING
void Model::getTestInfoFish(){
    QString fish;
    if(waterType == TypeOfWater::TOW_SaltWater)
        fish = saltFish[currInfo];
    else if(waterType == TypeOfWater::TOW_SmoothWater)
        fish = smoothFish[currInfo];
    else if(waterType == TypeOfWater::TOW_FreshWater)
        fish = freshFish[currInfo];
    QString fishPic = fishQA.value(fish).value("filepath");

    //send all infomation of the fish
    QString question1 = "What is my Name?";
    QString answer1 = fishQA.value(fish).value(question1);

    QString question2  = "How big can I get?";
    QString answer2 = fishQA.value(fish).value(question2);

    QString question3  = "Where can you find me?";
    QString answer3 = fishQA.value(fish).value(question3);

    QString question4  = "Am I an endangered species?";
    QString answer4 = fishQA.value(fish).value(question4);

    if(currInfo < 9)
        currInfo++;
    else
        currInfo = 0;

    emit updateInformation(question1, answer1, question2, answer2,
                           question3, answer3, question4, answer4,
                           fish, fishPic);
}


//QUIZ TESTING
void Model::getTestQuizInfo(){
    QString question;
    QString answer;
    QString fish;
    if(waterType == TypeOfWater::TOW_SaltWater)
        fish = saltFish[currQuiz];
    else if(waterType == TypeOfWater::TOW_SmoothWater)
        fish = smoothFish[currQuiz];
    else if(waterType == TypeOfWater::TOW_FreshWater)
        fish = freshFish[currQuiz];
    QString fishPic = fishQA.value(fish).value("filepath");

    //Get the question and aswer
    switch(qNum){
    case 0:
        question = "What is my Name?";
        answer = fishQA.value(fish).value(question);
        break;
    case 1:
        question = "How big can I get?";
        answer = fishQA.value(fish).value(question);
        break;
    case 2:
        question = "Where can you find me?";
        answer = fishQA.value(fish).value(question);
        break;
    case 3:
        question = "Am I an endangered species?";
        answer = fishQA.value(fish).value(question);
        break;
    }

    //send to method to get two other random values of fish
    QString randAsnw1 = getRandAnswer(qNum,question, answer);
    QString randAsnw2 = getRandAnswer(qNum, question, answer);


    //Counter of questions
    if(qNum < 3)
        qNum++;
    else
        qNum = 0;
    //COunter of fish
    if(currQuiz < 10 && qNum ==0)
        currQuiz++;
    else if(currQuiz >= 10 && qNum == 0)
        currQuiz = 0;

    emit updateQuiz(question, answer, randAsnw1, randAsnw2,  fishPic, fish);

}
