#include <iostream>

using namespace std; 

void modifyArray(int *arr, int &size){
	
	// calling from modifyArray function	
	cout << "reading array for values declared in main" << endl;
	for (int i=0; i < size; i++){
		cout << arr[i] << ",";
	}

	// wiping off contents of the array
	for (int i=0; i < size; i++) arr[i] = 0; 
	
} // closing modifyArray

int main(){

	int arr[] = {1, 2, 5, 9, 8, 3, 2};
	int size = 7;
	modifyArray(arr, size);

	// read contents of array from main
	cout << "\nreading array from main" << endl;
	for (int i=0; i<size; i++)cout <<  arr[i] << ".";

	return 0;
	
}
