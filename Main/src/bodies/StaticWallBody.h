#ifndef JHKJHJKHJKJKHJKHJKJKHJK_JKHKJHKJHJKHJKHJKHJK
#define JHKJHJKHJKJKHJKHJKJKHJK_JKHKJHKJHJKHJKHJKHJK

#include "src/bodies/Box2DBody.h"


class StaticWallBody : public Box2DBody
{
private:

        b2PolygonShape* wallShape;

protected:

    virtual void onReady();

    virtual void onUpdateNotify();

    virtual void onItemAttached();
public:

    static Body *Allocator(const QString& name, const IWorld& world);

    StaticWallBody(const IWorld&);

    virtual ~StaticWallBody();

    virtual b2BodyDef* createBodyDefinition() const;
};



#endif //JHKJHJKHJKJKHJKHJKJKHJK_JKHKJHKJHJKHJKHJKHJK
