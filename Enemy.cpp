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
	Move();
	AddForce();
	Detection();
	Hit();
}

void Enemy::Move()
{
	if (isIncrease)
	{
		force.y += 0.1;
		if (force.y >= 5)
			isIncrease = !isIncrease;
	}
	else
	{
		force.y -= 0.1;
		if (force.y <= -5)
			isIncrease = !isIncrease;
	}

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
