#ifndef UKKJHKHJKHJKHKJH_I_WORLD_PROVIDER_H
#define UKKJHKHJKHJKHKJH_I_WORLD_PROVIDER_H

#include <memory>

#include <QString>

#include "src/god/i/IDimensionProvider.h"

class IWorld;
class Body;

//This is an interface class thus it only contains public sections with only abstract methods
class IWorldProvider : public virtual IDimensionProvider
{
    public:

    virtual std::shared_ptr<IWorld> getWorld() const = 0;

    virtual std::shared_ptr<Body> getBody(const QString& name) const = 0;

    virtual bool isWorldProviderReady() const = 0;

};


#endif //UKKJHKHJKHJKHKJH_I_WORLD_PROVIDER_H
