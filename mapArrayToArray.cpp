/* Scroll down for more information */

#include <iostream>
#include <map>

using namespace std; 

int main(){

	// Initiate the map, for array to array
	map<int*, int*> arr2arr;

	int aa[] = {0, 1, 2, 5, 9};
	int bb[] = {10, 15, 22, 98};

	arr2arr[aa] = bb;

	// loop over all the values in array bb
	for (int i=0; i < 4; i++ )cout << arr2arr[aa][i] << ",";
	
	return 0;
}

/*

	This kind of mapping would be useful where an entire collection of 
	objects should be associated with another collection, but one at a time. 
*/
