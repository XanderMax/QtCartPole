#ifndef JILLHKLHJ_SDDSDSD_DSSDSDSD_I_APP_PROVIDER_H
#define JILLHKLHJ_SDDSDSD_DSSDSDSD_I_APP_PROVIDER_H

#include <memory>

#include <QString>

#include "src/god/i/IDimensionProvider.h"

class IApp;
class Item;

//This is an interface class thus it only contains public sections with only abstract methods
class IAppProvider : public virtual IDimensionProvider
{
public:

    virtual std::shared_ptr<IApp> getApp() const = 0;

    virtual std::shared_ptr<Item> getItem(const QString& name) const = 0;

    virtual std::shared_ptr<Item> getRootViewItem() const = 0;

    virtual unsigned int getScreenWidth() const = 0;
    virtual unsigned int getScreenHeight() const = 0;

    virtual bool isAppProviderReady() const = 0;

};



#endif //JILLHKLHJ_SDDSDSD_DSSDSDSD_I_APP_PROVIDER_H
