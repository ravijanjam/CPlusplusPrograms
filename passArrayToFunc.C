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
