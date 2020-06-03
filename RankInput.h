#pragma once
#include "GameObject.h"
#include <iostream>

class RankInput :
	public GameObject
{
public:
	std::wstring name = L"";
	int alphabet = 0;

	void Init()override;
	void Update()override;
	void Render()override;

	void UpDown();

	void SetName();
};

