#include "field.h"
#include <QPainter>

Field::Field(Images *images, int left, int top, int width, int height):
    pictures(images), left(left), top(top), width(width), height(height)
{
    field.fill(CLEAR, 100);
    image = new QImage(width, height, QImage::Format_ARGB32);
}

Field::~Field()
{
    delete image;
}

const QImage& Field::Image() const
{
    return *image;
}

void Field::redraw()
{
    image->fill(0);
    QPainter painter(image);
    double cfx = 1.0 * width / 10.0;
    double cfy = 1.0 * height / 10.0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            switch (cell(i, j)) {
            case DOT:
                painter.drawImage(i * cfx, j * cfy, pictures->get("dot"));
                break;
            case INJURED:
                painter.drawImage(i * cfx, j * cfy, pictures->get("injured"));
                break;
            case SHIP:
                painter.drawImage(i * cfx, j * cfy, pictures->get("killed"));
                break;
            default:
                break;
            }
        }
    }
}

Cell Field::cell(int x, int y)
{
    int n = y * 10 + x;

        if( x < 0 || y < 0 || x >= 10 || y >= 10 )
            return CLEAR;

        if( n >= 0 && n < field.size() )
            return field[n];

        //qDebug() << "ERROR: no such cell";
        return CLEAR;
}

void Field::setCell(int x, int y, Cell cell)
{
    int n = y * 10 + x;

    if(
        x >= 0 && y >= 0 && x < 10 && y < 10 &&
        n >= 0 && n < field.size()
    )
    {
        field[n] = cell;
        return;
    }
}

int Field::x()
{
    return left;
}

int Field::y()
{
    return top;
}

QPoint Field::coordinates(int x, int y)
{
    QPoint result;
    result.setX(-1);
    result.setY(-1);
    if (x < left || x > (left + width) || y < top || y > (top + height))
    {
        return result;
    }
    double cfx = 1.0 * width / 10.0;
    double cfy = 1.0 * height / 10.0;
    result.setX(1.0 * (x - left) / cfx);
    result.setY(1.0 * (y - top) / cfy);
    return result;
}

