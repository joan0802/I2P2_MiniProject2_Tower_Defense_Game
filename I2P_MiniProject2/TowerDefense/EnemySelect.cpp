#include <allegro5/allegro_primitives.h>
#include <allegro5/color.h>
#include <cmath>
#include <random>
#include <string>
#include <vector>
#include "Allegro5Exception.hpp"
#include "AudioHelper.hpp"
#include "Bullet.hpp"
#include "DirtyEffect.hpp"
#include "Enemy.hpp"
#include "ExplosionEffect.hpp"
#include "GameEngine.hpp"
#include "Group.hpp"
#include "IScene.hpp"
#include "LOG.hpp"
#include "PlayScene.hpp"
#include "Turret.hpp"
#include "EnemySelect.hpp"
#include <list>
#include <vector>
#include <string>

#include "Point.hpp"
#include "Sprite.hpp"

RedNormalEnemy::RedNormalEnemy(int x, int y) : Enemy("play/enemy-10.png", x, y, 25, 45, 7, 5, 0) {
    // TODO 2 (1/3): You can imitate the 2 files: 'RedNormalEnemy.hpp', 'RedNormalEnemy.cpp' to create a new enemy.
}

TwoDiceEnemy::TwoDiceEnemy(int x, int y) : Enemy("play/dice-2.png", x, y, 25, 70, 7, 5, 2) {
}

DiceEnemy::DiceEnemy(int x, int y) : Enemy("play/dice-1.png", x, y, 25, 55, 7, 5, 1) {
}