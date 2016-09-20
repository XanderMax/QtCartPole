#include "StaticWallBody.h"

#include "src/world/IWorld.h"

#include "src/god/i/IAppProvider.h"

void StaticWallBody::onReady()
{
    qDebug() << __PRETTY_FUNCTION__;

    std::shared_ptr<b2World> worldPtr = getWorld().getWorld();

    if(worldPtr != nullptr)
    {
        box2dBody = worldPtr->CreateBody(bodyDefinition.get());

        if(box2dBody != nullptr)
        {
            box2dBody->CreateFixture(wallShape, 0.0f);
        }
    }
}

void StaticWallBody::onUpdateNotify()
{
    Box2DBody::onUpdateNotify();
}

void StaticWallBody::onItemAttached()
{
    Box2DBody::onItemAttached();
    wallShape = new b2PolygonShape();
    wallShape->SetAsBox(getWidth() / 2, getHeight() / 2);
}

Body *StaticWallBody::Allocator(const QString &name, const IWorld &world)
{
    Q_UNUSED(name)
    return new StaticWallBody(world);
}

StaticWallBody::~StaticWallBody()
{
    if(wallShape != nullptr)
    {
        delete wallShape;
    }
}

StaticWallBody::StaticWallBody(const IWorld &world) : Box2DBody(world), wallShape(nullptr)
{


}

b2BodyDef *StaticWallBody::createBodyDefinition() const
{
        b2BodyDef* bodyDef = new b2BodyDef();
        bodyDef->position.Set(getXRelativeToItem(), getYRelativeToItem());

        return bodyDef;
}
