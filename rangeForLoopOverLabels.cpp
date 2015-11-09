/* Scroll to the bottom for more information */

#include <iostream>
#include <string>
#include <map>

using namespace std; 

void rangeForLoopOverLabels(){

string ll[] = {"Monkey", "Donkey", "Cat", "Dog"};
map<string, vector<int>> mp;

const int ii[] = {2, 9, 5, 2, 1, 9, 8, 6, 7, 0};

vector<int> vv(begin(ii), end(ii));


// Passing values per label
for (auto ss : ll) { //for-a1

	cout << ss << endl;
	mp[ss] = vv;

}// closing for-a1

// Get the numbers per label out
for (auto ss : ll){ //for-a2
	int ts = mp[ss].size();

	cout << "stuff for the label : " << ss << endl;
	for(int j=0; j < ts; j++) cout << mp[ss].at(j) << "\t";
	cout << endl;

	
	cout << "using the iterator : " << ss << endl;
	for (vector<int>::iterator it = mp[ss].begin(); it != mp[ss].end(); ++it ) cout << *it << "\t";

}// closing for-a2


} // closing main


/*

	Creates labels, maps labels to vectors, gets out the values using iteratoras well as the vanilla method of reading numbers

*/
