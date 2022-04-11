#include "SuperMember.h"
SuperMember::SuperMember() {
	Best = *new Member();
	Generation = 0;
}
SuperMember::SuperMember(Member Best, int Generation) {
	this->Best = Best;
	this->Generation = Generation;
}
int SuperMember::GetGeneration() {
	return Generation;
}
string SuperMember::GetSuperDNA() {
	return Best.GetDNA();

}
int SuperMember::GetSuperFitness() {
	return Best.GetFitness();
}