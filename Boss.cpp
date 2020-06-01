#include "DXUT.h"
#include "Boss.h"
#include "SkillContestTry1.h"

void Boss::Init()
{
	SetTexture(L"Resource/Boss.png", { 495,240 });
	SetCollider({ 495,240 }, Layer::ENEMY);

	hpBar = ObjectManager::Instantiate<BossHpBar>({ SCREEN_WIDTH / 2, 100 });
	hpBar->boss = this;
}

void Boss::Update()
{
	Attack();
	Hit();
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
	printf("Pattern1\n");
}

void Boss::Pattern2()
{
	printf("Pattern2\n");
}

void Boss::Pattern3()
{
	printf("Pattern3\n");
}
