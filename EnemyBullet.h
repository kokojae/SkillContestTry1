#pragma once
#include "GameObject.h"
class EnemyBullet :
    public GameObject
{
public:
    float speed;
    float destroyTime;
    float damage;

    void Init()override;
    void Update()override;

    void Destroy();

    void SetBullet(D3DXVECTOR2 direction, float a_speed, float a_damage, float a_destroyTime);
};

