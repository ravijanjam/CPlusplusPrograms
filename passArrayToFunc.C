#include <iostream>


using namespace std; 

// Function takes the array from  the main
// and just reads it
void readArr(int arr[]){
	
	for (int i=0; i < 5; i++) cout << arr[i] << "\t"; 
}

void passArrayToFunc(){

	int arr[] = {1, 2, 3, 4,5};

	// Pass an array declared
	readArr(arr);

}

/*

To run the program at the command prompt to
1. g++ passArrayToFunc.C
2. ./a.out

Passes a 1D array from main to a function and 
reads the array there. 

*/
