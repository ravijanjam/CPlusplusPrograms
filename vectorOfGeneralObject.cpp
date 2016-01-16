#include <iostream>
#include <vector>

using namespace std;

class Animal{

	public:
		Animal(){};
		void move(int i){cout << "I have " << i << " objects" << endl;}
};

int main(){

	Animal a;
	vector<Animal> listOfAnimals;

	for (int i=0; i<5; i++) {
		listOfAnimals.push_back(a);
	}
	

	vector<Animal>::iterator it;
	int i=0;
	for ( it = listOfAnimals.begin(); it != listOfAnimals.end(); ++it ) 
	listOfAnimals.at(0).move(i++);
}

/* 
 *
 * Takes an object of Animal and returns  
 */
