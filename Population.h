#pragma once
#include "Member.h"
#include <iostream>
#include<vector>
#include<fstream>
using namespace std;

class Population
{
private:
	string Goal;
	vector<Member> Members;
	int PopulationSize;
	int Mutation;
	int Gen;
public:
	Population();
	Population(int, int, string);
	void CheckSeq();
	void Evaluate(int);
	Member Mutate();
};


