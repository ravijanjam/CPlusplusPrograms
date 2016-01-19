
// C++ Headers
#include <iostream>
#include <vector>

// ROOT Headers
#include <TH1D.h>
#include <TF1.h>
#include <TRandom3.h>

using namespace std;

void RStoreHistogramsInVector(){

	vector<TH1D*> vhist;
	TH1D *h = new TH1D("h", "Just another histogram", 100, 0, 1);
	TH1D *h2 = new TH1D("h2", "Just another histogram", 100, 0, 1);

	TF1 *mygaus = new TF1("mygaus", "TMath::Gaus(x, 0.3, 0.5)", 0.6);	
	TF1 *mygaus2 = new TF1("mygaus2", "TMath::Gaus(x, 1.3, 0.5)", 0.6);	

	h->FillRandom("mygaus", 10000);
	h2->FillRandom("mygaus", 10000);

	vhist.push_back(h);
	vhist.push_back(h2);

	TH1D *h3 = (TH1D*)vhist.at(0);
	h3->SetLineColor(kBlue);

	TH1D *h4 = (TH1D*)vhist.at(1);
	h4->SetLineColor(kRed);
	h3->Draw();
	h4->Draw("same");

} 
