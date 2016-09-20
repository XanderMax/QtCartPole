#ifndef __I_AM_LURE_I_WORLD_H__
#define __I_AM_LURE_I_WORLD_H__

#include <thread>

#include <QDebug>

#include "src/bodies/Body.h"
#include "Box2D/Box2D.h"

class IAppProvider;
class IDimensionProvider;

class IWorld
{
private:

    const IAppProvider& appProvider;

    std::shared_ptr<b2World> box2World;

    bool started;

protected:

    IWorld(const IAppProvider&);

    virtual std::shared_ptr<Body> _getBody(const QString& name) const = 0;

    virtual bool _addBody(const QString& name, const std::shared_ptr<Body>& body) = 0;

    virtual bool _start() = 0;

    virtual float _getWidth() const {return 0.0f;}
    virtual float _getHeight() const {return 0.0f;}
    virtual float _getRatio() const {return 0.0f;}

    template <typename TB2World = b2World, typename ... TArgs>
    void setWorld(TArgs ... args)
    {
        if(box2World == nullptr)
        {
            box2World = std::shared_ptr<b2World>(new TB2World(args...));
        }
    }

public:

    virtual ~IWorld(){}

    bool start();

    const IAppProvider& getAppProvider() const;

    const IDimensionProvider& getDimensionProvider() const;

    bool isStarted() const;

    float getWidth() const;
    float getHeight() const;
    float getRatio() const;


    std::shared_ptr<b2World> getWorld() const;

    template <typename TBody = Body>
    std::shared_ptr<TBody> getBody(const QString& name) const
    {
        std::shared_ptr<Body> bodyPtr = _getBody(name);

        if(bodyPtr != nullptr)
        {
            return std::dynamic_pointer_cast<TBody>(bodyPtr);
        }

        return nullptr;
    }

    template <typename TBody, typename ... TArgs>
    bool addBody(const QString& name, TArgs ... args)
    {
        qDebug() << __PRETTY_FUNCTION__ << name;
        std::shared_ptr<Body> bodyPtr(TBody::Allocator(name, *this, args...));

        if(bodyPtr != nullptr)
        {
            return _addBody(name, bodyPtr);
        }
        else
        {
            qWarning() << "Failed to allocate body " << name;
            return false;
        }
    }



};



#endif //__I_AM_LURE_I_WORLD_H__
