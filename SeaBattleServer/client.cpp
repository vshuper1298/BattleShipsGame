#include "client.h"

void Client::send(const QString &cmd)
{
    QTextStream clientStream(socket);
    clientStream << cmd << "\n";
}
