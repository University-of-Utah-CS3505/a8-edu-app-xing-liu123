#include "model.h"
#include <QFile>
#include <QTextStream>

Model::Model(QObject *parent)
    : QObject{parent}
{
    loadInfoQ();

    // Define the gravity vector to 0 (Since the fishe should not be falling)
    b2Vec2 gravity(0.0f, 0.0f);
    // Construct a world object, which will hold and simulate the rigid bodies.
    world = new b2World(gravity);

    currentSpear = 1;
    isShot = false;

    timer = new QTimer(this);
    quizTimer = new QTimer(this);
    contactListener = new HitListener();

    correctAnsw = 0;
    correctAnswForProgBar = 0;
    quizTimeCounter =10;

    // Create contact listener
    world->SetContactListener(contactListener);

    connect(timer,
            &QTimer::timeout,
            this,
            &Model::updateWorld);

    connect(quizTimer,
            &QTimer::timeout,
            this,
            &Model::updateQuizTime);

    //When a collision happens, we get a fish that will be sent to view
    connect(contactListener,
            &HitListener::sendCollision,
            this,
            &Model::getFish);
}

Model::~Model(){
    delete world;
    delete timer;
    delete contactListener;
    delete quizTimer;
}

// set up the physical world
/**
 * @brief Model::setUpWorld
 * It obtains the current water being used,
 * sets up the phisical world with collision management and
 * the bodies of the world (fishes and spear)
 * @param water
 */
void Model::setUpWorld(QString water){
    //Set up the type of water being navigated
    if(water.contains("Salt"))
        waterType = TypeOfWater::TOW_SeaWater;
    if(water.contains("Fresh"))
        waterType = TypeOfWater::TOW_PondWater;
    if(water.contains("Smooth"))
        waterType = TypeOfWater::TOW_RiverWater;

    //Call to initialize the fishes (bodies)
    initFish1();
    initFish2();
    initFish3();
    initSpear();

    // start the world imitation
    timer->start(10);
}


/**
 * @brief Model::initFish1
 * Initialize the fish to be at the top with the slowest velocity.
 */
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
    b2Vec2 velocity1(1.6f, 0.0f);
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


/**
 * @brief Model::initFish2
 * Initialize the fish to be in the middle with the medium velocity.
 */
