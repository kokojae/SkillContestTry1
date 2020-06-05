#include "DXUT.h"
#include "RankBoard.h"
#include "SkillContestTry1.h"

void RankBoard::Init()
{
}

void RankBoard::Update()
{
	if (GetAsyncKeyState(VK_RETURN))
	{
		SceneManager::LoadScene(SceneManager::Scene::TITLE);
	}
}

void RankBoard::Render()
{
	float i = 0;
	for (Rank* inst : RankManager::rankingList)
	{
		wchar_t buf[256];
		ZeroMemory(buf, sizeof(buf));
		swprintf(buf, L" : %dÁ¡", inst->score);

		GraphicManager::TextRender(inst->name + buf, { -200,i * 100 - 300 });

		i += 1;
	}
}
