#include "DXUT.h"
#include "PlayerBullet.h"

void PlayerBullet::Init()
{
	SetTexture(L"Resource/PlayerBullet.png", { 114,67 });
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

void PlayerBullet::SetBullet(D3DXVECTOR2 direction, float a_speed, float a_destroyTime)
{
	destroyTime = a_destroyTime;
	speed = a_speed;
	D3DXVec2Normalize(&direction, &direction);
	force = direction * speed;
}
