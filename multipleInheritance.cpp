#include <iostream>

using namespace std;

class Animal{

	public:
		int eyes, legs;
		bool move(){ cout << "Test method for move" << endl; return 1; }
		
};

class Vehicle{

	public:
		void move(){ cout << "From Vehicle class, I have wheels to move" << endl; }
	
};

class Reptile: public Animal, public Vehicle{

	public:
		void move(){ cout <<"From Reptile inheriting animal and vehicle" << endl;}
		void legs(){ cout << "I do have legs and fins" << endl; }
		void bodyParts(){
			cout << "Reptile has number of eyes" << "\t"
			     << eyes;
		}
};

int main(){

	Animal *a = new Animal();
	Reptile *r = new Reptile();
	r->move();
	r->legs();

	r->eyes = 2;
	r->bodyParts();

	return 0;
		
}
