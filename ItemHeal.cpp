#include "DXUT.h"
#include "ItemHeal.h"
#include "SkillContestTry1.h"

void ItemHeal::Init()
{
	SetTexture(L"Resource/HealItem.png", { 256,256 });
	SetCollider({ 256,256 }, Layer::ITEM);
}

void ItemHeal::Process(Player* player)
{
	player->hp += player->maxHp * 0.2;
	if (player->hp > player->maxHp)
		player->hp = player->maxHp;
}
