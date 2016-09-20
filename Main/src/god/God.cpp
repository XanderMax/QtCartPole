#include "God.h"

#include "src/app/IApp.h"
#include "src/world/IWorld.h"

God::God()
{

}

God::~God()
{

}

std::shared_ptr<IApp> God::getApp() const
{
    return app;
}

std::shared_ptr<Item> God::getItem(const QString &name) const
{
    if(app != nullptr)
    {
        return app->getItem(name);
    }

    return nullptr;
}

std::shared_ptr<Item> God::getRootViewItem() const
{
    if(app != nullptr)
    {
        return app->getRootViewItem<Item>();
    }

    return nullptr;
}

unsigned int God::getScreenWidth() const
{
    if(app != nullptr)
    {
        return app->getScreenWidth();
    }

    return 0;
}

unsigned int God::getScreenHeight() const
{
    if(app != nullptr)
    {
        return app->getScreenHeight();
    }

    return 0;
}

bool God::isAppProviderReady() const
{
    return app != nullptr;
}

std::shared_ptr<IWorld> God::getWorld() const
{
    return world;
}

std::shared_ptr<Body> God::getBody(const QString &name) const
{
    if(world != nullptr)
    {
        std::shared_ptr<Body> bodyPtr = world->getBody(name);
    }

    return nullptr;
}

bool God::isWorldProviderReady() const
{
    return world != nullptr;
}

std::shared_ptr<IDimension> God::getDimension() const
{
    return dimension;
}

void God::start()
{
    qDebug() << __PRETTY_FUNCTION__;
    if(world != nullptr && !world->isStarted())
    {
        world->start();
    }
}

#include "God.h"
