#include "App.h"

#include <QDebug>

#include "src/god/i/IWorldProvider.h"

#include "src/items/ViewItem.h"


void App::initView()
{
    rootComponent = std::shared_ptr<QQmlComponent>(new QQmlComponent(&engine, QUrl(QStringLiteral("qrc:/main.qml"))));

    if(rootComponent != nullptr)
    {
        rootViewItem = std::shared_ptr<ViewItem>((ViewItem*)ViewItem::Allocator(rootComponent->create()));
    }

    qDebug() << __PRETTY_FUNCTION__ << getScreenWidth() << getScreenHeight();
}

std::shared_ptr<Item> App::_getItem(const QString &name) const
{
    return items.value(name, nullptr);
}

bool App::_addItem(const QString &name, const std::shared_ptr<Item> &itemPtr)
{
    if(items.value(name, nullptr) == nullptr)
    {
        items.insert(name, itemPtr);
        return true;
    }

    return false;
}

App::App(const IWorldProvider &worldProvider, QQmlApplicationEngine& _engine) : IApp(worldProvider), engine(_engine)
{
    initView();
}

App::~App()
{

}
