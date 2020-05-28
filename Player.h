#pragma once
#include "GameObject.h"
class Player :
    public GameObject
{
public:
    int level;
    float exp;
    float hp;
    float moveSpeed;
    float damage;
    bool isStraight;
    float straightTime;
    float radialTime;
    float fireBetTime;

    void Init()override;
    void Update()override;

    void Move();
    void Fire();
    void Toggle();
};

