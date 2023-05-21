#ifndef ORANGEBULLET_HPP
#define ORANGEBULLET_HPP
#include "Bullet.hpp"

class Enemy;
class Turret;
namespace Engine {
    struct Point;
}  // namespace Engine

class OrangeBullet : public Bullet {
public:
    explicit OrangeBullet(Engine::Point position, Engine::Point forwardDirection, float rotation, Turret* parent);
    void OnExplode(Enemy* enemy) override;
};
class FireBullet : public Bullet {
public:
    explicit FireBullet(Engine::Point position, Engine::Point forwardDirection, float rotation, Turret* parent);
    void OnExplode(Enemy* enemy) override;
};
#endif // WOODBULLET_HPP
