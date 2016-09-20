#ifndef __EYE_CARAMBA_BODY_H__
#define __EYE_CARAMBA_BODY_H__

#include <memory>
#include <QObject>
#include "src/items/Item.h"
#include "Box2D/Box2D.h"

class Simulation;
class IWorld;

class Body : public QObject
{
private:
    const IWorld& world;

    std::shared_ptr<Item> item;

    bool readyFlag;

protected:

    std::shared_ptr<b2BodyDef> bodyDefinition;

    Body(const IWorld& _world);

    //By the time this function is called the body is attached to particular item and item can be accessed through object field
    virtual void onItemAttached() {}

    virtual void onReady() {}

    virtual void onUpdateNotify() {}

    virtual b2BodyDef* createBodyDefinition() const = 0;

public:

    virtual ~Body();

    //By the time this function the body is attached to particular item
    void attachItem(const std::shared_ptr<Item>& item);

    //After Body is ready it can access other bodies in simulation as they have passed all steps of lifecycle, They night not be ready though
    bool getReady() const;
    void setReady();

    void update();

    bool isItemAttached() const;

    const std::shared_ptr<b2BodyDef>& getBodyDefinition();

    const IWorld& getWorld() const;

    const std::shared_ptr<Item>& getItem() const;

};




#endif //__EYE_CARAMBA_BODY_H__
