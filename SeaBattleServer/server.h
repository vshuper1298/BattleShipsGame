#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QObject>
#include <QDebug>
#include <QTcpSocket>
#include <QMap>
#include <QString>
#include <QStringList>
#include <QRegExp>
#include <QTimer>
#include "field.h"
#include "client.h"

typedef QMap<int, Client> Clients;

class Server : public QObject
{
    Q_OBJECT
public:
    Server();
private slots:
    void onNewUserConnected();
    void onTimeout();
    void receivedData();
private:
    void parseData(const QString & cmd, int clientId);
    bool cellPlacement(const QString &cmd, Clients::iterator client);
    bool makeStep(const QString &cmd, Clients::iterator client);
    bool placeShips(const QString &ships, Clients::iterator client);
    void connectClients(Clients::iterator client1, Clients::iterator client2);
private:
    QTcpServer *server;
    Clients clients;
    QTimer *timer;
};

#endif // SERVER_H
