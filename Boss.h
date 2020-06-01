#pragma once
#include "Enemy.h"
class BossHpBar;

class Boss :
    public Enemy
{
public:
    float patternBetTime;

    float hp = 1000;
    float maxHp = 1000;
    BossHpBar* hpBar;

    void Init()override;
    void Update()override;

    void Attack();
    int Detection();
    void Pattern1();
    void Pattern2();
    void Pattern3();
};

