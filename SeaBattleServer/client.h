#ifndef CLIENT_H
#define CLIENT_H

#include <QTcpSocket>
#include <QMap>
#include "field.h"
#include "constants.h"

struct Client
{
    QTcpSocket *socket;
    ClientStatus status;
    QMap<int, Client>::iterator playingWith;
    void send(const QString &cmd);
    Field field;
};

#endif // CLIENT_H
