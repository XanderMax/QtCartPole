#include "IApp.h"

#include "src/items/Item.h"
#include "src/items/ViewItem.h"

#include "src/god/i/IWorldProvider.h"

std::shared_ptr<Item> IApp::getItemAnyway(const QString &name)
{
    std::shared_ptr<Item> itemPtr = _getItem(name);

    if(itemPtr != nullptr)
    {
        return itemPtr;
    }
    else
    {
        std::shared_ptr<Item> newItemPtr(ViewItem::Allocator(name, *this));
        bool result = _addItem(name, newItemPtr);

        return (result ? newItemPtr : nullptr);
    }
}

IApp::IApp(const IWorldProvider &_worldProvider) : worldProvider(_worldProvider)
{

}

unsigned int IApp::getScreenWidth() const
{
    if(rootViewItem != nullptr)
    {
        return rootViewItem->getWidth();
    }

    return 0;
}

unsigned int IApp::getScreenHeight() const
{
    if(rootViewItem != nullptr)
    {
        return rootViewItem->getHeight();
    }

    return 0;
}

const IWorldProvider &IApp::getWorldProvider() const
{
    return worldProvider;
}

const IDimensionProvider &IApp::getDimensionProvider() const
{
    return getWorldProvider();
}
