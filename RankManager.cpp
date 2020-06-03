#include "DXUT.h"
#include "RankManager.h"

std::list<Rank*> RankManager::rankingList = std::list<Rank*>();

bool SortRank(Rank* a, Rank* b)
{
	return a->score > a->score;
}

void RankManager::Release()
{
	std::list<Rank*>::iterator it = rankingList.begin();

	while (it != rankingList.end())
	{
		auto inst = it._Ptr->_Myval;
		delete inst;
		rankingList.erase(it++);
	}
}

void RankManager::AddRank(std::wstring name, int score)
{
	Rank* inst = new Rank;

	rankingList.push_back(inst);
	inst->name = name;
	inst->score = score;
	rankingList.sort(SortRank);
}
