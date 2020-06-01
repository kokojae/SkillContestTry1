#include "DXUT.h"
#include "EnemyBullet.h"

void EnemyBullet::Init()
{
	SetTexture(L"Resource/EnemyBullet2.png", { 15,11 });
	SetCollider({ 15,11 }, Layer::ENEMY_BULLET);
	z = 1;
}

void EnemyBullet::Update()
{
	AddForce();
	Destroy();
}

void EnemyBullet::Destroy()
{
	destroyTime -= DXUTGetElapsedTime();
	if (destroyTime <= 0)
		destroy = true;
}

void EnemyBullet::SetBullet(D3DXVECTOR2 direction, float a_speed, float a_damage, float a_destroyTime)
{
	destroyTime = a_destroyTime;
	damage = a_damage;
	speed = a_speed;
	D3DXVec2Normalize(&direction, &direction);
	force = direction * speed;
}
