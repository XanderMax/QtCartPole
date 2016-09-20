#include "Box2DBody.h"

#include "src/world/IWorld.h"
#include "src/god/i/IAppProvider.h"


void Box2DBody::onUpdateNotify()
{
    emit signalUpdate();
}

void Box2DBody::onItemAttached()
{
    qDebug() << __PRETTY_FUNCTION__ << getItem()->getName() << getRawItemX() << getRawItemY();
    QObject::connect(this, SIGNAL(signalUpdate()), this, SLOT(updateOnSignal()));
}

void Box2DBody::onUpdateSignal()
{
        std::shared_ptr<Item> itemPtr = getItem();

        if(itemPtr != nullptr)
        {
            itemPtr->setX(getXCoordinate());
            itemPtr->setY(getYCoordinate());
        }
}

Box2DBody::Box2DBody(const IWorld &world) : Body(world), box2dBody(nullptr)
{

}

Box2DBody::~Box2DBody()
{

}

int Box2DBody::getXCoordinate() const
{
    if(box2dBody != nullptr)
    {
        float ratio = getWorld().getRatio();
        float x = box2dBody->GetPosition().x;

        return (int)(x / ratio);
    }
    return 0;
}

int Box2DBody::getYCoordinate() const
{
    if(box2dBody != nullptr)
    {
        float ratio = getWorld().getRatio();
        float y = box2dBody->GetPosition().y;

        return ( (int)(y / ratio)) ;
    }
    return 0;
}

int Box2DBody::getRawItemX() const
{
    std::shared_ptr<Item> itemPtr = getItem();

    if(itemPtr != nullptr)
    {
        return itemPtr->getX();
    }

    return 0;
}

int Box2DBody::getRawItemY() const
{
    std::shared_ptr<Item> itemPtr = getItem();

    if(itemPtr != nullptr)
    {
        return itemPtr->getY();
    }

    return 0;
}

float Box2DBody::getYRelativeToItem() const
{
    float ratio = getWorld().getRatio();

    std::shared_ptr<Item> itemPtr = getItem();

    if(itemPtr != nullptr)
    {
        float y = (float) itemPtr->getY();

        return ratio * y;
    }

    return 0;
}

float Box2DBody::getXRelativeToItem() const
{
    float ratio = getWorld().getRatio();

    std::shared_ptr<Item> itemPtr = getItem();

    if(itemPtr != nullptr)
    {
        float x = (float) itemPtr->getX();

        return ratio * x;
    }

    return 0;
}

float Box2DBody::getRawX() const
{
    if(box2dBody != nullptr)
    {
        return box2dBody->GetPosition().x;
    }

    return 0.0f;
}

float Box2DBody::getRawY() const
{
    if(box2dBody != nullptr)
    {
        return box2dBody->GetPosition().y;
    }

    return 0.0f;
}

float Box2DBody::getWidth() const
{
    std::shared_ptr<Item> itemPtr = getItem();

    if(itemPtr != nullptr)
    {
        float width = (float)itemPtr->getWidth();

        return width * getWorld().getRatio();
    }

    return 0.0f;
}

float Box2DBody::getHeight() const
{
    std::shared_ptr<Item> itemPtr = getItem();

    if(itemPtr != nullptr)
    {
        float width = (float)itemPtr->getHeight();

        return width * getWorld().getRatio();
    }

    return 0.0f;
}

void Box2DBody::updateOnSignal()
{
    onUpdateSignal();
}
