#pragma once
#include "Member.h"
class SuperMember : public Member
{
private:
	Member Best;
	int Generation;
public:
	SuperMember();
	SuperMember(Member, int);
	int GetGeneration();
	string GetSuperDNA();
	int GetSuperFitness();

};

