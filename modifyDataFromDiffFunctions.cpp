/* Instructions at the bottom */

#include <iostream>
#include <string>

using namespace std; 

// Initalize a structure whose data will be modified by different functions
struct userData{
	string words[5];
	double nums[5];
};

// Function that adds words to userData
userData addWord(userData &ud){

	// Changing the content here for userData
	ud.words[1] = "addWord";
	ud.nums[1] = 1;

	cout << "from addWord" << "\t"
	     << ud.words[0] << "\t"
	     << ud.words[1] << "\t"
	     << ud.nums[0] << "\t"
	     << ud.nums[1] << "\t"
	     << endl;

	return ud; 
}

// Function that adds nums to userData
userData addNums(userData &ud){
	

	// Changing the content here for userData
	ud.nums[2] = 2 ;
	ud.words[2] = "addnums";

	cout << "from addNums" << "\t"
	     << ud.words[0] << "\t"
	     << ud.words[1] << "\t"
	     << ud.nums[0] << "\t"
	     << ud.nums[1] << "\t"
	     << endl;

	return ud;
}

// main program
int main(){

	userData ud; 
	ud.words[0] = "main";
	ud.nums[0] = 0;
	
	cout << "stuff added from main " << "\t"
	     << ud.words[0] << "\t"
	     << ud.nums[0] << "\t"
	     << endl;

	cout << endl;

	addWord(ud);

	cout << "calling updated userData from main - round 1" << "\n"
	     << ud.words[0] << "\t"
	     << ud.words[1] << "\t"
	     << ud.nums[0] << "\t"
	     << ud.nums[1] << "\t"
	     << endl;


	cout << endl;
	addNums(ud);

	cout << "calling updated userData from main - round 2" << "\n"
	     << ud.words[0] << "\t"
	     << ud.words[1] << "\t"
	     << ud.words[2] << "\t"
	     << ud.nums[0] << "\t"
	     << ud.nums[1] << "\t"
	     << ud.nums[2] << "\t"
	     << endl;
	     
	return 0;
	
}


/*

The purpose of this program is to initate a data structure and update it sequentially 
from different functions. 

To run from the command prompt do : 
1. g++ modifyDataFromDiffFunctions.cpp
2. ./a.out

You should see an output that looks like this

---------------------------------------------------
stuff added from main 	main	0	

from addWord	main	addWord	0	1	
calling updated userData from main - round 1
main	addWord	0	1	

from addNums	main	addWord	0	1	
calling updated userData from main - round 2
main	addWord	addnums	0	1	2	
preon@debian:~/IsingModel/CplusplusPrograms$ ./a.out 
stuff added from main 	main	0	

from addWord	main	addWord	0	1	
calling updated userData from main - round 1
main	addWord	0	1	

from addNums	main	addWord	0	1	
calling updated userData from main - round 2
main	addWord	addnums	0	1	2	

---------------------------------------------------

*/
