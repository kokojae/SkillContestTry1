#pragma once
#include "GameObject.h"
class RankBoard :
    public GameObject
{
public:
    void Init()override;
    void Update()override;
    void Render()override;
};

