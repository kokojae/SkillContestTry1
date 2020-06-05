#include "DXUT.h"
#include "Enemy.h"
#include "SkillContestTry1.h"

void Enemy::Init()
{
	SetTexture(L"Resource/Enemy.png", { 105,69 });
	SetCollider({ 105,69 }, Layer::ENEMY);
	z = 9;
}

void Enemy::Update()
{
	Detection();
	Hit();
}

void Enemy::Hit()
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
			destroy = true;
			ItemProduce();
		}
	}
}

void Enemy::Detection()
{
	fireBetTime -= DXUTGetElapsedTime();

	detectionRect = {
		static_cast<LONG>((position - collider.center).x - SCREEN_WIDTH),
		static_cast<LONG>((position - collider.center).y),
		static_cast<LONG>((position - collider.center + collider.size).x),
		static_cast<LONG>((position - collider.center + collider.size).y)
	};

	auto inst = ObjectManager::ColliderCheck(&detectionRect, Layer::PLAYER);
	if (inst != nullptr)
	{
		if (!GameManager::isBombing)
		{
			if (fireBetTime <= 0)
			{
				fireBetTime = betTime;
				ObjectManager::Instantiate<EnemyBullet>(position)->SetBullet({ -1,0 }, 25, 10, 3);
			}
		}
	}
}

void Enemy::IsCamIn()
{
	isCamIn = IntersectRect(&RECT(), GetRect(), Camera::GetCameraRect());
}

void Enemy::ItemProduce()
{
	bool isSuccess = false;

	do
	{
		int which = rand() % 4;

		switch (which)
		{
		case 0:
			ObjectManager::Instantiate<ItemHeal>(position);
			isSuccess = true;
			break;
		case 1:
			if (GameManager::player->level < 5)
			{
				printf("(대충 레벨업 아이템)\n");
				isSuccess = true;
			}
			else
			{
				printf("레벨 5임 ㅅㄱ\n");
			}
			break;
		case 2:
			printf("(대충 쿨 초기화 템)\n");
			isSuccess = true;
			break;
		default:
			printf("아이템 안뜸 ㅅㄱ\n");
			isSuccess = true;
			break;
		}
	} while (!isSuccess);
}
