#include <iostream>
#include <vector>

using namespace std;

int main(){

	int i;

	int dbContacted[] = {0};
	int dbImpossible[] = {0};
	

	// Initialize an array
	int dbAllInt[] = { 2726, 8719, 2698, 2665, 2657, 2592, 2586, 2508, 2369, 2363, 2317, 2315, 2279, 2196, 1930, 1734, 194, 273, 434, 849, 1127, 1409, 1490, 620, 640, 1284, 2773, 2738, 2731, 2684, 2697,2668, 2666, 2413, 2174, 680, 744, 863, 1058, 1368, 138, 681, 2774, 2777, 434, 1542, 198, 1641, 633, 1692, 710, 142, 1409, 1186, 900, 849, 660, 538, 456, 260, 268, 194, 148, 153,47, 1734, 1903, 1920, 1930, 2008, 2279, 2315, 2319, 2549, 2508, 2584, 2592, 2657, 2665, 8719, 2739, 2744, 2757, 2760, 2769, 2792, 2794, 2803, 2809, 2816, 2818, 2820, 2827, 2825 };

	// Pass the array into a vector for easy access
	vector<int> dbAll(dbAllInt, dbAllInt + sizeof(dbAllInt)/sizeof(int));

	cout << "Verify the existence and in which data base : " << endl;
		
	//vector<int>::iterator it = dbAll.begin();

	do {
	
		cout << "Please enter an integer" << endl;
		cin >> i ; 
		
		for ( vector<int>::iterator it = dbAll.begin(); it != dbAll.end(); ++it ){
			int match = *it; 
			if ( i == match ) cout << "The number : " << *it << "already exists in " << *it << endl;
		}

		//for (int k=0; k<dbAll.size(); k++) cout << dbAll.size()  << endl;
	
	//++it;
		cout << "If you want to quit, please hit 0" << endl;

	} while ( i!=0 );

	return 0;

}

/*
	Purpose : To verify if an ID has already been contacted and in which category is it, already contacted or not any more possible. 
	Has three databases. dbContacted has the set of numbers where the ids are already contacted. 
	dbImpossible : not possible choices. 
	dbAll has every contacted ID. 
		

	User gives an ID during runtime, which is verified against the existing database. 
*/
