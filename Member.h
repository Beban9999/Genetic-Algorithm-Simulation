#pragma once
#include<iostream>
using namespace std;

class Member {
private:
	string DNA;
	int Fitness;
public:
	Member();
	Member(string);
	void FillString(string);
	void SetFitness(int);
	string& GetDNA();
	int GetFitness();
	int GetSize();
	void operator()(Member, int);
	void operator+(int i);
	
	friend class Population;

};