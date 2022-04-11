#include "Member.h"
#include <time.h>
#include<vector>

Member::Member() {
	DNA = "0";
	Fitness = 0;
}
Member::Member(string Goal) {
	srand(time(NULL));
	Fitness = 0;
	
	
}
void Member::FillString(string Goal) {
	DNA.resize(Goal.size());

		for (int j = 0; j < DNA.size(); j++) { 
			DNA.at(j) = (unsigned char)rand() % 96 + 32;
		}
}

void Member::operator()(Member Par, int i) {	
	this->GetDNA().at(i) = Par.GetDNA().at(i);
}
void Member::operator+(int i) {
	this->GetDNA().at(i) = (unsigned char)(rand() % 96 + 32);
}

void Member::SetFitness(int F) {
	Fitness = F;
}
int Member::GetFitness() {
	return Fitness;
}
int Member::GetSize() {
	return DNA.size();
}
string& Member::GetDNA() {
	return DNA;
}