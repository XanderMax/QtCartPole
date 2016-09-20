#include "Item.h"


Item::Item(const QString &_name) : name(_name)
{
}

Item::~Item()
{

}

int Item::getX() const
{
    return getProperty("x").toInt();
}

void Item::setX(int x)
{
    setProperty("x", x);
}

int Item::getY() const
{
    return getProperty("y").toInt();
}

void Item::setY(int y)
{
    setProperty("y", y);
}

unsigned int Item::getWidth() const
{
    return getProperty("width").toUInt();
}

void Item::setWidth(unsigned int width)
{
    setProperty("width", width);
}

unsigned int Item::getHeight() const
{
    return getProperty("height").toUInt();
}

void Item::setHeight(unsigned int height)
{
    setProperty("height", height);
}

QString Item::getName() const
{
    return name;
}

