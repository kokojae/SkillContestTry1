#include "DXUT.h"
#include "BombBullet.h"
#include "SkillContestTry1.h"

void BombBullet::Init()
{
	SetTexture(L"Resource/PlayerBullet2.png", { 55,52 }, { 3.5,3.5 });
	SetCollider(info.size * info.scale.x, Layer::BOMB);
	z = 5;
}

void BombBullet::Update()
{
	Move();
	AddForce();
	Hit();
	Destroy();
}

void BombBullet::Move()
{
	force.x = sin(t) * sca;
	force.y = cos(t) * sca;
	t += 0.1;
	sca = 1;
}

void BombBullet::Hit()
{
	auto inst = PlaceMeeting({ 0,0 }, Layer::ENEMY | Layer::ENEMY_BULLET);

	if (inst != nullptr)
	{
		auto enemy = dynamic_cast<Enemy*>(inst);
		if (enemy != nullptr)
		{
			enemy->hp -= damage;
			if (enemy->hp <= 0)
				enemy->destroy = true;
		}

		auto bullet = dynamic_cast<EnemyBullet*>(inst);
		if (bullet != nullptr)
		{
			bullet->destroy = true;
		}
	}
}

void BombBullet::Destroy()
{
	destroyTime -= DXUTGetElapsedTime();
	if (destroyTime <= 0)
		destroy = true;
}

void BombBullet::SetBullet(D3DXVECTOR2 direction, float a_speed, float a_damage, float a_destroyTime)
{
	destroyTime = a_destroyTime;
	damage = a_damage;
	speed = a_speed;
	D3DXVec2Normalize(&direction, &direction);
	force = direction * speed;
}
