#ifndef CONSTANTS_H
#define CONSTANTS_H

const int kSize = 10;

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
