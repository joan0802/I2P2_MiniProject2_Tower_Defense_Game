#ifndef MACHINEGUNTURRET_HPP
#define MACHINEGUNTURRET_HPP
#include "Turret.hpp"

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
#endif // PLUGGUNTURRET_HPP
