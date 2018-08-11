#ifndef FIELD_H
#define FIELD_H

#include "images.h"
#include "constants.h"
#include <QImage>
#include <QPixmap>
#include <QVector>

class Field
{
public:
    Field(Images *images, int left, int top, int width, int height);
    ~Field();
    const QImage & Image() const;
    void redraw();
    Cell cell(int x, int y);
    void setCell(int x, int y, Cell cell);
    QPoint coordinates(int x, int y);
    int x();
    int y();
    
private:
    QImage *image;
    Images *pictures;
    QVector<Cell> field;
    int left;
    int top;
    int width;
    int height;
};

#endif // FIELD_H
