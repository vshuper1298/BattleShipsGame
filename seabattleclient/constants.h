#ifndef CONSTANTS_H
#define CONSTANTS_H

enum State
{
    PLACING_SHIPS,
    WAITING_STEP,
    MAKING_STEP
};

enum Cell
{
    CLEAR = 0,
    SHIP,
    DOT,
    INJURED
};

#endif // CONSTANTS_H
