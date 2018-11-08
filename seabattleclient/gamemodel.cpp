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

bool GameModel::isShipSingleDeck(int x, int y)
{
    if (playerField->cell(x + 1, y) != SHIP)
    {
        if(playerField->cell(x - 1, y) != SHIP)
        {
            if(playerField->cell(x, y + 1) != SHIP)
            {
                if(playerField->cell(x, y - 1) != SHIP)
                {
                    return true;
                }
            }
        }
    }
    else
    {
        return false;
    }
}

bool GameModel::isShipSize(int x, int y, int size)
{
    if (playerField->cell(x, y) != SHIP)
    {
        return false;
    }
    if (size == 1)
    {
        return isShipSingleDeck(x, y);
    }
    if (playerField->cell(x - 1, y) == SHIP || playerField->cell(x - 1, y) == SHIP)
        return false;
    int i = 0;
    while (playerField->cell(x + i, y) == SHIP)
    {
        ++i;
    }
    while (playerField->cell(x, y + i) == SHIP)
    {
        ++i;
    }
    if (size == i)
        return true;
    else
        return false;
}
