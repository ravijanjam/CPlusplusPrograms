/* Scroll to the bottom for more information */


// ROOT Headers
#include "TH1D.h"
#include "TRandom3.h"

// C++ Header
#include <iostream>

using namespace std; 

struct histStruct{

	TH1D *h1;

};

// Populate the histogram in this function
TH1D& writeHistogram(histStruct &hs){

	hs.h1 = new TH1D("hs.h1", "test histograms", 1000, 0, 1);

	for (int i=0; i<1000; i++){
		
		 gRandom->SetSeed(0);
		 (hs.h1)->Fill(gRandom->Rndm());
	}
	
	return *hs.h1;
	
}

void histInsideStruct(){

	// Initialize the struct containing the bare histogram
	histStruct hs; 
	
	// Call the histogram populated in the function outside
	writeHistogram(hs).Draw();
	
	//(hs.h1)->Draw();

}

/*

This program passes a histogram initialized in a structure, 
fills it in a function outside main and draws it in main function. 

*/
