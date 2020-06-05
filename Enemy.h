#pragma once
#include "GameObject.h"
class Enemy :
    public GameObject
{
public:
    float hp = 100;
    float maxHp = 100;
    RECT detectionRect;
    float fireBetTime = 0;
    float betTime = 0.1;


    int exp = 100;

    bool isCamIn = false;

    virtual void Init()override;
    virtual void Update()override;

    virtual void Hit();

    void Detection();

    void IsCamIn();

    void ItemProduce();
};

