#ifndef PLUGGUNTURRET_HPP
#define PLUGGUNTURRET_HPP
#include <allegro5/bitmap.h>
#include <memory>
#include <vector>
#include "Turret.hpp"
#include "Sprite.hpp"

class PlugGunTurret : public Turret {
public:
    static const int Price;
    PlugGunTurret(float x, float y);
    void CreateBullet() override;
};

#endif // PLUGGUNTURRET_HPP
