#ifndef FIELD_H
#define FIELD_H

#include <QString>
#include <QVector>
#include "constants.h"

class Field
{
public:
    void initCells(const QString &data);
    eCell cell(int x, int y);
    void setCell(int x, int y, eCell cell);
private:
    QVector<eCell> field;
};

#endif // FIELD_H
