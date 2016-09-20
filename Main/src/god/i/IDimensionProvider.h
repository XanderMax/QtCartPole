#ifndef HJKHJKJSJKHJKHJKJK_FSF_SF_I_DIMENSION_PROVIDER_H
#define HJKHJKJSJKHJKHJKJK_FSF_SF_I_DIMENSION_PROVIDER_H

#include <memory>

class IDimension;

//This is an interface class thus it only contains public sections with only abstract methods
class IDimensionProvider
{
public:

    virtual std::shared_ptr<IDimension> getDimension() const = 0;

};



#endif //HJKHJKJSJKHJKHJKJK_FSF_SF_I_DIMENSION_PROVIDER_H
