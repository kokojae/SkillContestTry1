#pragma once
class Player;

class GameManager
{
public:
	static Player* player;
	static bool isBombing;

	static void Init();
	static void Update();
	static void LateUpdate();
	static void Render();
	static void Release();

	static void CheatKey();
};

