#include <allegro5/allegro_primitives.h>
#include <allegro5/color.h>
#include <cmath>
#include <random>
#include <string>
#include <vector>
#include "AudioHelper.hpp"
#include "Group.hpp"
#include "Bomb.hpp"
#include "GameEngine.hpp"
#include "DirtyEffect.hpp"
#include "LOG.hpp"
#include "Collider.hpp"
#include "ExplosionEffect.hpp"
#include "Enemy.hpp"
#include "BulletSelect.hpp"
#include "Turret.hpp"
#include "PlayScene.hpp"
#include "ShootEffect.hpp"
#include "Point.hpp"

PlayScene* Bomb::getPlayScene() {
	return dynamic_cast<PlayScene*>(Engine::GameEngine::GetInstance().GetActiveScene());
}

const int Bomb::Price = 80;
Bomb::Bomb(float x, float y) :
    // TODO 3 (1/5): You can imitate the 2 files: 'PlugGunTurret.hpp', 'PlugGunTurret.cpp' to create a new turret.
    Turret("play/dirt.png", "play/bomb64.png", x, y, 1.5 * 64, Price, 1.5, 6, 1) {
    // Move center downward, since we the turret head is slightly biased upward
    Anchor.y += 8.0f / GetBitmapHeight();
}
void Bomb::CreateBullet() {}

void Bomb::OnExplode() {
	getPlayScene()->EffectGroup->AddNewObject(new ExplosionEffect(Position.x, Position.y));
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> distId(1, 3);
	std::uniform_int_distribution<std::mt19937::result_type> dist(1, 20);
	for (int i = 0; i < 10; i++) {
		// Random add 10 dirty effects.
		getPlayScene()->GroundEffectGroup->AddNewObject(new DirtyEffect("play/dirty-" + std::to_string(distId(rng)) + ".png", dist(rng), Position.x, Position.y));
	}
	PlayScene* scene = getPlayScene();
	for (auto& target : scene->EnemyGroup->GetObjects()) {
		Enemy* ene = dynamic_cast<Enemy*>(target);
		if (Engine::Collider::IsCircleOverlap(Position, 64*1.5, ene->Position, ene->CollisionRadius)) {
			Engine::LOG() << "Bomb!";
			ene->Hit(200);
		}
	}
}

void Bomb::Update(float deltaTime) {
	Sprite::Update(deltaTime);
	PlayScene* scene = getPlayScene();
	imgBase.Position = Position;
	imgBase.Tint = Tint;
	if (!Enabled)
		return;
	for (auto& it : scene->EnemyGroup->GetObjects()) {
		Enemy* enemy = dynamic_cast<Enemy*>(it);
		if (!enemy->Visible)
			continue;
		if (Engine::Collider::IsCircleOverlap(Position, 20, enemy->Position, enemy->CollisionRadius)) {
			OnExplode();
			getPlayScene()->TowerGroup->RemoveObject(objectIterator);
			return;
		}
	}
	return;
}