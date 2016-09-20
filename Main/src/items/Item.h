#ifndef __GOOD_NEWS_EVERYONE_ITEM_H__
#define __GOOD_NEWS_EVERYONE_ITEM_H__

#include <QObject>
#include <QVariant>

class Simulation;

class Item
{
private:

protected:

        QString name;
public:

    Item(const QString& name);

    virtual ~Item();

    virtual QVariant getProperty(const QString& propName) const = 0;
    virtual void setProperty(const QString& propName, const QVariant& value) = 0;

    int getX() const;
    void setX(int x);

    int getY() const;
    void setY(int y);

    unsigned int getWidth() const;
    void setWidth(unsigned int width);

    unsigned int getHeight() const;
    void setHeight(unsigned int height);

    QString getName() const;
};


#endif //__GOOD_NEWS_EVERYONE_ITEM_H__
