#include "DXUT.h"
#include "Sheild.h"
#include "SkillContestTry1.h"

void Sheild::Init()
{
	SetTexture(L"Resource/Sheild.png", { 72,71 }, { 2.5,2.5 });
	SetCollider({ 150,150 }, Layer::SHEILD);
	info.color = D3DCOLOR_ARGB(150, 144, 215, 236);
	z = 50;
}

void Sheild::Update()
{
	Move();
	Hit();
	Destroy();
}

void Sheild::Move()
{
	position = player->position;
}

void Sheild::Hit()
{
	auto inst = PlaceMeeting({ 0,0 }, Layer::ENEMY_BULLET);

	if (inst != nullptr)
	{
		auto bullet = dynamic_cast<EnemyBullet*>(inst);
		bullet->destroy = true;
	}
}

void Sheild::Destroy()
{
	activeTime -= DXUTGetElapsedTime();
	if (activeTime <= 0)
	{
		player->sheild = nullptr;
		destroy = true;
	}
}

void Sheild::SetSheild(Player* a_player, float a_activeTime)
{
	player = a_player;
	activeTime = a_activeTime;
}
