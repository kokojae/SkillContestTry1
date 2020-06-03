#pragma once
#include "GameObject.h"
class Player;

class ItemBase :
    public GameObject
{
public:
    virtual void Update()override;

    virtual void Hit();

    virtual void Process(Player* player) = 0;
};

