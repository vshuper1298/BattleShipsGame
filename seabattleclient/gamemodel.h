#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include "constants.h"
#include "field.h"

class GameModel
{
public:
    GameModel(Images *images);
    ~GameModel();
//    Ship (int x, int y, int size = 1);
    QPoint changeCoordinates(int x, int y, CurrentField currentField);
    bool isCorrectPlacement();
    void setState(State state);
    State state();
private:
    State gameState;
    Field *playerField;
    Field *enemyField;
};

#endif // GAMEMODEL_H
