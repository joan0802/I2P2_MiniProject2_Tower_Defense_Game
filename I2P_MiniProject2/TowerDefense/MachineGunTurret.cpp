#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "AudioHelper.hpp"
#include "OrangeBullet.hpp"
#include "Group.hpp"
#include "MachineGunTurret.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"

const int MachineGunTurret::Price = 40;
MachineGunTurret::MachineGunTurret(float x, float y) :
    // TODO 3 (1/5): You can imitate the 2 files: 'PlugGunTurret.hpp', 'PlugGunTurret.cpp' to create a new turret.
    Turret("play/tower-base.png", "play/turret-1.png", x, y, 300, Price, 1, 1) {
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

const int DoubleMachineGunTurret::Price = 40;
DoubleMachineGunTurret::DoubleMachineGunTurret(float x, float y) :
    // TODO 3 (1/5): You can imitate the 2 files: 'PlugGunTurret.hpp', 'PlugGunTurret.cpp' to create a new turret.
    Turret("play/tower-base.png", "play/turret-2.png", x, y, 300, Price, 1, 2) {
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