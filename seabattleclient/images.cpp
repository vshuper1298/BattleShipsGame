#include "images.h"

void Images::load()
{
    images.insert("field", QImage(":/image/background.png"));
    images.insert("dot", QImage(":/image/dot.png"));
    //images.insert("killed", QImage(":/image/kill.png"));
    images.insert("injured", QImage(":/image/injured.png"));
}

QImage& Images::get(const QString& imageName)
{
    QMap<QString, QImage>::iterator i = images.find(imageName);
    return i.value();
}

