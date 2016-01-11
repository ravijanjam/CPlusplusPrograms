#include <iostream>

using namespace std;


class Movement{

	public:
	Movement(){cout << "Name of the class is Movement" << endl;}
	int degreesOfFreedom(int a){ return a;}
	~Movement(){cout << "Bye bye" << endl; Movement::degreesOfFreedom(4);}
};

int main(){

	Movement *m = new Movement();
	m->degreesOfFreedom(9);
	delete m;
	
}
