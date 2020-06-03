#pragma once
#include "GameObject.h"
class BigFuckBomb :
    public GameObject
{
public:
    float bombingTime = 3;

    void Init()override;
    void Update()override;
};

