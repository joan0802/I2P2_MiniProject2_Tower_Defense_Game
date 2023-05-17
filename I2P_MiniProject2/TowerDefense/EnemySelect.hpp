#ifndef ENEMYSELECT_HPP
#define ENEMYSELECT_HPP
#include "Enemy.hpp"

class RedNormalEnemy : public Enemy {
public:
    RedNormalEnemy(int x, int y);
};

class TwoDiceEnemy : public Enemy {
public:
    TwoDiceEnemy(int x, int y);
};

class DiceEnemy : public Enemy {
public:
    DiceEnemy(int x, int y);
};
#endif // REDNORMALENEMY_HPP
