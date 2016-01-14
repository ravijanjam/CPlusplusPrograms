#include <iostream>

using namespace std;

struct myData{

	string h;
};

class Animal{

	public:
		void move(){cout << "I can walk";};
		void passData( myData mD );
};

void Animal::passData(myData mD){

	cout << "Data from strcut myData " << mD.h <<  endl;

}

int main(){

	Animal a;
	myData dat;
	dat.h = "Whats up";
	a.passData(dat);
	return 0;
}


