#ifndef __EYE_PHONE_IS_BEST_APP_H__
#define __EYE_PHONE_IS_BEST_APP_H__

#include <QObject>
#include <QString>
#include <QMap>
#include <QQmlComponent>
#include <QQmlApplicationEngine>

#include "src/app/IApp.h"


class Item;

class App : public IApp
{

    Q_OBJECT

private:

    QQmlApplicationEngine& engine;

    QMap<QString, std::shared_ptr<Item>> items;

    std::shared_ptr<QQmlComponent> rootComponent;


    void initView();

protected:

    virtual std::shared_ptr<Item> _getItem(const QString& name) const;

    virtual bool _addItem(const QString& name, const std::shared_ptr<Item>& itemPtr);

public:

    App(const IWorldProvider &worldProvider, QQmlApplicationEngine& _engine);

    virtual ~App();


};


#endif //__EYE_PHONE_IS_BEST_APP_H__
