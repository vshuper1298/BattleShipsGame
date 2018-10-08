#ifndef CONSTANTS_H
#define CONSTANTS_H

const int fieldSize = 100;

enum ClientStatus
{
    CONNECTED = 0,
    READY,
    WAITING_STEP,
    MAKING_STEP
};

enum eCell
{
    CLEAR = 0,
    SHIP,
    DOT,
    INJURED
};
#endif // CONSTANTS_H
