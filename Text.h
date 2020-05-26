#pragma once
#include "GameObject.h"
class Text :
    public GameObject
{
public:
    std::wstring text = L"";
    D3DXVECTOR2 scale = { 1,1 };
    bool isUI = false;

    void Render();

    void SetText(std::wstring a_text, D3DXVECTOR2 a_scale, bool a_isUI = false);
};

