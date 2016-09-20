#include "Body.h"

#include "src/world/IWorld.h"


Body::Body(const IWorld &_world) : world(_world), item(nullptr), readyFlag(false), bodyDefinition(nullptr)
{
}

Body::~Body()
{
}

void Body::attachItem(const std::shared_ptr<Item>& _item)
{
    //Do this only if item hasn't yet been attached
    if(item == nullptr)
    {
        item = _item;

        bodyDefinition = std::shared_ptr<b2BodyDef>(createBodyDefinition());

        onItemAttached();
    }
}

bool Body::getReady() const
{
    return readyFlag;
}

void Body::setReady()
{
    readyFlag = true;

    onReady();
}

void Body::update()
{
    onUpdateNotify();
}

bool Body::isItemAttached() const
{
    return item != nullptr;
}

const std::shared_ptr<b2BodyDef> &Body::getBodyDefinition()
{
    return bodyDefinition;
}

const IWorld &Body::getWorld() const
{
    return world;
}

const std::shared_ptr<Item>& Body::getItem() const
{
    return item;
}
