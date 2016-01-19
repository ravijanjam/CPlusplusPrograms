#include <TH1D.h>
#include <TCanvas.h>
#include <TRandom3.h>
#include <TF1.h>

TH1D* returnHistogram( int nBins ){

	TH1D *h = new TH1D("h", "Test Histogram", nBins, 0, 10);
	TF1 *f = new TF1("f", "abs(sin(x)/x)", 0, 10);

	for (int i=0; i < nBins; i++ ) h->Fill(f->GetRandom());
	h->Delete();

	return h;
}

void RHistReturnFromFunction(){

	TH1D h = (TH1D)returnHistogram(5)->Draw();

	
}

