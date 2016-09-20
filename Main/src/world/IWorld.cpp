#include "IWorld.h"

#include "src/god/i/IAppProvider.h"

IWorld::IWorld(const IAppProvider &_appProvider) : appProvider(_appProvider), started(false)
{

}

const IAppProvider &IWorld::getAppProvider() const
{
    return appProvider;
}

const IDimensionProvider &IWorld::getDimensionProvider() const
{
    return getAppProvider();
}

bool IWorld::isStarted() const
{
    return started;
}

float IWorld::getWidth() const
{
    return _getWidth();
}

float IWorld::getHeight() const
{
    return _getHeight();
}

float IWorld::getRatio() const
{
    return _getRatio();
}

std::shared_ptr<b2World> IWorld::getWorld() const
{
    return  box2World;
}

bool IWorld::start()
{
    if(!started)
    {
        started = _start();
    }

    return started;
}
