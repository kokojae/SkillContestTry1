#include "DXUT.h"
#include "BigFuckBomb.h"
#include "SkillContestTry1.h"

void BigFuckBomb::Init()
{
	ObjectManager::Instantiate<BombBullet>({ position.x + 20,position.y + 0 })->SetBullet({ 0,0 }, 25, 1, 3);
	ObjectManager::Instantiate<BombBullet>({ position.x + 20,position.y + 20 })->SetBullet({ 0,0 }, 25, 1, 3);
	ObjectManager::Instantiate<BombBullet>({ position.x + 0,position.y + 20 })->SetBullet({ 0,0 }, 25, 1, 3);
	ObjectManager::Instantiate<BombBullet>({ position.x - 20,position.y + 20 })->SetBullet({ 0,0 }, 25, 1, 3);
	ObjectManager::Instantiate<BombBullet>({ position.x - 20,position.y + 0 })->SetBullet({ 0,0 }, 25, 1, 3);
	ObjectManager::Instantiate<BombBullet>({ position.x - 20,position.y - 20 })->SetBullet({ 0,0 }, 25, 1, 3);
	ObjectManager::Instantiate<BombBullet>({ position.x + 0,position.y - 20 })->SetBullet({ 0,0 }, 25, 1, 3);
	ObjectManager::Instantiate<BombBullet>({ position.x + 20,position.y - 20 })->SetBullet({ 0,0 }, 25, 1, 3);
}

void BigFuckBomb::Update()
{

}
