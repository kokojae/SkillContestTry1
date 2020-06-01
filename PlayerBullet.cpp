#include "DXUT.h"
#include "PlayerBullet.h"

void PlayerBullet::Init()
{
	SetTexture(L"Resource/PlayerBullet.png", { 114,67 });
	SetCollider({ 35,35 }, Layer::PLAYER_BULLET);
	z = 2;
}

void PlayerBullet::Update()
{
	AddForce();
	Destroy();
}

void PlayerBullet::Destroy()
{
	destroyTime -= DXUTGetElapsedTime();
	if (destroyTime <= 0)
		destroy = true;
}

void PlayerBullet::SetBullet(D3DXVECTOR2 direction, float a_speed, float a_damage, float a_destroyTime)
{
	destroyTime = a_destroyTime;
	damage = a_damage;
	speed = a_speed;
	D3DXVec2Normalize(&direction, &direction);
	force = direction * speed;
}
