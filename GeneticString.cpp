#include <Windows.h>
#include <iostream>
#include <time.h>
#include <string>
#include "Member.h"
#include "Population.h"
using namespace std;

int main() {
    
	int PopulationSize , MutationRate;
	string Goal;
	srand(time(NULL));


	cout << "Enter population: (500 - 50000)\t";  cin >> PopulationSize; //Moze i manje ali je dosta sporo
	cout << "Enter the probability of a mutation (0 - 100)\t"; cin >> MutationRate;
	cin.ignore();
	cout << "Enter the goal: "; getline(cin, Goal);
	Population Test(MutationRate, PopulationSize, Goal);
	Test.CheckSeq();
	
}
