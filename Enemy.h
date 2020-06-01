#pragma once
#include "GameObject.h"
class Enemy :
    public GameObject
{
public:
    float hp = 100;
    RECT detectionRect;
    float fireBetTime = 0;
    float betTime = 0.1;
    bool isIncrease = false;

    int exp = 100;

    virtual void Init()override;
    virtual void Update()override;

    void Move();

    void Hit();

    void Detection();
};

