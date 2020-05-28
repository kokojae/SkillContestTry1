#pragma once
#include "GameObject.h"
class PlayerBullet :
    public GameObject
{
public:
    float speed;
    float destroyTime;

    void Init()override;
    void Update()override;

    void Destroy();

    void SetBullet(D3DXVECTOR2 direction, float a_speed, float a_destroyTime);
};

