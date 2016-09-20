#include "DynamicBoxBody.h"

#include <QDebug>

#include "src/world/IWorld.h"
#include "src/god/i/IAppProvider.h"

void DynamicBoxBody::onReady()
{
    qDebug() << __PRETTY_FUNCTION__;

    std::shared_ptr<b2World> worldPtr = getWorld().getWorld();

    if(worldPtr != nullptr)
    {
        box2dBody = worldPtr->CreateBody(bodyDefinition.get());

        if(box2dBody != nullptr)
        {
            b2FixtureDef fixtureDef;
            fixtureDef.shape = dynamicBoxShape;
            fixtureDef.density = 1.0f;
            fixtureDef.friction = 0.3f;

            box2dBody->CreateFixture(&fixtureDef);
        }
    }
}

void DynamicBoxBody::onItemAttached()
{
    Box2DBody::onItemAttached();
    dynamicBoxShape = new b2PolygonShape();
    dynamicBoxShape->SetAsBox(getWidth() / 2, getHeight() / 2);
}

void DynamicBoxBody::onUpdateNotify()
{
    Box2DBody::onUpdateNotify();
}

Body *DynamicBoxBody::Allocator(const QString &name, const IWorld &world)
{
    Q_UNUSED(name)
    return new DynamicBoxBody(world);
}

DynamicBoxBody::DynamicBoxBody(const IWorld &world) : Box2DBody(world), dynamicBoxShape(nullptr)
{

}

DynamicBoxBody::~DynamicBoxBody()
{
    if(dynamicBoxShape != nullptr)
    {
        delete dynamicBoxShape;
    }
}

b2BodyDef *DynamicBoxBody::createBodyDefinition() const
{
    b2BodyDef* bodyDef = new b2BodyDef();
    bodyDef->type = b2_dynamicBody;
    bodyDef->position.Set(getXRelativeToItem(), getYRelativeToItem());

    return bodyDef;
}
