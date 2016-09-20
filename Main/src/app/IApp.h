#ifndef __EYE_PHONE_IS_BEST_I_APP_H__
#define __EYE_PHONE_IS_BEST_I_APP_H__

#include <memory>

#include <QObject>
#include <QDebug>

class Item;
class IWorldProvider;
class IDimensionProvider;

//TODO: Rename class to AppBase
class IApp : public QObject
{
private:

    const IWorldProvider& worldProvider;

    std::shared_ptr<Item> getItemAnyway(const QString& name);

protected:

    //this actualy declares the screen;
    std::shared_ptr<Item> rootViewItem;

    IApp(const IWorldProvider&);

    virtual std::shared_ptr<Item> _getItem(const QString& name) const = 0;

    virtual bool _addItem(const QString& name, const std::shared_ptr<Item>& itemPtr) = 0;



public:

    virtual ~IApp(){}

    unsigned int getScreenWidth() const;
    unsigned int getScreenHeight() const;

    const IWorldProvider& getWorldProvider() const;

    const IDimensionProvider& getDimensionProvider() const;

    template <typename TItem = Item>
    std::shared_ptr<Item> getItemForcfully(const QString& name)
    {
        std::shared_ptr<Item> itemPtr = getItemAnyway(name);

        if(itemPtr != nullptr)
        {
            return std::dynamic_pointer_cast<TItem>(itemPtr);
        }

        return nullptr;
    }

    template <typename TItem = Item>
    std::shared_ptr<Item> getItem(const QString& name) const
    {
        std::shared_ptr<Item> itemPtr = _getItem(name);

        if(itemPtr != nullptr)
        {
            return std::dynamic_pointer_cast<TItem>(itemPtr);
        }

        return nullptr;
    }

    template <typename TItem = Item>
    std::shared_ptr<TItem> getRootViewItem() const
    {
        if(rootViewItem != nullptr)
        {
            return std::dynamic_pointer_cast<TItem>(rootViewItem);
        }

        return nullptr;
    }

    template <typename TItem, typename ... TArgs>
    bool addItem(const QString& objectName, TArgs ... args)
    {
        qDebug() << __PRETTY_FUNCTION__ << objectName;
        std::shared_ptr<Item> itemPtr(TItem::Allocator(objectName, *this, args...));

        if(itemPtr != nullptr)
        {
            return _addItem(objectName, itemPtr);;
        }
        else
        {
            qWarning() << "Failed to allocate an item " << objectName;
            return false;
        }
    }
};


#endif //__EYE_PHONE_IS_BEST_I_APP_H__
