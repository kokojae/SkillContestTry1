#include "DXUT.h"
#include "Boss.h"
#include "SkillContestTry1.h"

void Boss::Init()
{
	SetTexture(L"Resource/Boss.png", { 495,240 });
	SetCollider({ 495,240 }, Layer::ENEMY);

	hp = maxHp = 10000;
}

void Boss::Update()
{
	IsCamIn();
	if (isCamIn)
	{
		Attack();
		Hit();
		SetHpBar();
	}
}

void Boss::Release()
{
	if (hpBar != nullptr)
	{
		hpBar->destroy = true;
		hpBar = nullptr;
	}
}

void Boss::Attack()
{
	int Rs = Boss::Detection();
	switch (Rs)
	{
	case 1:
		Pattern1();
		break;
	case 2:
		Pattern2();
		break;
	case 3:
		Pattern3();
		break;
	default:
		break;
	}
}

int Boss::Detection()
{
	patternBetTime -= DXUTGetElapsedTime();

	if (patternBetTime <= 0)
	{
		patternBetTime = 3;

		for (int i = 1; i <= 3; i++)
		{
			RECT detectionRect = {
				static_cast<LONG>((position - collider.center).x - (collider.size.x * i)),
				static_cast<LONG>((position - collider.center).y - SCREEN_HEIGHT),
				static_cast<LONG>((position - collider.center + collider.size).x - (collider.size.x * i)),
				static_cast<LONG>((position - collider.center + collider.size).y + SCREEN_HEIGHT)
			};

			if (ObjectManager::ColliderCheck(&detectionRect, Layer::PLAYER))
				return i;
		}
	}
	return 0;
}

void Boss::Pattern1()
{
	//printf("Pattern1\n");
}

void Boss::Pattern2()
{
	//printf("Pattern2\n");
}

void Boss::Pattern3()
{
	//printf("Pattern3\n");
}

void Boss::Hit()
{
	auto inst = PlaceMeeting({ 0,0 }, Layer::PLAYER_BULLET);

	if (inst != nullptr)
	{
		auto bullet = dynamic_cast<PlayerBullet*>(inst);
		hp -= bullet->damage;
		bullet->destroy = true;

		if (hp <= 0)
		{
			GameManager::player->exp += exp;
			GameManager::player->hp = GameManager::player->maxHp;
			destroy = true;
		}
	}
}

void Boss::SetHpBar()
{
	if (hpBar == nullptr)
	{
		if (isCamIn)
		{
			hpBar = ObjectManager::Instantiate<BossHpBar>({ SCREEN_WIDTH / 2,250 });
		}
	}
	if (hpBar != nullptr)
	{
		float sca = hp / maxHp;
		if (sca <= 0)
			sca = 0;
		hpBar->info.scale.x = sca;
	}
}
