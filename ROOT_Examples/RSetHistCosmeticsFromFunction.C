// C++ Headers
#include <iostream>

// ROOT Headers
#include <TH1D.h>

TH1D* setHistCosmetics( int nBins, int binMin, int binMax ){

	TH1D *h1 = new TH1D("h1", "First hist", nBins, binMin, binMax);
	h1->FillRandom("gaus", 1000);

	// Apply cosmetics
	h1->SetLineColor(kGreen);
	return h1;
}

void RSetHistCosmeticsFromFunction(){

	TH1D *h2 = new TH1D("h2", "First hist", 100, -10, 10);

	TF1 *f = new TF1("f", "exp(-x)", 0, 6.28);
	h2->FillRandom("f", 1000);
	h2->SetLineColor(kRed);
	h2->Draw();

	setHistCosmetics(100, -10, 10)->Draw("same");

}

/*
 * 
 * A sample program that creates a histogram with random 
 * samples, where the goal of this program is to set cosmetics
 * in the function.
 *
 * This program can be a template when your macro is going to have
 * lots of histograms and a lots of lines are to be written just for
 * the same of cosmetics
 *
 */


