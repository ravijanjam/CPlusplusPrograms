/* Scroll to the bottom for information */

#include <iostream>
#include <fstream>

using namespace std;

void cat(ofstream &myFile){

	cout << "Meow, Meow ! Dude, I am a cat" << endl;
	myFile << "Meow, Meow ! Dude, I am a cat" << endl;
}

void dog(ofstream &myFile){

	cout << "Bow, Wow ! Dude, I am a dog" << endl;
	myFile << "Bow, Wow ! Dude, I am a dog" << endl;
}

void cow(ofstream &myFile){

	cout << "Moo, moo ! Dude, I am a cow" << endl;
	myFile << "Moo, moo ! Dude, I am a cow" << endl;
}

int main(){

	ofstream myFile;
	myFile.open("writeFromDiffFuncs.txt");
	cat(myFile); dog(myFile); cow(myFile);
	myFile.close();
	
	return 0;
}

/*

To run this program :
1. g++ writeToFileFromDiffFunctions.cpp
2. ./a.out 
3. cat writeFromDiffFuncs.txt

------------------------------------------
Messages from different functions named cat, dog and cow are write to a file with the file open in 
the main function. 

Once the program runs successfully, you should see a text file named 
writeFromDiffFuncs.txt in the same directory. 

*/
