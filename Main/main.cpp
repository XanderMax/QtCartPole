#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlComponent>

#include <iostream>

#include "src/god/God.h"

#include "src/app/App.h"

#include "src/world/World.h"

#include "src/items/ViewItem.h"

#include "src/bodies/TimerBody.h"
#include "src/bodies/StaticWallBody.h"
#include "src/bodies/DynamicBoxBody.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);


    QQmlApplicationEngine engine;

    God* god = new God();

    god->setApp<App, QQmlApplicationEngine&>(engine);
    god->setWorld<World>(50.0f);

    god->addItem<ViewItem>("rect");
    god->addItem<ViewItem>("ground");
    god->addItem<ViewItem>("bar");

    god->addBody<DynamicBoxBody>("rect");
    god->addBody<StaticWallBody>("bar");
    god->addBody<StaticWallBody>("ground");


    god->start();

    return app.exec();
}
