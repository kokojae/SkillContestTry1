#include "DXUT.h"
#include "ItemHeal.h"
#include "SkillContestTry1.h"

void ItemHeal::Init()
{
	SetTexture(L"", {});
	SetCollider({}, Layer::ITEM);
}

void ItemHeal::Process(Player* player)
{
	player->hp += player->maxHp * 0.2;
	if (player->hp > player->maxHp)
		player->hp = player->maxHp;
}
