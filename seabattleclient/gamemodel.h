#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include "constants.h"
#include "field.h"

class GameModel
{
public:
    explicit GameModel(Images *images);
    ~GameModel();
//    Ship (int x, int y, int size = 1);
    QPoint changeCoordinates(int x, int y, CurrentField currentField);
    bool isCorrectPlacement();
    bool isShipSize(int x, int y, int size);
    bool isShipSingleDeck(int x, int y);
    void setState(State state);
    int shipsCount(int size);
    State state();
private:
    State gameState;
    Field *playerField;
    Field *enemyField;
};

#endif // GAMEMODEL_H
