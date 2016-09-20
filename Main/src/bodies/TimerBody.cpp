#include "TimerBody.h"

#include <QTimer>
#include <QDebug>

#include "src/world/IWorld.h"


void TimerBody::onReady()
{
    qDebug() << __PRETTY_FUNCTION__;

    QTimer::singleShot(3000, this, SLOT(onTimeout()));
}

Body *TimerBody::Allocator(const QString &name, const IWorld &world)
{
    Q_UNUSED(name)
    return new TimerBody(world);
}

TimerBody::TimerBody(const IWorld& world) : Body(world)
{

}

b2BodyDef *TimerBody::createBodyDefinition() const
{
    return nullptr;
}

void TimerBody::onTimeout()
{
    std::shared_ptr<Item> itemPtr = getItem();
    if(itemPtr != nullptr)
    {
        itemPtr->setX(itemPtr->getX() + 10);
    }
    QTimer::singleShot(3000, this, SLOT(onTimeout()));
}
