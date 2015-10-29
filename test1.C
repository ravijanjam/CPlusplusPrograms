#include <iostream>
#include <vector>

using namespace std; 

struct dat{

	vector<int> vv;
	map<char ,double> mp;
}sD;

void test1(){


	string a2z = "ABCDEFGHIJKLMNOPQRXYZA";

	vector<char> vss;

	double i=0; 	
	for (char c : a2z) 
	{ 
		vss.push_back(c);
		cout << "from inside vector: " << vss.at(i) << endl;
		sD.mp[c] = i++;
		cout << c << endl;
	}

	for( int i=0; i <= vss.size() ; i++ ){

		string pp;
		pp += vss.at(i);
		pp += vss.at(i+1);
		cout << "strings together" << pp << endl;

	}
	
	for (int i=0, j=0; i < 10 && j<10; i++, j++) cout << i << "," << j << endl;
	cout << "Filling sequence " << endl;
	for (int i=0; i< 5; i++) {sD.vv.push_back(i); cout << i;}
	cout << endl;

	cout << "Retrieving sequence " << endl;
	for (int i=0; i< 5; i++) cout << sD.vv.at(i) ;
	cout << endl;

	map<string, string> nm;
	nm["name"] = "Hen";
	nm["type"] = "Bird";
}

/*

Passing vector and retrieving values from struct
	
*/
