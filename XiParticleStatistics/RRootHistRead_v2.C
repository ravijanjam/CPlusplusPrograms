// C++ Headers
#include <iostream>

// ROOT Headers
#include <TFile.h>
#include <TF1.h>
#include <TH1D.h>
#include <TString.h>
#include <TLegend.h>
#include <TLatex.h>

double fitFunction(double *x, double *p){

	return p[0]*exp(-x[0]*p[1]);

}

void RRootHistRead_v2(){
	
	TCanvas *c = new TCanvas("c", "", 1024, 758);
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
	fitFn->SetLineColor(kGreen);
	fitFn->GetParameters(paramFromFit);

	// Generate data from fit
	double nBins = 27, pT[27], spectraFromFit[27]; // From the Xi 
	for (int i=0; i < nParam; i++) cout << "Parameters from fit: " << paramFromFit[i] << "\t";
	cout << endl;
	for (int i=0; i < nBins; i++){

		//spectraFromFit[i] = paramFromFit[0]*exp(-i) + paramFromFit[1];
//		spectraFromFit[i] = paramFromFit[0]*exp(-i + paramFromFit[1]) ;
		spectraFromFit[i] = 2.86252e-02*exp(-i*1.50842e+00) ;
		pT[i] = i;
			
	}

	// Using Integral for the Fit, to account for binwidth effects
	fitFn->SetLineColor(kBlue);
	h->Fit(fitFn, "I");
	h->SetMarkerStyle(20);

	c->SetLogy(1);
	TGraph *g = new TGraph(nBins, pT, spectraFromFit);
	g->SetTitle("#Xi^{+} spectra from pPb data, CMS");
	g->SetMarkerStyle(21);
	g->SetMarkerSize(1.5);
	g->SetMarkerColor(kRed);
	g->Draw("alp");
	h->Draw("same");
	

	TLegend *lg = new TLegend(0.67, 0.77, 0.87, 0.87);
	lg->AddEntry(h, "Histogram", "lp");
	lg->AddEntry(g, "Reconstructed function from fit, 27 bins", "lp");
	lg->AddEntry(fitFn, "Fit from the function", "lp");
	lg->Draw();
}


/*
 * Notes :
 * 1. The parameters from the fit are observed at the output and put by hand in the interpolating function. This needs to be automated.
 * 2. The input is put by hand, needs to be given during run time. So, is the case with histograms and their names. 
 *
 */
