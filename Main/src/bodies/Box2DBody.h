#ifndef HKHKJHJKJKHJKHJKHJKK_BOX_2d_BODY______
#define HKHKJHJKJKHJKHJKHJKK_BOX_2d_BODY______

#include <QObject>

#include "src/bodies/Body.h"

class Box2DBody : public Body
{

    Q_OBJECT

private:


protected:

    b2Body* box2dBody;

    virtual void onUpdateNotify();

    virtual void onItemAttached();

    virtual void onUpdateSignal();
public:

    Box2DBody(const IWorld&);
    virtual ~Box2DBody();

    int getXCoordinate() const;
    int getYCoordinate() const;

    int getRawItemX() const;
    int getRawItemY() const;

    float getYRelativeToItem() const;
    float getXRelativeToItem() const;

    float getRawX() const;
    float getRawY() const;

    float getWidth() const;
    float getHeight() const;

public slots:

    void updateOnSignal();

signals:

    void signalUpdate();

};



#endif //HKHKJHJKJKHJKHJKHJKK_BOX_2d_BODY______
