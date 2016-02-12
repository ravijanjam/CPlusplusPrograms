#include <TH1D.h>
#include <TCanvas.h>
#include <TH1.h>

void RVariableBinning(){


	TCanvas *c1 = new TCanvas("c1", "", 700, 400);
	TCanvas *c2 = new TCanvas("c2", "", 700, 400);

	double binArr[] = {-29, -20, -13, -10, -8, -3, 0, 3, 8, 20, 29};

	// Get the array size 
	int nBins = sizeof(binArr)/sizeof(double)-1;
	cout << "nBins " << nBins << endl;
	TH1D *h = new TH1D("n", "title", 100, -5, 5);
	h->FillRandom("gaus", 10000);

	TH1D *hVarBin;
	hVarBin = (TH1D*)h->Clone();
	hVarBin = (TH1D*)h->Rebin(nBins, "hVarBin", binArr);

	cout << "========================================================" << endl;
	cout << "Num of bins initial histogram: " << h->GetNbinsX() << endl;
	cout << "Num of bins in the clone of the histogram rebinned: " << hVarBin->GetNbinsX() << endl;
	cout << "Go to the end of the program for more information" << endl;
	cout << "========================================================" << endl;

	hVarBin->Scale(0.8);
	hVarBin->SetAxisRange(0, 5000, "Y");
	hVarBin->SetTitle("Rebinned Guassian Histogram");
	hVarBin->SetFillColor(kGreen-2);

	c2->cd();
	hVarBin->Draw();


	h->SetFillColor(kRed-2);
	h->SetTitle("Gaussian Fill, main histogram");
	c1->cd();
	h->Draw();

}

/* 
 *
 * Note that the data from the main histogram h is used to rebin another histogram
 */
