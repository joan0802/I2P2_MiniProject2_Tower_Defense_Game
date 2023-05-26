#ifndef BOMB_HPP
#define BOMB_HPP
#include <allegro5/bitmap.h>
#include <memory>
#include <vector>

#include "Sprite.hpp"
#include "Turret.hpp"

enum TileType {
	TILE_DIRT,
	TILE_FLOOR,
	TILE_OCCUPIED,
	TILE_MACHINEGUN,
	TILE_BOMB
};

class Bomb : public Turret {
protected:
    PlayScene* getPlayScene();
public:
    static const int Price;
    Bomb(float x, float y);
    void CreateBullet() override;
    void Update(float deltatime) override;
    void OnExplode();
};
#endif // PLANE_HPP
