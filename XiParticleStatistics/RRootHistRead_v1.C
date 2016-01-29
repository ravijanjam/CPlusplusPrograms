// C++ Headers
#include <iostream>

// ROOT Headers
#include <TFile.h>
#include <TF1.h>
#include <TH1D.h>
#include <TString.h>

double fitFunction(double *x, double *p){

	return p[0]*exp(-x[0]) + p[1];

}

void RRootHistRead_v1(){
	
	TFile *inputFile = new TFile("pPb_MBSpectra_Combine_-1_1.root");
	cout << "Is the file Open " << inputFile->IsOpen() << endl;

	//Copy the histogram
	TString hName = "Spectra_NtrkOffline0_inf";
	TH1D *h = (TH1D*)inputFile->Get(hName);

	cout << "Number of bins in the histogram: " << h->GetSize() << "\n";
	h->Draw();

	double nhBins = h->GetSize();
	for (int i=0; i < nhBins; i++) cout << h->GetBinWidth(i) << ", ";
	cout << endl;

	// Fit function
	double nParam = 2, maxValue = 5, minValue = 0;

	TF1 *fitFn = new TF1("fitFn", fitFunction, minValue, maxValue, nParam);

	// Set parameters for Fit
	fitFn->SetParameter(0, 0.008);

	// Get parameters from Fit
	double paramFromFit[2];
	fitFn->GetParameters(paramFromFit);

	// Generate data from fit
	double nBins = 27, pT[27], spectraFromFit[27]; // From the Xi 
	for (int i=0; i < nBins; i++){

		spectraFromFit[i] = paramFromFit[0]*exp(-i) + paramFromFit[1];
		cout << spectraFromFit[i] << ", ";
		pT[i] = i;
			
	}

	// Using Integral for the Fit
	h->Fit(fitFn, "I");

	TGraph *g = new TGraph(nBins, pT, spectraFromFit);
	g->SetMarkerStyle(7);
	g->SetMarkerSize(1.5);
	g->SetMarkerColor(kGreen);
	g->Draw("ALP");
	h->Draw("same");
	
}

