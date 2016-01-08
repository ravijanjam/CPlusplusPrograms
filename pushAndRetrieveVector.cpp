#include <iostream>
#include <vector>

using namespace std;

int main(){

	vector<double> vv;
	vv.push_back(0.2); 	vv.push_back(0.4); 	vv.push_back(0.6); 
	
	for (int i=0; i<vv.size(); i++) cout << vv.at(i) << ",\t";
	vv.clear();

	for (int i=0; i<vv.size(); i++) cout << vv.at(i) << ",\t";
	
	return 0;
}
