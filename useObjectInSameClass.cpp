#include <iostream>

using namespace std;


class Animal{

	public:
		int move(){ cout << "from the method move" << endl; return 5;}
		void climb(){ Animal::move();}
};

int main(){

	Animal a;	
	a.move();
	a.climb();
	return 0;
}
