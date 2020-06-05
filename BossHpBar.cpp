#include "DXUT.h"
#include "BossHpBar.h"
#include "SkillContestTry1.h"

void BossHpBar::Init()
{
	SetTexture(L"Resource/BossHpBar.png", { 700,50 });
	info.color = D3DCOLOR_XRGB(255, 0, 0);
	z = 90;
	info.camOn = false;
}
