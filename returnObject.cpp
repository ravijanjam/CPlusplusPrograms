/* Scroll to the bottom for more information */

// C++ Headers
#include <iostream>
#include <string>

using namespace std; 

struct userData{

	string name;
	int nShirts, nPants;

};

class Fabric{

	public:
		userData uD;
		double shirt, pant, hands, legs, shoulder;

		Fabric(){
			cout << "Please enter the name of the person" << endl;
			cin >> uD.name ;

			cout << "Please enter the number of shirts:  " << endl;
			cin >> uD.nShirts ;

			cout << "Please enter the number of pants :  " << endl;
			cin >> uD.nPants ;

		} // Constructor 

		bool displayData();
		bool amendData();

};

bool Fabric::amendData(){
	
	cout << "Edit the name of the person : " << endl;
	cin >> uD.name;
}

bool Fabric::displayData(){

	cout << "The name of the person is : " << uD.name << "\n"
	     << "Number of shirts asked for : " << uD.nShirts << "\n"
	     << "Number of pants asked for : " << uD.nPants << "\n";
	
	return 0;
}

struct classData{

	Fabric fab; 
};


Fabric& returnObject(Fabric &fab){

	cout << "==============================" << endl;
	cout << "From the function returnObject " << endl;
	fab.displayData();

	return fab;
}

int main(){

	Fabric fabr;
	fabr.displayData();

	fabr.amendData();

	cout << "\n The edited data is as follows " << endl;
	fabr.displayData();

	returnObject(fabr);

	return 0;

} // Closing main

/*
	This program take creates a class,takes a struct inside it, has a funciton inside which the data passed into the class is edit.:w

*/
