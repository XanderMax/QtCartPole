#include "ViewItem.h"

#include "src/app/IApp.h"

Item *ViewItem::Allocator(const QString &name, const IApp &iApp)
{
    const std::shared_ptr<ViewItem>& view = iApp.getRootViewItem<ViewItem>();

    if(view != nullptr)
    {
        const std::shared_ptr<QObject>& viewObject = view->getObject();

        if(viewObject != nullptr)
        {
            QObject* object = viewObject->findChild<QObject*>(name);

            if(object != nullptr)
            {
                return new ViewItem(object, name);
            }
        }
    }

    return nullptr;
}

Item *ViewItem::Allocator(QObject *object)
{
    if(object != nullptr)
    {
        QString objectName = object->property("objectName").toString();

        if(objectName.isEmpty())
        {
            objectName = "__root__";
        }

        return new ViewItem(object, objectName);
    }

    return nullptr;
}

ViewItem::ViewItem(QObject *_item, const QString& _name) : Item(_name), item(_item)
{
}

ViewItem::~ViewItem()
{

}

QVariant ViewItem::getProperty(const QString &propName) const
{
    if(item != nullptr)
    {
        return item->property(propName.toStdString().c_str());
    }
    else
    {
        return QVariant();
    }
}

void ViewItem::setProperty(const QString &propName, const QVariant &value)
{
    if(item != nullptr)
    {
        item->setProperty(propName.toStdString().c_str(), value);
    }

}

QString ViewItem::getObjectName() const
{
    return getProperty("objectName").toString();
}

const std::shared_ptr<QObject>& ViewItem::getObject() const
{
    return item;
}
