#include "World.h"

#include <QDebug>

#include "src/god/i/IAppProvider.h"

#include "unistd.h"


bool World::runStep()
{
    usleep(999999 / 60);
    updateWorld();

    for(auto it = bodies.begin(); it != bodies.end(); ++it)
    {
        std::shared_ptr<Body> bodyPtr = it.value();

        if(bodyPtr != nullptr)
        {
            bodyPtr->update();
        }
    }
    return true;
}

void World::updateWorld()
{
    float32 timeStep = 1.0f / 60.0f;

    int32 velocityIterations = 6;
    int32 positionIterations = 2;

    std::shared_ptr<b2World> worldPtr = getWorld();

    if(worldPtr != nullptr)
    {
        worldPtr->Step(timeStep, velocityIterations, positionIterations);
    }
}

void World::execLoop()
{
    while(runStep());
}

float World::calculateHeight(float width) const
{
    float screenWidth = (float)getAppProvider().getScreenWidth();
    float screenHeight = (float)getAppProvider().getScreenHeight();

    Q_ASSERT_X(getAppProvider().isAppProviderReady(), "World::calculateHeigh", "World expects App to be ready before initialization\n"
                                                                               "This is likely to happen when setWorld is called prior to setApp by God.\n"
                                                                               "God works in mysterious ways");

    //This is ratio between screen size and world size
    float screenRatio = width / screenWidth;

    return screenRatio * screenHeight;
}

float World::calculateRatio(float width) const
{
    float screenWidht = (float)getAppProvider().getScreenWidth();

    return width / screenWidht;
}

std::shared_ptr<Body> World::_getBody(const QString &name) const
{
    return bodies.value(name, nullptr);
}

bool World::_addBody(const QString &name, const std::shared_ptr<Body> &body)
{
    qDebug() << __PRETTY_FUNCTION__ << name;

    std::shared_ptr<Item> itemPtr = getAppProvider().getItem(name);

    if(bodies.value(name, nullptr) == nullptr && itemPtr != nullptr)
    {
        body->attachItem(itemPtr);

        bodies.insert(name, body);

        return true;
    }

    return false;
}

bool World::_start()
{
    qDebug() << __PRETTY_FUNCTION__;
    for(auto it = bodies.begin(); it != bodies.end(); ++it)
    {
        std::shared_ptr<Body> bodyPtr = it.value();

        if(bodyPtr != nullptr)
        {
            bodyPtr->setReady();
        }
    }

    b2Loop = new std::thread(std::bind(&World::execLoop, this));

    return true;
}

float World::_getWidth() const
{
    return width;
}

float World::_getHeight() const
{
    return calculateHeight(getWidth());
}

float World::_getRatio() const
{
    return calculateRatio(getWidth());
}

World::World(const IAppProvider &appProvider, float _width) : IWorld(appProvider), width(_width), gravityVector(0.0f, 10.0f)
{
    setWorld(gravityVector);
}
