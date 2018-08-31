#include "gamemodel.h"

GameModel::GameModel(Images *images)
{
    playerField = new Field(images, 23, 42, 259, 252);
    enemyField = new Field(images, 358, 43, 260, 252);
    gameState = PLACING_SHIPS;
}

GameModel::~GameModel()
{
    delete playerField;
    delete enemyField;
}

void GameModel::setState(State state)
{
    gameState = state;
}

State GameModel::state()
{
    return gameState;
}

QPoint GameModel::changeCoordinates(int x, int y, CurrentField currentField)
{
    if (currentField == PLAYER_FIELD)
    {
        return playerField->coordinates(x, y);
    }
    else
    {
        return enemyField->coordinates(x, y);
    }
}
