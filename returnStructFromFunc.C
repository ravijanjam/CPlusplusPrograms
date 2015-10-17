#include <iostream>
#include <string>

using namespace std;

struct tss{
	string name; 
	double price;

}; 

tss returnStruct(){

	cout << "Hello from Struct" << endl;
	
	tss t; 
	t.name = "Bokadia";
	t.price = 32; 

	return t; 
}


void returnStructFromFunc(){
	
	tss p;
	p = returnStruct();

//	t.name = "Bokadia";
//	t.price = 32; 

	cout << p.name << "\n" << p.price << endl;
	
	

}
