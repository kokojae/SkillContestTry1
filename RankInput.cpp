#include "DXUT.h"
#include "RankInput.h"
#include "SkillContestTry1.h"

void RankInput::Init()
{
}

void RankInput::Update()
{
	UpDown();
	SetName();
}

void RankInput::Render()
{
	//DrawSelf();

	std::wstring buf;

	buf.clear();
	buf.push_back(name[0]);
	GraphicManager::TextRender(buf, { -100,0 });

	buf.clear();
	buf.push_back(name[1]);
	GraphicManager::TextRender(buf, { 0,0 });

	buf.clear();
	buf.push_back(name[2]);
	GraphicManager::TextRender(buf, { 100,0 });
}

void RankInput::UpDown()
{
	static bool isPush = false;

	if (GetAsyncKeyState(VK_UP) && !isPush)
	{
		alphabet--;
		if (alphabet < 1)
			alphabet = 26;
		isPush = true;
	}
	else if (GetAsyncKeyState(VK_DOWN) && !isPush)
	{
		alphabet++;
		if (alphabet > 26)
			alphabet = 1;
		isPush = true;
	}
	else if (!GetAsyncKeyState(VK_UP) && !GetAsyncKeyState(VK_DOWN))
	{
		isPush = false;
	}
}

void RankInput::SetName()
{
	switch (alphabet)
	{
	case 1:
		name[charCount] = 'A';
		break;
	case 2:
		name[charCount] = 'B';
		break;
	case 3:
		name[charCount] = 'C';
		break;
	case 4:
		name[charCount] = 'D';
		break;
	case 5:
		name[charCount] = 'E';
		break;
	case 6:
		name[charCount] = 'F';
		break;
	case 7:
		name[charCount] = 'G';
		break;
	case 8:
		name[charCount] = 'H';
		break;
	case 9:
		name[charCount] = 'I';
		break;
	case 10:
		name[charCount] = 'J';
		break;
	case 11:
		name[charCount] = 'K';
		break;
	case 12:
		name[charCount] = 'L';
		break;
	case 13:
		name[charCount] = 'M';
		break;
	case 14:
		name[charCount] = 'N';
		break;
	case 15:
		name[charCount] = 'O';
		break;
	case 16:
		name[charCount] = 'P';
		break;
	case 17:
		name[charCount] = 'Q';
		break;
	case 18:
		name[charCount] = 'R';
		break;
	case 19:
		name[charCount] = 'S';
		break;
	case 20:
		name[charCount] = 'T';
		break;
	case 21:
		name[charCount] = 'U';
		break;
	case 22:
		name[charCount] = 'V';
		break;
	case 23:
		name[charCount] = 'W';
		break;
	case 24:
		name[charCount] = 'X';
		break;
	case 25:
		name[charCount] = 'Y';
		break;
	case 26:
		name[charCount] = 'Z';
		break;
	default:
		break;
	}

	static bool isReturn = false;
	if (GetAsyncKeyState(VK_RETURN) && !isReturn)
	{
		alphabet = 1;

		charCount++;
		if (charCount > 2)
		{
			RankManager::AddRank(name, 10);
			SceneManager::LoadScene(SceneManager::Scene::TITLE);
		}
		isReturn = true;
	}
	else if (!GetAsyncKeyState(VK_RETURN))
	{
		isReturn = false;
	}
}
