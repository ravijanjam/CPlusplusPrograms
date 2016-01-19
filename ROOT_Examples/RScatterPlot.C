
// ROOT Headers
#include <TH1D.h>
#include <TRandom3.h>

void RScatterPlot(){

	// Defined a 2D Histogram
	TH2D *h2scatt = new TH2D("h2","Scatter plot", 50, -5, 5, 50, -5, 5);

	// Pass some values 
	double px, py;
	for (int i=0; i < 100000; i++){
		gRandom->Rannor(px, py);
		h2scatt->Fill(px, 5*py);
		h2scatt->Fill(3+0.5*px, 2*py-10);
	}
	//h2scatt->Draw("scat=1");
	h2scatt->SetFillColor(5);
	h2scatt->Draw("ARR");
}
