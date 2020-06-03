#pragma once
#include "GameObject.h"
class Text;
class Sheild;

class Player :
    public GameObject
{
public:
    int level;
    float exp;
    float expToNext;
    float maxHp;
    float hp;
    float moveSpeed;
    float straightDamage;
    float radialDamage;
    bool isStraight;
    float straightTime;
    float radialTime;
    float fireBetTime;
    int score;
    Text* UIText;

    Sheild* sheild;
    float sheildTime;
    float bombingTime;
    Text* noticeText;
    float noticeTextTime;

    bool isImmortal;

    void Init()override;
    void Update()override;
    void LateUpdate()override;

    void Move();
    void LevelUp(bool isCheat = false);;

    void Hit();

    void Fire();
    void Toggle();
    void Skill();

    void SetUI();
    void SetShield();
    void SetBFB();

    void LockInCamera();
};

