#include "server.h"

Server::Server()
{
    server = new QTcpServer(this);
    connect (server, SIGNAL(newConnection()), this, SLOT(onNewUserConnected()));
    server->listen(QHostAddress::Any, 1234);
    qDebug() << "Server started";
    timer = new QTimer(this);
    timer->setInterval(3000);
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimeout()));
    timer->start();
}

void Server::onNewUserConnected()
{
    Client client;
    client.socket = server->nextPendingConnection();
    client.status = CONNECTED;
    client.playingWith = clients.end();
    int clientId = client.socket->socketDescriptor();
    clients.insert(clientId, client);
    connect (client.socket, SIGNAL(readyRead()), this, SLOT(receivedData()));
    qDebug() << "Client connected";
}

void Server::onTimeout()
{

}

void Server::receivedData()
{
    QTcpSocket *clientSocket = (QTcpSocket*)sender();
    QByteArray data = clientSocket->readAll();
    parseData(data, clientSocket->socketDescriptor());
}

void Server::parseData(const QString & cmd, int clientId)
{
    Clients::iterator i = clients.find(clientId);
    if (i == clients.end())
    {
        return;
    }

    if (cellPlacement(cmd, i))
    {
        return;
    }

    if (makeStep(cmd, i))
    {
        return;
    }

    i->send("wrongcmd:");
}

bool Server::cellPlacement(const QString& cmd, Clients::iterator client)
{
    QRegExp rx("field:([01]+:");
    if (rx.indexIn(cmd) != -1)
    {
        qDebug() << "Field: " << rx.cap(1);
        if (!placeShips(rx.cap(1), client))
        {
            return false;
        }
        client->status = READY;
        return true;
    }
    return false;
}

bool Server::makeStep(const QString& cmd, Clients::iterator client)
{
    QRegExp rx("step:(\\d):(\\d):");
    if (rx.indexIn(cmd) != -1)
    {
        if (client->status == MAKING_STEP)
        {
            int x = rx.cap(1).toInt();
            int y = rx.cap(2).toInt();
            QString response1;
            QString response2;
            eCell current = client->playingWith->field.cell(x, y);
            if (current == CLEAR || current == DOT)
            {
                current = DOT;
                response1 = QString("field2:miss:%1:%2").arg(x).arg(y);
                response2 = QString("field1:miss:%1:%2").arg(x).arg(y);
            }
            else
            {
                current = INJURED;
                response1 = QString("field2:injured:%1:%2").arg(x).arg(y);
                response2 = QString("field1:injured:%1:%2").arg(x).arg(y);
                client->status = MAKING_STEP;
                client->playingWith->status = WAITING_STEP;
                client->send(response1);
                client->playingWith->send(response2);
                client->send("go:");
            }
        }
    }
}

bool Server::placeShips(const QString &ships, Clients::iterator client)
{

}

void Server::connectClients(Clients::iterator client1, Clients::iterator client2)
{
    client1->status = MAKING_STEP;
    client2->status = WAITING_STEP;
    client1->playingWith = client2;
    client2->playingWith = client1;
    QTextStream clientStream(client1->socket);
    clientStream << "go:\n";
}
