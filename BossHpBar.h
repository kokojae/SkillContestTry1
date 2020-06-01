#pragma once
#include "GameObject.h"
class Boss;

class BossHpBar :
    public GameObject
{
public:
    Boss* boss = nullptr;

    void Init()override;
    void Update()override;
};

