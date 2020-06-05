#pragma once
#include "Enemy.h"
class BossHpBar;

class Boss :
    public Enemy
{
public:
    float patternBetTime;

    BossHpBar* hpBar = nullptr;

    void Init()override;
    void Update()override;
    void Release()override;

    void Attack();
    int Detection();
    void Pattern1();
    void Pattern2();
    void Pattern3();

    void Hit()override;

    void SetHpBar();
};

