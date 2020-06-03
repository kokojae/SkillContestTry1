#include "DXUT.h"
#include "RankInput.h"
#include "SkillContestTry1.h"

void RankInput::Init()
{
}

void RankInput::Update()
{
	switch (alphabet)
	{
		case

	default:
		break;
	}
}

void RankInput::Render()
{
	DrawSelf();

	std::wstring buff = L"";

	switch (name.length())
	{
	case 1:
		buff[1] = name[1];
		GraphicManager::TextRender(buff, { -50,0 });
		break;
	case 2:
		buff[1] = name[2];
		GraphicManager::TextRender(buff, { -50,0 });
		break;
	case 3:
		buff[1] = name[3];
		GraphicManager::TextRender(buff, { -50,0 });
		break;
	default:
		break;
	}
}

void RankInput::UpDown()
{
	static bool isPush = false;

	if (GetAsyncKeyState(VK_UP) && !isPush)
	{
		alphabet--;
		if (alphabet < 0)
			alphabet = 27;

		isPush = true;
	}
	else if (!GetAsyncKeyState(VK_UP))
	{
		isPush = false;
	}
}

void RankInput::SetName()
{
}
