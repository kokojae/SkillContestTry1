#include "DXUT.h"
#include "BigFuckBomb.h"
#include "SkillContestTry1.h"

void BigFuckBomb::Init()
{
	ObjectManager::Instantiate<BombBullet>(position)->SetBullet({ 1,0 }, 25, 1, 3);
	ObjectManager::Instantiate<BombBullet>(position)->SetBullet({ 1,1 }, 25, 1, 3);
	ObjectManager::Instantiate<BombBullet>(position)->SetBullet({ 0,1 }, 25, 1, 3);
	ObjectManager::Instantiate<BombBullet>(position)->SetBullet({ -1,1 }, 25, 1, 3);
	ObjectManager::Instantiate<BombBullet>(position)->SetBullet({ -1,0 }, 25, 1, 3);
	ObjectManager::Instantiate<BombBullet>(position)->SetBullet({ -1,-1 }, 25, 1, 3);
	ObjectManager::Instantiate<BombBullet>(position)->SetBullet({ 0,-1 }, 25, 1, 3);
	ObjectManager::Instantiate<BombBullet>(position)->SetBullet({ 1,-1 }, 25, 1, 3);

	GameManager::isBombing = true;

	printf("BombingTime is Start\n");
}

void BigFuckBomb::Update()
{
	bombingTime -= DXUTGetElapsedTime();

	if (bombingTime <= 0)
	{
		GameManager::isBombing = false;
		destroy = true;
		printf("BombingTime is End\n");
	}
}
