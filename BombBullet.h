#pragma once
#include "GameObject.h"
class BombBullet :
	public GameObject
{
public:
	float speed;
	float destroyTime;
	float damage;
	float t = 0;
	float sca = 1;

	void Init()override;
	void Update()override;

	void Move();
	void Hit();
	void Destroy();

	void SetBullet(D3DXVECTOR2 direction, float a_speed, float a_damage, float a_destroyTime);
};

