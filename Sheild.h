#pragma once
#include "GameObject.h"
class Player;

class Sheild :
    public GameObject
{
public:
    float activeTime;
    Player* player;

    void Init()override;
    void Update()override;

    void Move();

    void Hit();

    void Destroy();

    void SetSheild(Player* a_player, float a_activeTime);
};

