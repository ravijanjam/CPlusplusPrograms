#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std; 

void rangeBasedForLoop(){

	//map<string, vector<int>> mp;
	
	string ss = "Hello";
	//char cc = "Hello";

	for (auto c : ss)
	{
		cout << c; 	
	}

	for (auto m : {0, 1, 2, 3}) cout << m << endl;
	
}
