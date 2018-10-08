#include "field.h"

eCell Field::cell(int x, int y)
{
    int n = y * 10 + x;

        if( x < 0 || y < 0 || x >= 10 || y >= 10 )
            return CLEAR;

        if( n >= 0 && n < field.size() )
            return field[n];

        //qDebug() << "ERROR: no such cell";
        return CLEAR;
}

void Field::setCell(int x, int y, eCell cell)
{
    int n = y * 10 + x;

    if(x >= 0 && y >= 0 && x < 10 && y < 10 &&
        n >= 0 && n < field.size())
    {
        field[n] = cell;
        return;
    }
}

void Field::initCells(const QString &data)
{
    auto it = data.begin() + 1;
        for(int i = 0; i < fieldSize; i++)
        {
            field.push_back(eCell(QString(*it).toInt()));
            it++;
        }
}
