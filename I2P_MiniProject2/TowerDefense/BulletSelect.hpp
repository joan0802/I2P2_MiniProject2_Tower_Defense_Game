#ifndef BULLETSELECT_HPP
#define BULLETSELECT_HPP
#include "Bullet.hpp"

class Enemy;
class Turret;
class PlayScene;
namespace Engine {
    struct Point;
}  // namespace Engine

class OrangeBullet : public Bullet {
public:
    explicit OrangeBullet(Engine::Point position, Engine::Point forwardDirection, float rotation, Turret* parent);
    void OnExplode(Enemy* enemy) override;
};

class WoodBullet : public Bullet {
public:
    explicit WoodBullet(Engine::Point position, Engine::Point forwardDirection, float rotation, Turret* parent);
    void OnExplode(Enemy* enemy) override;
};

class DoubleBullet : public Bullet {
public:
    explicit DoubleBullet(Engine::Point position, Engine::Point forwardDirection, float rotation, Turret* parent);
    void OnExplode(Enemy* enemy) override;
};
#endif // WOODBULLET_HPP
