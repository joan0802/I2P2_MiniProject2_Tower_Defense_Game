#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "AudioHelper.hpp"
#include "Group.hpp"
#include "TurretSelect.hpp"
#include "BulletSelect.hpp"
#include "PlayScene.hpp"
#include "ShootEffect.hpp"
#include "Point.hpp"

const int PlugGunTurret::Price = 40;
PlugGunTurret::PlugGunTurret(float x, float y) :
    // TODO 3 (1/5): You can imitate the 2 files: 'PlugGunTurret.hpp', 'PlugGunTurret.cpp' to create a new turret.
    Turret("play/tower-base.png", "play/turret-6.png", x, y, 200, Price, 1.5, 0, 1) {
    // Move center downward, since we the turret head is slightly biased upward
    Anchor.y += 8.0f / GetBitmapHeight();
}
void PlugGunTurret::CreateBullet() {
    Engine::Point diff = Engine::Point(cos(Rotation - ALLEGRO_PI / 2), sin(Rotation - ALLEGRO_PI / 2));
    float rotation = atan2(diff.y, diff.x);
    Engine::Point normalized = diff.Normalize();
    // Change bullet position to the front of the gun barrel.
    getPlayScene()->BulletGroup->AddNewObject(new WoodBullet(Position + normalized * 36, diff, rotation, this));
    // TODO 4 (2/2): Add a ShootEffect here. Remember you need to include the class.
    getPlayScene()->EffectGroup->AddNewObject(new ShootEffect(Position.x + diff.x * 36, Position.y + diff.y * 36));
    AudioHelper::PlayAudio("gun.wav");
}

const int MachineGunTurret::Price = 50;
MachineGunTurret::MachineGunTurret(float x, float y) :
    // TODO 3 (1/5): You can imitate the 2 files: 'PlugGunTurret.hpp', 'PlugGunTurret.cpp' to create a new turret.
    Turret("play/tower-base.png", "play/turret-1.png", x, y, 300, Price, 1, 1, 1) {
    // Move center downward, since we the turret head is slightly biased upward
    Anchor.y += 8.0f / GetBitmapHeight();
}
void MachineGunTurret::CreateBullet() {
    Engine::Point diff = Engine::Point(cos(Rotation - ALLEGRO_PI / 2), sin(Rotation - ALLEGRO_PI / 2));
    float rotation = atan2(diff.y, diff.x);
    Engine::Point normalized = diff.Normalize();
    // Change bullet position to the front of the gun barrel.
    getPlayScene()->BulletGroup->AddNewObject(new OrangeBullet(Position + normalized * 36, diff, rotation, this));
    // (2/2): Add a ShootEffect here. Remember you need to include the class.
    AudioHelper::PlayAudio("gun.wav");
}

const int DoubleMachineGunTurret::Price = 50;
DoubleMachineGunTurret::DoubleMachineGunTurret(float x, float y) :
    // TODO 3 (1/5): You can imitate the 2 files: 'PlugGunTurret.hpp', 'PlugGunTurret.cpp' to create a new turret.
    Turret("play/tower-base.png", "play/turret-2.png", x, y, 300, Price, 1, 2, 2) {
    // Move center downward, since we the turret head is slightly biased upward
    Anchor.y += 8.0f / GetBitmapHeight();
}
void DoubleMachineGunTurret::CreateBullet() {
    Engine::Point diff = Engine::Point(cos(Rotation - ALLEGRO_PI / 2), sin(Rotation - ALLEGRO_PI / 2));
    float rotation = atan2(diff.y, diff.x);
    Engine::Point normalized = diff.Normalize();
    // Change bullet position to the front of the gun barrel.
    Engine::Point pos = Position;
    pos.x -= 2;
    getPlayScene()->BulletGroup->AddNewObject(new FireBullet(pos + normalized * 36, diff, rotation, this));
    pos.x += 11;
    getPlayScene()->BulletGroup->AddNewObject(new FireBullet(pos + normalized * 36, diff, rotation, this));

    // (2/2): Add a ShootEffect here. Remember you need to include the class.
    AudioHelper::PlayAudio("gun.wav");
}

const int RotateTurret::Price = 70;
RotateTurret::RotateTurret(float x, float y) :
    // TODO 3 (1/5): You can imitate the 2 files: 'PlugGunTurret.hpp', 'PlugGunTurret.cpp' to create a new turret.
    Turret("play/tower-base.png", "play/turret-9.png", x, y, 200, Price, 100000000, 3, 4) {
    Enabled = false;
    // Move center downward, since we the turret head is slightly biased upward
    //Anchor.y += 8.0f / GetBitmapHeight();
}
void RotateTurret::CreateBullet() {
    Engine::Point diff = Engine::Point(cos(Rotation - ALLEGRO_PI / 2), sin(Rotation - ALLEGRO_PI / 2));
    float rotation = atan2(diff.y, diff.x);
    Engine::Point normalized = diff.Normalize();
    // Change bullet position to the front of the gun barrel.
    getPlayScene()->BulletGroup->AddNewObject(new RotateBullet(Position + normalized * 150, normalized, rotation, this));
    getPlayScene()->BulletGroup->AddNewObject(new RotateBullet(Position - normalized * 150, normalized, rotation, this));
    getPlayScene()->BulletGroup->AddNewObject(new RotateBullet(Position + normalized * 75, normalized, rotation, this));
    getPlayScene()->BulletGroup->AddNewObject(new RotateBullet(Position + normalized * 75, normalized, rotation, this));
    // (2/2): Add a ShootEffect here. Remember you need to include the class.
    AudioHelper::PlayAudio("gun.wav");
}

const int Shovel::Price = 0;
Shovel::Shovel(float x, float y) :
    // TODO 3 (1/5): You can imitate the 2 files: 'PlugGunTurret.hpp', 'PlugGunTurret.cpp' to create a new turret.
    Turret("play/floor.png", "play/shovel.png", x, y, 0, Price, 0, 4, 0) {
    // Move center downward, since we the turret head is slightly biased upward
    //Anchor.y += 8.0f / GetBitmapHeight();
}
void Shovel::CreateBullet() {}

const int Shifter::Price = 0;
Shifter::Shifter(float x, float y) :
    // TODO 3 (1/5): You can imitate the 2 files: 'PlugGunTurret.hpp', 'PlugGunTurret.cpp' to create a new turret.
    Turret("play/floor.png", "play/shifter.png", x, y, 0, Price, 0, 4, 0) {
    // Move center downward, since we the turret head is slightly biased upward
    //Anchor.y += 8.0f / GetBitmapHeight();
}
void Shifter::CreateBullet() {}