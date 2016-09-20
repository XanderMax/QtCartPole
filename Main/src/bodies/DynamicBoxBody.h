#ifndef KHUGUHJKGIUBKJGIUGI_DYNAMIC_BOX_BODY_H___
#define KHUGUHJKGIUBKJGIUGI_DYNAMIC_BOX_BODY_H___

#include "src/bodies/Box2DBody.h"


class DynamicBoxBody : public Box2DBody
{
private:

    b2PolygonShape* dynamicBoxShape;

protected:

    void onReady();

    void onItemAttached();

    void onUpdateNotify();
public:

    static Body* Allocator(const QString& name, const IWorld& world);

    DynamicBoxBody(const IWorld&);

    virtual ~DynamicBoxBody();


    virtual b2BodyDef* createBodyDefinition() const;
};




#endif //KHUGUHJKGIUBKJGIUGI_DYNAMIC_BOX_BODY_H___
