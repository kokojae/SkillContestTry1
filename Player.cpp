#include "DXUT.h"
#include "Player.h"
#include "SkillContestTry1.h"

void Player::Init()
{
	SetTexture(L"Resource/Player.png", { 105,69 });
	SetCollider({ 105,69 }, Layer::PLAYER);
	z = 10;

	level = 1;
	exp = 0;
	expToNext = 100;
	maxHp = 100;
	hp = maxHp;
	moveSpeed = 10;
	straightDamage = 10;
	radialDamage = 5;
	isStraight = false;
	straightTime = 0.05;
	radialTime = 0.1;
	fireBetTime = 0;

	UIText = ObjectManager::Instantiate<Text>();
	UIText->SetText(L"", { 1,1 }, true);
	UIText->z = 100;

	sheild = nullptr;
	isImmortal = true;

	GameManager::player = this;
}

void Player::Update()
{
	Move();
	Toggle();
	AddForce();
	Fire();
	Skill();
	Hit();
	if (exp >= expToNext)
		LevelUp();
	SetUI();
}

void Player::LateUpdate()
{
	Camera::position.x += 1;
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
		force.y -= force.y / moveSpeed;

	if (GetAsyncKeyState(VK_LEFT))
		if (force.x >= -moveSpeed)
			force.x -= moveSpeed * DXUTGetElapsedTime();
	if (GetAsyncKeyState(VK_RIGHT))
		if (force.x <= moveSpeed)
			force.x += moveSpeed * DXUTGetElapsedTime();
	if (!GetAsyncKeyState(VK_LEFT) && !GetAsyncKeyState(VK_RIGHT))
		force.x -= force.x / moveSpeed;
}

void Player::LevelUp(bool isCheat)
{
	if (level < 5)
	{
		if (!isCheat)
			exp -= expToNext;
		level++;
		expToNext = level * 100;

		maxHp += maxHp * 0.2;
		hp = maxHp;

		straightDamage += straightDamage * 0.2;
		radialDamage += radialDamage * 0.2;

		straightTime -= straightTime * 0.2;
		radialTime -= radialTime * 0.2;
	}
}

void Player::Hit()
{
	auto inst = PlaceMeeting({ 0,0 }, Layer::ENEMY_BULLET);

	if (inst != nullptr)
	{
		auto bullet = dynamic_cast<EnemyBullet*>(inst);
		bullet->destroy = true;

		if (!isImmortal)
		{
			hp -= bullet->damage;
			if (hp <= 0)
				destroy = true;
		}
	}
}

void Player::Fire()
{
	fireBetTime -= DXUTGetElapsedTime();
	if (GetAsyncKeyState('Z'))
	{
		if (isStraight)
		{
			if (fireBetTime <= 0)
			{
				fireBetTime = straightTime;
				ObjectManager::Instantiate<PlayerBullet>(position)->SetBullet({ 1,0 }, 25, straightDamage, 3);
			}
		}
		else
		{
			if (fireBetTime <= 0)
			{
				fireBetTime = radialTime;
				for (int i = 0; i < 5; i++)
				{
					ObjectManager::Instantiate<PlayerBullet>(position)->SetBullet({ 10,static_cast<float>(i - 2) }, 25, radialDamage, 3);
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
		isStraight = !isStraight;
		isPush = true;
	}
	if (!GetAsyncKeyState('X'))
	{
		isPush = false;
	}
}

void Player::Skill()
{
	if (GetAsyncKeyState('C'))
		if (level >= 2)
			SetShield();
	if (GetAsyncKeyState('V'))
		if (level >= 4)
			SetBFB();

}

void Player::SetUI()
{
	wchar_t buffer[256];
	swprintf(buffer, L"Lv.%1d     HP : %3.0f/%3.0f     Exp : %5.0f/%5.0f", level, hp, maxHp, exp, expToNext);
	UIText->text = buffer;
}

void Player::SetShield()
{
	if (sheild == nullptr)
	{
		sheild = ObjectManager::Instantiate<Sheild>(position);
		sheild->SetSheild(this, 3);
	}
}

void Player::SetBFB()
{
	static float t = 0;
	t -= DXUTGetElapsedTime();

	if (t <= 0)
	{
		t = 1;
		ObjectManager::Instantiate<BigFuckBomb>(position);
	}
}
