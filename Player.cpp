#include "DXUT.h"
#include "Player.h"
#include "SkillContestTry1.h"

void Player::Init()
{
	SetTexture(L"Resource/Player.png", { 105,69 });

	level = 1;
	exp = 0;
	hp = 100;
	moveSpeed = 10;
	damage = 10;
	isStraight = true;
	straightTime = 0.05;
	radialTime = 0.1;
	fireBetTime = straightTime;
}

void Player::Update()
{
	Move();
	Toggle();
	Fire();
	AddForce();
	printf("x : %06.6f, y : %06.6f\n", position.x, position.y);
}

void Player::Move()
{
	if (GetAsyncKeyState(VK_UP))
		if (force.y >= -moveSpeed)
			force.y -= moveSpeed * DXUTGetElapsedTime();
	if (GetAsyncKeyState(VK_DOWN))
		if (force.y <= moveSpeed)
			force.y += moveSpeed * DXUTGetElapsedTime();
	if (!GetAsyncKeyState(VK_UP) && !GetAsyncKeyState(VK_DOWN))
		force.y -= force.y / 20;

	if (GetAsyncKeyState(VK_LEFT))
		if (force.x >= -moveSpeed)
			force.x -= moveSpeed * DXUTGetElapsedTime();
	if (GetAsyncKeyState(VK_RIGHT))
		if (force.x <= moveSpeed)
			force.x += moveSpeed * DXUTGetElapsedTime();
	if (!GetAsyncKeyState(VK_LEFT) && !GetAsyncKeyState(VK_RIGHT))
		force.x -= force.x / 20;
}

void Player::Fire()
{
	fireBetTime -= DXUTGetElapsedTime();
	if (GetAsyncKeyState('Z'))
	{
		printf("Fire\n");
		if (isStraight)
		{
			if (fireBetTime <= 0)
			{
				fireBetTime = straightTime;
				ObjectManager::Instantiate<PlayerBullet>(position)->SetBullet({ 1,0 }, 25, 3);
			}
		}
		else
		{
			if (fireBetTime <= 0)
			{
				fireBetTime = radialTime;
				for (int i = 0; i < 5; i++)
				{
					ObjectManager::Instantiate<PlayerBullet>(position)->SetBullet({ 10,static_cast<float>(i - 2) }, 25, 3);
				}
			}
		}
	}
}

void Player::Toggle()
{
	static bool isPush = false;

	if (GetAsyncKeyState('X') && !isPush)
	{
		printf("Toggle\n");
		isStraight = !isStraight;
		isPush = true;
	}
	if (!GetAsyncKeyState('X'))
	{
		isPush = false;
	}
}
