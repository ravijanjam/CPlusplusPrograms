#include <iostream>
#include <vector>

using namespace std; 

struct dat{

	vector<int> vv;
	map<string,vector<int>> mp;
}sD;

void test1(){

//	vector<int> vv; 
	cout << "Filling sequence " << endl;
	for (int i=0; i< 5; i++) {sD.vv.push_back(i); cout << i;}
	cout << endl;

	cout << "Retrieving sequence " << endl;
	for (int i=0; i< 5; i++) cout << sD.vv.at(i) ;
	cout << endl;
}

/*

Passing vector and retrieving values from struct
	
*/
