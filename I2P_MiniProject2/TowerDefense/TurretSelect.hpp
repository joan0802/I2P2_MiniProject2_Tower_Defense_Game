#ifndef TURRETSELECT_HPP
#define TURRETSELECT_HPP
#include "Turret.hpp"

class PlugGunTurret : public Turret {
public:
    static const int Price;
    PlugGunTurret(float x, float y);
    void CreateBullet() override;
};

class MachineGunTurret : public Turret {
public:
    static const int Price;
    MachineGunTurret(float x, float y);
    void CreateBullet() override;
};

class DoubleMachineGunTurret : public Turret {
public:
    static const int Price;
    DoubleMachineGunTurret(float x, float y);
    void CreateBullet() override;
};

class RotateTurret : public Turret {
public:
    static const int Price;
    RotateTurret(float x, float y);
    void CreateBullet() override;
};

class Shovel : public Turret {
public:
    static const int Price;
    Shovel(float x, float y);
    void CreateBullet() override;
};

class Shifter : public Turret {
public:
    static const int Price;
    Shifter(float x, float y);
    void CreateBullet() override;
};

#endif // PLUGGUNTURRET_HPP
