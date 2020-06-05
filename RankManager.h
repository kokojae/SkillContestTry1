#pragma once
#include <iostream>
#include <list>

class Rank
{
public:
	std::wstring name;
	int score;
};

class RankManager
{
public:
	static std::list<Rank*> rankingList;

	static void Release();

	static void AddRank(std::wstring name, int score);
};

bool SortRank(const Rank* a, const Rank* b);

