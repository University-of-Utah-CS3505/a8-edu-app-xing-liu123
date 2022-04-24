#include "model.h"
#include <iostream>
#include <QFile>
#include <QTextStream>
#include <QImage>
#include <QPixmap>
#include <QVector>

Model::Model(QObject *parent)
    : QObject{parent}
{
    loadInfoQ();
    currentSpear = 1;
    isShot = false;
    timer = new QTimer(this);
    quizTimer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Model::updateWorld);
    connect(quizTimer, &QTimer::timeout, this, &Model::updateQuizTime);

    correctAnsw = 0;
    quizTimeCounter =10;
}

Model::~Model(){
    delete world;
}

// set up the physical world
void Model::setUpWorld(QString water){

    if(water.contains("Salt"))
        waterType = TypeOfWater::TOW_SeaWater;
    if(water.contains("Fresh"))
        waterType = TypeOfWater::TOW_PondWater;
    if(water.contains("Smooth"))
        waterType = TypeOfWater::TOW_RiverWater;

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

    initFish1();
    initFish2();
    initFish3();
    initSpear();

    // start the world imitation
    timer->start(25);
}


//Initialize the fish to be at the top with the slowest velocity.
void Model::initFish1(){
    fish1X = 55;
    fish1Y = 300;

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
    dynamicFish.SetAsBox(0.22f, 0.12f);

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
    fish2X = 55;
    fish2Y = 400;

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
    dynamicFish.SetAsBox(0.22f, 0.12f);

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

//Initialize the fish to be at the buttom with the fastest velocity.
void Model::initFish3(){
    fish3X = 55;
    fish3Y = 500;

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
    dynamicFish.SetAsBox(0.22f, 0.12f);

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

// initialize the spear based on the current spear
void Model::initSpear(){
    switch(currentSpear){
        case 1:
            spearImage.load(":/spear4.png");
            break;
        case 2:
            spearImage.load(":/spear2.png");
            break;
        case 3:
            spearImage.load(":/spear3.png");
            break;
        case 4:
            spearImage.load(":/spear4.png");
            break;
    }

    // center of spear on the window
    spearX = 400;
    spearY = 75;

    b2BodyDef bodySpearDef;
    bodySpearDef.type = b2_dynamicBody;

    // center of spear in the world
    bodySpearDef.position.Set(4.00f, 0.75f);
    spear = world->CreateBody(&bodySpearDef);

    // Define another box shape for our dynamic body.
    b2PolygonShape dynamicSpear;

    // give different collision box size to different spears
    switch(currentSpear){
        case 1:
            dynamicSpear.SetAsBox(0.012f, 0.45f);
            break;
        case 2:
            dynamicSpear.SetAsBox(0.014f, 0.47f);
            break;
        case 3:
            dynamicSpear.SetAsBox(0.016f, 0.49f);
            break;
        case 4:
            dynamicSpear.SetAsBox(0.018f, 0.51f);
            break;
    }

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

// shot the spear based on the position clicked by the player
void Model::shotSpear(int x, int y){
    // ignore action if it is moving
    if(isShot){
        return;
    }

    isShot = true;

    float velocityX = 0;
    float velocityY = 0;
    float angle = 0;
    float radian = 0;

    QImage rotated;
    QPixmap spearPix;

    // if target is below the position of character, it will be shot at the angle based on the target position
    if(y > 75){
        velocityX = x - 400;
        velocityY = y - 75;

        radian = -atan(velocityX/velocityY);
        angle = radian*180 / M_PI;

        rotated = spearImage.transformed(QTransform().rotate(angle));
        spearPix = QPixmap::fromImage(rotated.scaled(150*(sin(abs(radian)) + cos(abs(radian))),150*(sin(abs(radian)) + cos(abs(radian)))));
    }
    // if target is above the position of character, it will be shot horizontally to the left
    else if(x <= 400){
        velocityX = -1;
        velocityY = 0;

        // rotate 90 degrees to the left
        angle = 90;
        radian = 0.5*M_PI;

        rotated = spearImage.transformed(QTransform().rotate(angle));
        spearPix = QPixmap::fromImage(rotated.scaled(150, 150));
    }
    // if target is above the position of character, it will be shot horizontally to the right
    else{
        velocityX = 1;
        velocityY = 0;

        // rotate 90 degrees to the left
        angle = -90;
        radian = -0.5*M_PI;

        rotated = spearImage.transformed(QTransform().rotate(angle));
        spearPix = QPixmap::fromImage(rotated.scaled(150, 150));
    }

    emit sendSpearLabel(spearPix);

    b2Vec2 velocity;

    // different spears have different speeds
    switch(currentSpear){
        case 1:
            velocity = b2Vec2(velocityX*sqrt(50/(pow(velocityX,2)+pow(velocityY,2))), velocityY*sqrt(50/(pow(velocityX,2)+pow(velocityY,2))));
            break;
        case 2:
            velocity = b2Vec2(velocityX*sqrt(72/(pow(velocityX,2)+pow(velocityY,2))), velocityY*sqrt(72/(pow(velocityX,2)+pow(velocityY,2))));
            break;
        case 3:
            velocity = b2Vec2(velocityX*sqrt(128/(pow(velocityX,2)+pow(velocityY,2))), velocityY*sqrt(128/(pow(velocityX,2)+pow(velocityY,2))));
            break;
        case 4:
            velocity = b2Vec2(velocityX*sqrt(200/(pow(velocityX,2)+pow(velocityY,2))), velocityY*sqrt(200/(pow(velocityX,2)+pow(velocityY,2))));
            break;
    }

    // normolize the velocity
    spear->SetLinearVelocity(velocity);
    spear->SetTransform(spear->GetPosition(), radian);
}

// update the world based on the timer
void Model::updateWorld(){
    // initial positions of objects on the window
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

    // checks if collision occurs
    if(contactListener->getDestroy()){ // is contacted when to delete objects
        //world->DestroyBody(fish1); //maybe needed will need to test
        contactListener->setDestroy(false);
        world->DestroyBody(spear);
        initSpear();
        world->DestroyBody(fish1);
        initFish1();
        world->DestroyBody(fish2);
        initFish2();
        world->DestroyBody(fish3);
        initFish3();
    }

    // Now print the position and angle of the body.
    b2Vec2 finalPos = spear->GetPosition();
    spearX= finalPos.x*100;
    spearY = finalPos.y*100;

    // check if the spear goes out of the window
    if(spearX <= 925 && spearX >= -125 && spearY <= 725 && spearY >= -125 ){
        emit setUpSpear(initXSpear, initYSpear, spearX - 75, spearY - 75);

    }
    // if so, reinitialize it and set it back to the boat
    else{
        world->DestroyBody(spear);
        emit setUpSpear(325, 0, 325, 0);

        initSpear();

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

    // place the fish to the left if it reaches right end
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

    // place the fish to the left if it reaches right end
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

    // place the fish to the left if it reaches right end
    if(fish3X < initXFish3){
        emit setUpFish3(-125, 460, fish3X - 55, fish3Y - 40);
    }
    else{
        emit setUpFish3(initXFish3, initYFish3, fish3X - 55, fish3Y - 40);
    }
}

// reset the world when going back to the fishing page from other page
void Model::resetWorld(){
    timer->stop();

    world->DestroyBody(spear);
    world->DestroyBody(fish1);
    world->DestroyBody(fish2);
    world->DestroyBody(fish3);

    emit setUpSpear(325, 0, 325, 0);
    isShot = false;
    initSpear();

    QPixmap spearPix = QPixmap::fromImage(spearImage.scaled(150, 150));;
    emit resetSpear(spearPix);

    initFish1();
    initFish2();
    initFish3();
    timer->start(25);
}

// rotate the spear when the player moving cursor
void Model::setSpearLabel(int x, int y){
    if(!isShot){
        QImage rotated;
        QPixmap spearPix;

        // rotate the spear when the cursor is below the character
        if(y > 75){
            double velocityX = x - 400;
            double velocityY = y - 75;
            double radian = -atan(velocityX/velocityY);
            double angle = radian*180 / M_PI;

            // change the size of pixmap to avoid scaling spear when rotating
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

//Reads the Text file Fish_info.txt and saves information to fishQA multimap.
void Model::loadInfoQ(){
    //access the file
    QFile inputFile(QString(":/Fish_info.txt"));
    //opens the file
    if (inputFile.open(QIODevice::ReadOnly))
    {
        //Reads the lines in the file
        QTextStream in(&inputFile);

        //counting the number of questions(fields) we go through, and it restarts at zero when it gets to the last question for each fish.
        int count = 0;
        //holds the current info for the line we are reading in the file
        QString line;
        QString currentFish;
        //holds all the information for each fish
        QMap<QString,QString> fishInfo;

        QString waterTypeFile = "";
        while (!in.atEnd())
        {
            line = in.readLine();
            if(line.contains("WaterType"))
            {
                line = line.trimmed().split(":")[1];
                waterTypeFile = line;
                continue;
            }

            if(line.contains("Question"))
            {
                line = line.trimmed().split(":")[1];
                questions.push_back(line);
                continue;
            }

            //fish information
            if(line.isEmpty()){
                continue;
            }
            //start of each fish, and saves the name as the current fish
            if(count == 0)
            {
                currentFish = line;
                count++;

                if(waterTypeFile == "pond")
                {
                    pondFish.push_back(currentFish);
                }
                else if(waterTypeFile == "river")
                {
                    riverFish.push_back(currentFish);
                }
                else
                {
                    seaFish.push_back(currentFish);
                }
            }
            //Questions[0] = what is my name?
            else if(line.contains(questions[0]))
            {
                line = line.trimmed().split(":")[1];
                fishInfo.insert(questions[0], line);
                count++;
            }
            //Questions[1] = How big can I get?
            else if(line.contains(questions[1]))
            {
                line = line.trimmed().split(":")[1];
                fishInfo.insert(questions[1], line);
                count++;
            }
            //Questions[2] = Where can you find me?
            else if(line.contains(questions[2]))
            {
                line = line.trimmed().split(":")[1];
                fishInfo.insert(questions[2], line);
                count++;
            }
            //Questions[3] = Am I an endangered species?
            else if(line.contains(questions[3]))
            {
                line = line.trimmed().split(":")[1];
                fishInfo.insert(questions[3], line);

            }
            //filepath to the real life image of the fish
            else if(line.contains("ActualImagefilepath"))
            {
                line = line.trimmed().split(" ")[1];
                fishInfo.insert("ActualImagefilepath", line);

            }
            //filepath to the pixelated image of the fish
            else if(line.contains("PixelatedImagefilepath"))
            {
                line = line.trimmed().split(" ")[1];
                fishInfo.insert("PixelatedImagefilepath", line);

            }
            //Rarity of the fish, common, rare, and legendary
            else if(line.contains("Rarity"))
            {
                line = line.trimmed().split(":")[1];
                fishInfo.insert("Rarity", line);

                //we add the information of the fishes to our FishQA multimap
                fishQA.insert(currentFish, fishInfo);
                count = 0;
                fishInfo.clear();
            }
        }
        //closes the file
        inputFile.close();
    }

    //********************** for testing purposes ************************
    //int count = 1;
    //for(QMap<QString,QString> str: fishQA.values())
    {
//        std::cout << count++ << std::endl;
//        std::cout << str.value("What is my Name?").toStdString() << std::endl;
//        std::cout << str.value("How big can I get?").toStdString() << std::endl;
//        std::cout << str.value("Where can you find me?").toStdString() << std::endl;
//        std::cout << str.value("ActualImagefilepath").toStdString() <<std::endl;
    }
}



//***********Quiz************************
//Once the Spear has crashed with a fish, the you call this method

//Common, Rare, Legendary
void Model::getFish(){

    //Get the fish
    int randNum = rand()%10;    
    currFish = getRandFish(randNum);
    //Get the water
    QChar waterL;
    if(waterType == TypeOfWater::TOW_PondWater)
        waterL = 'p';
    else if(waterType == TypeOfWater::TOW_RiverWater)
         waterL = 'r';
    else
         waterL = 's';


    //Read the picture file
    QString fishPic = fishQA.value(currFish).value("ActualImagefilepath");


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
        question = questions[questionNum];
        answer = fishQA.value(currFish).value(question);

        //send to method to get two other random values of fish (If our question is yes/no answer do not get fish)
        QString randAsnw1 = getRandAnswer(questionNum,question, answer, "", "");
        QString randAsnw2 = questionNum == 3? "N/A": getRandAnswer(questionNum, question, answer, randAsnw1, "");
        QString randAsnw3 = questionNum == 3? "N/A": getRandAnswer(questionNum, question, answer, randAsnw1, randAsnw2);

        //Set up timer for quiz
        quizCountDown();
        emit updateQuiz(question, answer, randAsnw1, randAsnw2, randAsnw2, fishPic, currFish);
    }
    //If it is not catched
    else{
        catchedFish.insert(currFish, 1);
        //send all infomation of the fish
        QString answer1 = fishQA.value(currFish).value(questions[0]);
        QString answer2 = fishQA.value(currFish).value(questions[1]);
        QString answer3 = fishQA.value(currFish).value(questions[2]);
        QString answer4 = fishQA.value(currFish).value(questions[3]);

        emit updateInformation(questions[0], answer1, questions[1], answer2,
                               questions[2], answer3, questions[3], answer4,
                               currFish, fishPic);

        if(waterL == 'p'){
            pondProgess++;
            emit updateNextLevelProgress(pondProgess, waterL);
        }
        else if(waterL == 'r')
        {
            riverProgess++;
            emit updateNextLevelProgress(riverProgess, waterL);
        }
        else
        {
            seaProgess++;
            emit updateNextLevelProgress(seaProgess, waterL);
        }
    }
}


//Helper method that gets a random answer based on the question
QString Model::getRandAnswer(int questionNum, QString question,  QString answer,
                             QString randAns1, QString randAns2){
    //get a random fish
    QString randFish = getRandFish(rand()%10);

    //Based on our question number (The question we did)
    QString randAnsw = fishQA.value(randFish).value(question);

    if(randAnsw != answer && randAnsw != randAns1 && randAnsw != randAns2 )
        return randAnsw;
    else
        return getRandAnswer(questionNum, question, answer, randAns1, randAns2);
}






//Helper method to get a random fish from the water type we are currently in
//TODO: TEst this!!!
QString Model::getRandFish(int randNum){
//    resetWorld();
    QString randFish;

    if(waterType == TypeOfWater::TOW_PondWater)
        randFish = pondFish[randNum];
    else if(waterType == TypeOfWater::TOW_RiverWater)
        randFish = riverFish[randNum];
    else
        randFish = seaFish[randNum];

    QString typeFish = fishQA.value(randFish).value("Rarity");


    //if my spear is wood but the fish I have is not 'common', get a different fish
    //if my spear is metal and I get a 'legenday' fish, get a different fish
    //if my fish is the same as my current fish, get a different fish
    if((currentSpear == 1 && typeFish != "Common") ||
            ((currentSpear == 2 || currentSpear == 3) && typeFish == "Legendary") ||
            (randFish == currFish)){
        randFish = getRandFish(rand()%10);
    }

    return randFish;
}



void Model::quizCountDown(){
    quizTimeCounter = 10;
        quizTimer->start(1000);
}

void Model::updateQuizTime(){
    emit sendCountDown(QString::number(quizTimeCounter));
    if(quizTimeCounter >0)
        quizTimeCounter--;
    else
        quizTimer->stop();

}




//Checks user answer
void Model::checkAnswer(QString question, QString userAnswer){
    QString correctAnswer = fishQA.value(currFish).value(question);
    if(correctAnswer == userAnswer){
        correctAnsw++;
        correctAnswForProgBar++;
        if(correctAnsw == 10){
            correctAnswForProgBar = 0;
            updateSpear();
        }
        else if(correctAnsw == 20){
            correctAnswForProgBar = 0;
            updateSpear();
        }
        else if(correctAnsw == 30){
            correctAnswForProgBar = 0;
            updateSpear();
        }
        else if(correctAnsw == 40){
            correctAnswForProgBar = 0;
            updateSpear();
        }
        emit answerResult(true, correctAnswer);
        emit updateNextSpearProgress(correctAnswForProgBar);
    }
    else
        emit answerResult(false, correctAnswer);
}



void Model::updateSpear(){
  if(currentSpear < 4){
    currentSpear++;
  }
  resetWorld();

}



//*********** Code for Testing *********************

//TESTING Code for quiz and Information WIndow
//INFORMATION TESTING
void Model::getTestInfoFish(){
//    QString fish;
//    if(waterType == TypeOfWater::TOW_PondWater)
//        fish = pondFish[currInfo];
//    else if(waterType == TypeOfWater::TOW_RiverWater)
//        fish = riverFish[currInfo];
//    else if(waterType == TypeOfWater::TOW_SeaWater)
//        fish = seaFish[currInfo];
//    QString fishPic = fishQA.value(fish).value("ActualImagefilepath");

//    if(!catchedFish.contains(fish))
//        catchedFish.insert(fish, 1);

//    //send all infomation of the fish
//    QString answer1 = fishQA.value(fish).value(questions[0]);
//    QString answer2 = fishQA.value(fish).value(questions[1]);
//    QString answer3 = fishQA.value(fish).value(questions[2]);
//    QString answer4 = fishQA.value(fish).value(questions[3]);

//    if(currInfo < 9)
//        currInfo++;
//    else
//        currInfo = 0;

//    emit updateInformation(questions[0], answer1, questions[1], answer2,
//                           questions[2], answer3, questions[3], answer4,
//                           fish, fishPic);
}


//QUIZ TESTING
void Model::getTestQuizInfo(){
//    QString answer;
//    QString fish;
//    if(waterType == TypeOfWater::TOW_PondWater)
//        fish = pondFish[currQuiz];
//    else if(waterType == TypeOfWater::TOW_RiverWater)
//        fish = riverFish[currQuiz];
//    else if(waterType == TypeOfWater::TOW_SeaWater)
//        fish = seaFish[currQuiz];
//    QString fishPic = fishQA.value(fish).value("ActualImagefilepath");
//    currFish = fish;
//    //Get the question and aswer
//    answer = fishQA.value(fish).value(questions[qNum]);

//    //send to method to get two other random values of fish
//    QString randAsnw1 = getRandAnswer(qNum,questions[qNum], answer, "", "");
//    QString randAsnw2 = qNum == 3? "N/A":getRandAnswer(qNum, questions[qNum], answer, randAsnw1, "");
//    QString randAsnw3 = qNum == 3? "N/A":getRandAnswer(qNum, questions[qNum], answer, randAsnw1, randAsnw2);


//    //Counter of fish
//    if(currQuiz < 10 && qNum ==0)
//        currQuiz++;
//    else if(currQuiz >= 10 && qNum == 0)
//        currQuiz = 0;

//    //quizTimer->start(1000);
//    quizCountDown();
//    emit updateQuiz(questions[qNum], answer, randAsnw1, randAsnw2, randAsnw3, fishPic, fish);

//    //Counter of questions
//    if(qNum < 3)
//        qNum++;
//    else
//        qNum = 0;
}


//************* Journal set **********************
void Model::getJouralInfo(int page){
    QVector<QString> info;
    QString pageStr;
    pageStr.setNum(page + 1);

    //if page == 0 -> Pond
    //if page == 1 -> Pond
    if(page == 0 || page == 1){
        info.push_back("Pond Fish");
        info.push_back("Page " + pageStr);
        setJournalVector(pondFish, info, page%2);
    }
    //if page == 2 -> River
    //if page == 3 -> River
    else if(page == 2 || page == 3){
        info.push_back("River Fish");
        info.push_back("Page " + pageStr);
        setJournalVector(riverFish, info, page%2);
    }
    //if page == 4 -> Sea
    //if page == 5 -> Sea
    else{
        info.push_back("Sea Fish");
        info.push_back("Page " + pageStr);
        setJournalVector(seaFish, info, page%2);
    }

    emit updateJournal(info, questions);
}

void Model::setJournalVector(QVector<QString> fish, QVector<QString> &info, int page){

    //TODO: Change to not have repeated code
    //if page is 0, sent the info of the first five fish in list
    if(page == 0){
        for(int i = 0; i <5; i++){
            //Check if the user has catch it
            if(catchedFish.contains(fish[i])){
                //Picture of Fish
                info.push_back(fishQA.value(fish[i]).value("PixelatedImagefilepath"));
                for(int j = 0; j < 4; j++){
                    info.push_back(fishQA.value(fish[i]).value(questions[j]));
                }
            }
            //If it has not been catch send a message
            else{
                info.push_back("uncached");
            }
        }
    }
    //else, sent info of last five fish in list
    else{
        for(int i = 5; i <10; i++){
            //Check if the user has catch it
            if(catchedFish.contains(fish[i])){
                //Picture of Fish
                info.push_back(fishQA.value(fish[i]).value("PixelatedImagefilepath"));
                for(int j = 0; j < 4; j++){
                    info.push_back(fishQA.value(fish[i]).value(questions[j]));
                }
            }
            //If it has not been catch send a message
            else{
                info.push_back("uncached");
            }
        }
    }

}