void Model::initFish2(){
    fish2X = 55;
    fish2Y = 400;

    // Define the dynamic body (fish). We set its position and call the body factory.
    b2BodyDef bodyDef2;
    bodyDef2.type = b2_dynamicBody;
    bodyDef2.position.Set(0.55f, 4.0f); //-> Starting position of the fish

    fish2 = world->CreateBody(&bodyDef2);

    //Give velocity to body (Medium)
    b2Vec2 velocity2(2.4f, 0.0f);
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


/**
 * @brief Model::initFish3
 * Initialize the fish to be at the buttom with the fastest velocity.
 */
void Model::initFish3(){
    fish3X = 55;
    fish3Y = 500;

    // Define the dynamic body (fish). We set its position and call the body factory.
    b2BodyDef bodyDef3;
    bodyDef3.type = b2_dynamicBody;
    bodyDef3.position.Set(0.55f, 5.0f); //-> Starting position of the fish

    fish3 = world->CreateBody(&bodyDef3);

    //Give velocity to body (Fast)
    b2Vec2 velocity3(3.2f, 0.0f);
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


/**
 * @brief Model::initSpear
 * It initialize the spear with its appropiate
 * velocity, position, and image based on the
 * current spear integer
 */
void Model::initSpear(){
    switch(currentSpear){
        case 1:
            spearImage.load(":/spear1.png");
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
            dynamicSpear.SetAsBox(0.012f, 0.36f);
            break;
        case 2:
            dynamicSpear.SetAsBox(0.012f, 0.40f);
            break;
        case 3:
            dynamicSpear.SetAsBox(0.012f, 0.44f);
            break;
        case 4:
            dynamicSpear.SetAsBox(0.012f, 0.48f);
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


/**
 * @brief Model::updateSpear
 * It upddates the information for updating the spear
 */
void Model::updateSpear(){
  if(currentSpear < 4){
    currentSpear++;
  }
  resetWorld();
}



/**
 * @brief Model::shotSpear
 * shot the spear based on the position clicked by the player
 * @param x - x of the clicked position
 * @param y - y of the clicked position
 */
void Model::shotSpear(int x, int y){
    // ignore action if it is moving
    if(isShot){
        return;
    }

    isShot = true;
    emit sendShootEffect();

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
            velocity = b2Vec2(velocityX*sqrt(8/(pow(velocityX,2)+pow(velocityY,2))), velocityY*sqrt(8/(pow(velocityX,2)+pow(velocityY,2))));
            break;
        case 2:
            velocity = b2Vec2(velocityX*sqrt(12/(pow(velocityX,2)+pow(velocityY,2))), velocityY*sqrt(12/(pow(velocityX,2)+pow(velocityY,2))));
            break;
        case 3:
            velocity = b2Vec2(velocityX*sqrt(16/(pow(velocityX,2)+pow(velocityY,2))), velocityY*sqrt(16/(pow(velocityX,2)+pow(velocityY,2))));
            break;
        case 4:
            velocity = b2Vec2(velocityX*sqrt(20/(pow(velocityX,2)+pow(velocityY,2))), velocityY*sqrt(20/(pow(velocityX,2)+pow(velocityY,2))));
            break;
    }

    // normolize the velocity
    spear->SetLinearVelocity(velocity);
    spear->SetTransform(spear->GetPosition(), radian);
}


/**
 * @brief Model::updateWorld
 * It updates the world based on the timer
 */
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

    // checks if collision occurs, if it does deletes all bodies and resets for the next step
    if(contactListener->getDestroy()){ // is contacted when to delete objects
        contactListener->setDestroy(false); // lets hitlistener reset
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


/**
 * @brief Model::resetWorld
 * It resets the world when going back to the fishing page
 */
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
    timer->start(10);
}



/**
 * @brief Model::setSpearLabel
 * It rotates the spear when the player moves its cursor
 * @param x - x of the position where the cursor is located
 * @param y - y of the position where the cursor is located
 */
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


/**
 * @brief Model::loadInfoQ
 * Reads the Text file Fish_info.txt and saves information to fishQA multimap.
 */
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
/**
 * @brief Model::getFish
 * It gets a random fish when a collison with spear and fish happens,
 * and sends the appropiate information to the view depending
 * on weather is going to the quiz or the information page.
 */
void Model::getFish(){
    emit sendSoundEffect();

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

    //Check if is in the list of catched fish (send to Quiz Page)
    if(catchedFish.contains(currFish)){
        QString question;
        QString answer;        

        //if it is then check how many times it has been catched
        //and get the %4 num to get the questionString
        int questionNum = rand() % 4; //returns 0,1,2,3
        //update the value

        //Get the question and aswer
        question = questions[questionNum];
        answer = fishQA.value(currFish).value(question);

        //send to method to get two other random values of fish
        //(If our question is yes/no answer do not get answer for last two)
        QString randAsnw1 = getRandAnswer(questionNum,question, answer, "", "");
        QString randAsnw2 = questionNum == 3? "N/A": getRandAnswer(questionNum, question, answer, randAsnw1, "");
        QString randAsnw3 = questionNum == 3? "N/A": getRandAnswer(questionNum, question, answer, randAsnw1, randAsnw2);

        //Set up timer for quiz
        quizCountDown();

        //Send information of quiz
        //(If is the first question (Name) we send an empty string)
        emit updateQuiz(question, answer, randAsnw1, randAsnw2, randAsnw3, fishPic,
                        questionNum == 0? "" :currFish);
    }
    //If it is not catched (send to Information Page)
    else{
        catchedFish.push_back(currFish);
        //send all infomation of the fish
        QString answer1 = fishQA.value(currFish).value(questions[0]);
        QString answer2 = fishQA.value(currFish).value(questions[1]);
        QString answer3 = fishQA.value(currFish).value(questions[2]);
        QString answer4 = fishQA.value(currFish).value(questions[3]);

        emit updateInformation(questions[0], answer1, questions[1], answer2,
                               questions[2], answer3, questions[3], answer4,
                               currFish, fishPic);

        //Based on the water we currently are, we send the infromation
        //for progreess bar
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


/**
 * @brief Model::getRandAnswer
 * Helper method that gets a random answer based on the question
 * @param questionNum
 * @param question
 * @param answer
 * @param randAns1
 * @param randAns2
 * @return string with the random answer
 */
QString Model::getRandAnswer(int questionNum, QString question,  QString answer,
                             QString randAns1, QString randAns2){
    //get a random fish
    QString randFish = getRandFish(rand()%10);

    //Based on our question number (The question we did)
    QString randAnsw = fishQA.value(randFish).value(question);

    //If the answer is equal to either of the previous answer, then repeat it again
    if(randAnsw == answer || randAnsw == randAns1 || randAnsw == randAns2 )
        return getRandAnswer(questionNum, question, answer, randAns1, randAns2);
    else
        return randAnsw;
}






//Helper method to get a random fish from the water type we are currently in
/**
 * @brief Model::getRandFish
 * @param randNum
 * @return String with a random fish
 */
QString Model::getRandFish(int randNum){
    QString randFish;

    //Based on the water we get the random fish
    if(waterType == TypeOfWater::TOW_PondWater)
        randFish = pondFish[randNum];
    else if(waterType == TypeOfWater::TOW_RiverWater)
        randFish = riverFish[randNum];
    else
        randFish = seaFish[randNum];

    //Get the rarity of the fish
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


/**
* @brief Model::quizCountDown
* It starts the count down for the quiz
*/
void Model::quizCountDown(){
    quizTimeCounter = 10;
    quizTimer->start(1000);
}

/**
 * @brief Model::updateQuizTime
 * It send the information of the countdown to the quiz
 */
void Model::updateQuizTime(){
    emit sendCountDown(QString::number(quizTimeCounter));
    if(quizTimeCounter >0)
        quizTimeCounter--;
    else
        quizTimer->stop();
}

/**
 * @brief Model::checkAnswer
 * It checks the answers of the usert for the quiz
 * @param question
 * @param userAnswer
 */
void Model::checkAnswer(QString question, QString userAnswer){
    QString correctAnswer = fishQA.value(currFish).value(question);
    quizTimer->stop();
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
/**
 * @brief Model::getJouralInfo
 * Based on the page we are currently at, we send the infromation
 * of the fish that belong to the pond, river or sea
 * @param page
 */
void Model::getJouralInfo(int page){
    QVector<QString> info;
    QString pageStr;
    pageStr.setNum(page + 1);

    //if page == 0 -> Pond
    //if page == 1 -> Pond
    if(page == 0 ){ // page == 0 || page == 1
        info.push_back("Pond");
        info.push_back("Page " + pageStr);
        setJournalVector(pondFish, info, page%1); //%2
    }
    //if page == 2 -> River
    //if page == 3 -> River
    else if(page == 1){ //page == 2 || page == 3
        info.push_back("River");
        info.push_back("Page " + pageStr);
        setJournalVector(riverFish, info, page%1);
    }
    //if page == 4 -> Sea
    //if page == 5 -> Sea
    else{
        info.push_back("Sea");
        info.push_back("Page " + pageStr);
        setJournalVector(seaFish, info, page%1);
    }

    emit updateJournal(info);
}

/**
 * @brief Model::setJournalVector
 * Helper method, that iterates through all the information of the fish,
 * based on the vector array given though the parameter to construct the
 * vector of the fishes that belong in the journal for that spefiic page.
 * @param fish
 * @param info
 * @param page
 */
void Model::setJournalVector(QVector<QString> fish, QVector<QString> &info, int page){

    //TODO: Change to not have repeated code
    //if page is 0, sent the info of the first five fish in list
    if(page == 0){
        for(int i = 0; i <10; i++){ // 5
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



