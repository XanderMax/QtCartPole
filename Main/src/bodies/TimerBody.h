#ifndef __KISS_MY_SHINY_METAL_ASS_TIMER_BODY_H__
#define __KISS_MY_SHINY_METAL_ASS_TIMER_BODY_H__

#include <QObject>

#include "Body.h"

class TimerBody : public Body
{
    Q_OBJECT
private:
protected:

    void onReady();
public:

    static Body *Allocator(const QString& name, const IWorld& world);

    TimerBody(const IWorld &world);
    ~TimerBody() {}

    b2BodyDef* createBodyDefinition() const;

public slots:

    void onTimeout();
};


#endif //__KISS_MY_SHINY_METAL_ASS_TIMER_BODY_H__
