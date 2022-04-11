#include "Population.h"
#include "Member.h"
#include "Template.h"
#include "SuperMember.h"
#include<algorithm>
#include <fstream>
#include<Windows.h>


Population::Population() {
	Members = vector<Member>(0);
	Goal = '0';
	PopulationSize = 0;
	Mutation = 0;
	Gen = 0;

}
Population::Population(int Mutation,int PopulationSize, string Goal) {
	fstream File;
	File.open("Generations.txt", ios::out);
	File << "Inicijalna populacija velicine "<< PopulationSize <<": \n\n";
	this->Mutation = Mutation;
	this->PopulationSize = PopulationSize;
	this->Goal = Goal;
	Gen = 0;
	Members = vector<Member>(PopulationSize);
	for (int i = 0; i < this->PopulationSize; i++) {
		Members.at(i).FillString(this->Goal);
		File << Members.at(i).Fitness << " : " << Members.at(i).DNA << endl;
	}
	File << "\n####################################################################################\n";
		
	File.close();


}
Member Population::Mutate() {
	fstream File;
	File.open("Generations.txt", ios::out | ios::app);
	
	sort(Members.begin(), Members.end(), [](Member const& a, Member& b) ->bool {return a.Fitness > b.Fitness; }); 

	vector<Member> Parents(Members.size() / 10); 

	File << "\nRoditelji nove generacije (najbolji hromozomi generacije "<< Gen << "): \n\n";

	for (int i = 0; i < Members.size() / 10; i++) {
		Parents.at(i) =   Members.at(i);
		File << Parents.at(i).Fitness << " : " << Parents.at(i).DNA << endl;
	}


	File << "\nNova generacija napravljena ukrstaljem i mutacijom: \n\n";
	for (int i = Members.size() / 10; i < Members.size(); i++) {
		for (int j = 0; j < Members.at(i).GetSize(); j++) {
			int Temp = rand() % Parents.size();
			Members.at(i).operator()(Parents.at(Temp), j); 
			
			if (rand() % 1000 < Mutation) { Members.at(i) + j; }
			Evaluate(i);
			//Ovde evaluacija nije neophodna
			//Pomaže nam da vidimo u txt fajlu fitness vrednosti
			//Možemo da primetimo koji hromozomi su postali roditelji slede?e generacije
		}
		
		File << Members.at(i).Fitness << " : " << Members.at(i).DNA << endl;
		
	}
	File << "\n####################################################################################\n";
	File.close();
	return Parents.at(0);
}
void Population::Evaluate(int i) {
	Members.at(i).SetFitness(0);
	for (int j = 0; j < Members.at(i).GetSize(); j++) {
		if (Members.at(i).DNA.at(j) == Goal.at(j))
			Members.at(i).SetFitness(Members.at(i).GetFitness() + 10);
	}
}

void Population::CheckSeq() {
	bool Seq = false;
	Member Best;
	int Break;
	SuperMember BestToPrint;
	

	cout << "Enter max generation (0 if you dont want the limit): "; cin >> Break;
	Stek<SuperMember> Bests((Break == 0 || Break <= 50) ? Break : 50);


	while (!Seq) {
		Gen++;
		for (int i = 0; i < Members.size(); i++) {
			Evaluate(i);
			if (Members.at(i).GetFitness() == Members.at(i).GetSize() * 10) {
				Seq = true;
			}
		}
		Best = Mutate();
		if (Break != 0) {
			if (Gen == Break) {
				cout << "\nGeneracija: \t" << Gen << " Najveci Fitness : \t" 
					<< Best.GetFitness() << " String : \t" 
					<< Best.GetDNA().c_str() << endl;
				cout << "Prekid zbog dostignutog maksimalnog broja generacija!\n\n";
				exit(0);
			}
				

		}

		cout << "\Generation: \t" << Gen << " Best Fitness : \t" << Best.GetFitness() << " String : \t" << Best.GetDNA().c_str() << endl;
		Sleep(1000);
		BestToPrint = *new SuperMember(Best, Gen);
		if (!(Bests.Full()))
			Bests.Put(BestToPrint);
		else {
			cout << "Stek sa najboljim hromozomima je pun!!!\n\n";
			break;
		}
			
	
	}
	fstream GenBest;
	remove("Best.txt");
	GenBest.open("Best.txt", ios::out | ios::app);
	GenBest << "Best chromosome: \n\n";
	while (!(Bests.Empty())) {
		Bests.Get(BestToPrint);
		GenBest << "Generation: " << BestToPrint.GetGeneration() 
			<< "\tFitness: " << BestToPrint.GetSuperFitness() 
			<< " \t " << BestToPrint.GetSuperDNA() <<   "\n";
		

	}
	GenBest.close();
	cout << "String found in generation: \t " << Gen << "\nString: \t" << Best.GetDNA().c_str() << endl;
	Sleep(2000);


	
}