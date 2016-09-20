#ifndef __I_AM_LURE_WORLD_H__
#define __I_AM_LURE_WORLD_H__

#include "src/world/IWorld.h"

class Body;

class World : public IWorld
{
private:

    const float width;

    std::thread* b2Loop;

    QMap<QString, std::shared_ptr<Body>> bodies;

    bool runStep();
    void updateWorld();

    void execLoop();

    float calculateHeight(float width) const;
    float calculateRatio(float width) const;

protected:

    b2Vec2 gravityVector;

    std::shared_ptr<Body> _getBody(const QString& name) const;

    bool _addBody(const QString& name, const std::shared_ptr<Body>& body);

    bool _start();

    float _getWidth() const;
    float _getHeight() const;
    float _getRatio() const;

public:

    World(const IAppProvider&, float _width);

    virtual ~World() {}







};



#endif //__I_AM_LURE_WORLD_H__
