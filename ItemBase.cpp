#include "DXUT.h"
#include "ItemBase.h"
#include "SkillContestTry1.h"

void ItemBase::Update()
{
	Hit();
}

void ItemBase::Hit()
{
	auto inst = PlaceMeeting({ 0,0 }, Layer::PLAYER);
	if (inst != nullptr)
	{
		auto player = dynamic_cast<Player*>(inst);
		Process(player);
		destroy = true;
	}
}
