// C++ Headers
#include <iostream>

// ROOT Headers
#include <TH1D.h>


TH1D* setHistCosmetics( TH1D *h, Color_t kcolor ){

	h->SetLineColor(kcolor);
	return h;
}

void RSetHistCosmeticsFromFunction(){

	// Initialize Histograms
	TH1D *h1 = new TH1D("h1", "First hist", 100, -10, 10);
	TH1D *h2 = new TH1D("h2", "First hist", 100, -10, 10);

	// Sample data from functions randomly
	TF1 *f1 = new TF1("f1", "exp(-x)", 0, 6.28);
	TF1 *f2 = new TF1("f2", "sin(x)*exp(-x)", 0, 6.28);

	h1->FillRandom("f1", 1000);
	h2->FillRandom("f2", 1000);

	// Draw the returned histogram from function
	setHistCosmetics(h1, 62)->Draw();
	setHistCosmetics(h2, 72)->Draw("same");

}

/*
 * 
 * A sample program that creates a histogram with random 
 * samples, where the goal of this program is to set cosmetics
 * in the function.
 *
 * This program can be a template when your macro is going to have
 * lots of histograms and a lots of lines are to be written just for
 * the sake of cosmetics per histogram
 *
 */


