#pragma once
#include "GameObject.h"
class Title :
    public GameObject
{
public:
    std::wstring backGround;
    std::wstring gameStart;
    std::wstring rankBoard;
    D3DXVECTOR2 backGroundSize;
    D3DXVECTOR2 gameStartSize;
    D3DXVECTOR2 rankBoardSize;

    void Init()override;
    void Update()override;
    void Render()override;
    void Release()override;

    void SetBackGround();
    void SetGameStart();
    void SetRankBoard();
};

