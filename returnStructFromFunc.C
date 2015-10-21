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

// Pass a struct to function and return it
tss passNReturnStruct(tss tt){

	cout << "struct from passNReturnStruct Function" << endl;
	cout << tt.name << "\n" << tt.price << endl;

	tt.name = "Vayu";
	
	return tt;
}

void returnStructFromFunc(){
	
	tss p1, p2;
	p1 = returnStruct();

//	t.name = "Bokadia";
//	t.price = 32; 

	cout << p1.name << "\n" << p1.price << endl;
	
	p2 = passNReturnStruct(p1);
	
	cout << "from p2" << "\n"
	     << p2.name << "\n"
	     << p2.price << "\n"
	     << endl;
	

}
