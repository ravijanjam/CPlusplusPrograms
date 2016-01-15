// C++ Headers
#include <iostream>
#include <string>

// ROOT Headers
#include <TCanvas.h>
#include <TString.h>

using namespace std;

void arrayOfCanvases(){

	TCanvas *c[5]; 
	TString s;

	for (int i=0; i<5; i++){

		s.Form("s[%d]",i);

		c[i] = new TCanvas(s, "Canvas", 700, 300);
	}
}
