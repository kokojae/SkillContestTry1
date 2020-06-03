#pragma once
#include "ItemBase.h"

class ItemHeal :
    public ItemBase
{
public:
    void Init()override;

    void Process(Player* player)override;
};

