#include "DXUT.h"
#include "Title.h"
#include "SkillContestTry1.h"

void Title::Init()
{
	backGround = L"Resource/BackGround.png";
	gameStart = L"Resource/GameStart.png";
	rankBoard = L"Resource/RankBoard.png";

	backGroundSize = { 1920,1080 };
	gameStartSize = { 300,100 };
	rankBoardSize = { 300,100 };
}

void Title::Update()
{	
	SetGameStart();
	if (IsClicked(MouseManager::Key::LEFT))
		SceneManager::LoadScene(SceneManager::Scene::STAGE1);
	SetRankBoard();
	if (IsClicked(MouseManager::Key::LEFT))
		SceneManager::LoadScene(SceneManager::Scene::RANK_BOARD);
}

void Title::Render()
{
	SetBackGround();
	DrawSelf();
	SetGameStart();
	DrawSelf();
	SetRankBoard();
	DrawSelf();
}

void Title::Release()
{
}

void Title::SetBackGround()
{
	SetTexture(backGround, backGroundSize);
	SetCollider(backGroundSize, Layer::DEFAULT);
	position = { 0,0 };
	z = -30;
}

void Title::SetGameStart()
{
	SetTexture(gameStart, gameStartSize);
	SetCollider(gameStartSize, Layer::DEFAULT);
	position = { SCREEN_WIDTH / 2 - collider.center.x - 50,SCREEN_HEIGHT / 2 - collider.center.y - 200 };
	z = -20;
}

void Title::SetRankBoard()
{
	SetTexture(rankBoard, rankBoardSize);
	SetCollider(rankBoardSize, Layer::DEFAULT);
	position = { SCREEN_WIDTH / 2 - collider.center.x - 50,SCREEN_HEIGHT / 2 - collider.center.y - 50 };
	z = -20;
}
