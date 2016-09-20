#ifndef __DOH_VIEW_ITEM_H__
#define __DOH_VIEW_ITEM_H__

#include <memory>

#include <QObject>
#include <QVariant>

#include "src/items/Item.h"

class Simulation;
class IApp;


class ViewItem : public Item
{
private:

    std::shared_ptr<QObject> item;

protected:

    ViewItem(QObject* _item, const QString& name);

public:

    static Item* Allocator(const QString& name, const IApp& iApp);
    static Item* Allocator(QObject* object);

    virtual ~ViewItem();

    virtual QVariant getProperty(const QString& propName) const;
    virtual void setProperty(const QString& propName, const QVariant& value);

    QString getObjectName() const;

    const std::shared_ptr<QObject> &getObject() const;



};


#endif //__DOH_VIEW_ITEM_H__
