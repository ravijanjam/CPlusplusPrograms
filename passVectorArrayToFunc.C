#include <iostream>
#include <vector>

using namespace std; 

// Reading 2D Array
template<int R, int C>
void read2DArr(int (&arr2D)[R][C]){
	//int arr2D[5][5];
	for (int i=0; i<5; i++){
		for (int j=0; j<5; j++){
			cout << arr2D[i][j] << endl;
		}
	}
}


// Reading 1D Vector 
void readVec(vector<int> *vArr){ cout << vArr->size(); }

// Reading 2D Vector 
void read2DVec(vector<vector<int>> &v2DArr){ cout << v2DArr.size(); }

void passVectorToFunc(){

	const int arr[] = {1, 2, 3, 4 ,5};
	vector<int> vArr(arr, arr + sizeof(arr)/sizeof(int));
	//vector<int> vArr(begin(arr), end(arr));

	// Declaring 2D array and passing random values
	int arr2D[5][5];
	for (int i=0; i<5; i++){
		for (int j=0; j<5; j++){
			arr2D[i][j] = rand()%10;
		}
	}

	
	cout << vArr.at(2) << endl;
	cout << &vArr << endl;

	vector<vector<int>> v2D;
	v2D.push_back(vArr);
	v2D.push_back(vArr);
	v2D.push_back(vArr);
	cout << "2D vector size  " << v2D.size() << endl;

	// Pass 2D vector to function
	read2DVec(v2D);

	// Pass vector to function
	readVec(&vArr);

	// Pass 2D array 
	read2DArr(arr2D);
		 
}
