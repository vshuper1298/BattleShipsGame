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
