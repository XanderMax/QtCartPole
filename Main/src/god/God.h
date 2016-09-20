#ifndef __IN_GOD_WE_TRUST_THE_REST_WE_CHECK_FOR_NULL_GOD_H__
#define __IN_GOD_WE_TRUST_THE_REST_WE_CHECK_FOR_NULL_GOD_H__

#include <QDebug>

#include "src/god/i/IAppProvider.h"
#include "src/god/i/IWorldProvider.h"
#include "src/god/i/IDimensionProvider.h"

#include "src/app/IApp.h"
#include "src/world/IWorld.h"
#include "src/dimensions/IDimension.h"

class God : public IAppProvider, public IWorldProvider
{
private:

    std::shared_ptr<IApp> app;

    std::shared_ptr<IWorld> world;

    std::shared_ptr<IDimension> dimension;

protected:

public:

    God();
    virtual ~God();

    template <typename TIApp, typename ... TArgs>
    void setApp(TArgs ... args)
    {
        qDebug() << __PRETTY_FUNCTION__;
        std::shared_ptr<IApp> appPtr(new TIApp(*this, args...));

        if(appPtr != nullptr && app == nullptr)
        {
            app = appPtr;
        }
    }

    template <typename TIWorld, typename ... TArgs>
    void setWorld(TArgs ... args)
    {
        qDebug() << __PRETTY_FUNCTION__;
        std::shared_ptr<IWorld> worldPtr(new TIWorld(*this, args...));

        if(worldPtr != nullptr && world == nullptr)
        {
            world = worldPtr;
        }
    }

    template <typename TIDimension, typename ... TArgs>
    void setDimension(TArgs ... args)
    {
        qDebug() << __PRETTY_FUNCTION__;
        std::shared_ptr<IDimension> dimensionPtr(new TIDimension(*this, args...));

        if(dimensionPtr != nullptr && dimension == nullptr)
        {
            dimension = dimensionPtr;
        }

    }

    //################### IAppProvider interface ####################

    std::shared_ptr<IApp> getApp() const;

    std::shared_ptr<Item> getItem(const QString &name) const;

    std::shared_ptr<Item> getRootViewItem() const;

    unsigned int getScreenWidth() const;

    unsigned int getScreenHeight() const;

    bool isAppProviderReady() const;


    //################### IWorldProvider interface ####################

    std::shared_ptr<IWorld> getWorld() const;

    std::shared_ptr<Body> getBody(const QString& name) const;

    bool isWorldProviderReady() const;


    //################### IDimensionProvider interface ####################

    std::shared_ptr<IDimension> getDimension() const;


    //################### Gods powers ####################

    void start();


    template <typename TItem, typename ... TArgs>
    bool addItem(const QString& name, TArgs ... args)
    {
        if(app != nullptr)
        {
            return app->addItem<TItem>(name, args...);
        }

        return false;
    }

    template <typename TBody, typename ... TArgs>
    bool addBody(const QString& name, TArgs ... args)
    {
        if(world != nullptr)
        {
            return world->addBody<TBody>(name, args...);
        }

        return false;
    }




};



#endif //__IN_GOD_WE_TRUST_THE_REST_WE_CHECK_FOR_NULL_GOD_H__
