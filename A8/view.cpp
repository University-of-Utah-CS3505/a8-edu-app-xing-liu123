#include "view.h"
#include "model.h"
#include "ui_view.h"

View::View(Model &model, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::View)
{
    ui->setupUi(this);
    //ui->widget->show();
    QPixmap pix;
    pix.load(":/fish1.png");
    QPixmap pix2;
    pix2.load(":/fish2.png");


    ui->fish1Label->setPixmap(pix.scaled(ui->fish1Label->width(), ui->fish1Label->height()));
    ui->fish2Label->setPixmap(pix2.scaled(ui->fish2Label->width(), ui->fish2Label->height()));
    ui->fish3Label->setPixmap(pix.scaled(ui->fish3Label->width(), ui->fish3Label->height()));

    // Define the gravity vector.
    b2Vec2 gravity(0.0f, 0.0f);

    // Construct a world object, which will hold and simulate the rigid bodies.
    world = new b2World(gravity);


    //***********FISH1**********************
    // Define the dynamic body (fish). We set its position and call the body factory.
    b2BodyDef bodyDef1;
    bodyDef1.type = b2_dynamicBody;
    bodyDef1.position.Set(3.0f, 0.0f); //-> Starting position of the fish
    body = world->CreateBody(&bodyDef1);

    //Give velocity to body
    b2Vec2 velocity1(0.0f, 4.0f);
    body->SetLinearVelocity(velocity1);

    //***********FISH2**********************
    // Define the dynamic body (fish). We set its position and call the body factory.
    b2BodyDef bodyDef2;
    bodyDef2.type = b2_dynamicBody;
    bodyDef2.position.Set(4.0f, 0.0f); //-> Starting position of the fish
    fish2 = world->CreateBody(&bodyDef2);

    //Give velocity to body
    b2Vec2 velocity2(0.0f, 6.0f);
    fish2->SetLinearVelocity(velocity2);


    //***********FISH3**********************
    // Define the dynamic body (fish). We set its position and call the body factory.
    b2BodyDef bodyDef3;
    bodyDef3.type = b2_dynamicBody;
    bodyDef3.position.Set(5.0f, 0.0f); //-> Starting position of the fish
    fish3 = world->CreateBody(&bodyDef3);

    //Give velocity to body
    b2Vec2 velocity3(0.0f, 8.0f);
    fish3->SetLinearVelocity(velocity3);


    //start Time
    QTimer * time = new QTimer(this);
    time->start(200);

    connect(time,
            &QTimer::timeout,
            this,
            &View::updateFish1);
    connect(time,
            &QTimer::timeout,
            this,
            &View::updateFish2);
    connect(time,
            &QTimer::timeout,
            this,
            &View::updateFish3);
}


View::~View()
{
    delete ui;
}

void View::updateFish1(){
    // Prepare for simulation. Typically we use a time step of 1/60 of a
    // second (60Hz) and 10 iterations. This provides a high quality simulation
    // in most game scenarios.
    float32 timeStep = 1.0f / 60.0f;
    int32 velocityIterations = 6;
    int32 positionIterations = 2;

    // Instruct the world to perform a single step of simulation.
    // It is generally best to keep the time step and iterations fixed.
    world->Step(timeStep, velocityIterations, positionIterations);


    if(body->GetPosition().y > 9){
        b2Vec2 pos(3.0f, -1.0f);
        body->SetTransform(pos,body->GetAngle());
    }

    // Now print the position and angle of the body.
    b2Vec2 position = body->GetPosition();
    float32 angle = body->GetAngle();

    printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);
    ui->fish1Label->setGeometry(position.y * 100, position.x * 100,
                                ui->fish1Label->width(), ui->fish1Label->height());
}



void View::updateFish2(){
    // Prepare for simulation. Typically we use a time step of 1/60 of a
    // second (60Hz) and 10 iterations. This provides a high quality simulation
    // in most game scenarios.
    float32 timeStep = 1.0f / 60.0f;
    int32 velocityIterations = 6;
    int32 positionIterations = 2;

    // Instruct the world to perform a single step of simulation.
    // It is generally best to keep the time step and iterations fixed.
    world->Step(timeStep, velocityIterations, positionIterations);


    if(fish2->GetPosition().y > 9){
        b2Vec2 pos(4.0f, -1.0f);
        fish2->SetTransform(pos,fish2->GetAngle());
    }

    // Now print the position and angle of the body.
    b2Vec2 position = fish2->GetPosition();
    float32 angle = fish2->GetAngle();

    printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);
    ui->fish2Label->setGeometry(position.y * 100, position.x * 100,
                                ui->fish2Label->width(), ui->fish2Label->height());
}


void View::updateFish3(){
    // Prepare for simulation. Typically we use a time step of 1/60 of a
    // second (60Hz) and 10 iterations. This provides a high quality simulation
    // in most game scenarios.
    float32 timeStep = 1.0f / 60.0f;
    int32 velocityIterations = 6;
    int32 positionIterations = 2;

    // Instruct the world to perform a single step of simulation.
    // It is generally best to keep the time step and iterations fixed.
    world->Step(timeStep, velocityIterations, positionIterations);


    if(fish3->GetPosition().y > 9){
        b2Vec2 pos(5.0f, -1.0f);
        fish3->SetTransform(pos,fish3->GetAngle());
    }

    // Now print the position and angle of the body.
    b2Vec2 position = fish3->GetPosition();
    float32 angle = fish3->GetAngle();

    printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);
    ui->fish3Label->setGeometry(position.y * 100, position.x * 100,
                                ui->fish3Label->width(), ui->fish3Label->height());
}


//void View::labelNewposition(int x, int y){
//    ui->fish1Label->setGeometry( x, y, ui->fish1Label->width(), ui->fish1Label->height());
//    ui->fish2Label->setGeometry( x, y, ui->fish2Label->width(), ui->fish2Label->height());
//    ui->fish3Label->setGeometry( x, y, ui->fish3Label->width(), ui->fish3Label->height());
//}

//For collision:
//Enable collision listening
// void begingContact(){  ...  }
//1. Which fictures collide -> Box2D
//2. Which bodies are you attach to -> Box2D
//3. WHich particle objects are associated with body -> we need to do this
    //Body:
        //Set user data
        //Get user data



