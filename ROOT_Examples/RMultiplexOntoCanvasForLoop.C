#include <TCanvas.h>
#include <TH1D.h>

void RMultiplexOntoCanvasForLoop(){

	TH1D *h[2];

	h[0] = new TH1D("hg", "Gauss", 1000, -5, 5);
	h[1] = new TH1D("hl", "Landau", 1000, -5, 5);

	int nEvents = 100000;
	h[0]->FillRandom("gaus", nEvents);
	h[1]->FillRandom("landau", nEvents);

	TCanvas *c[2];

	for (int i=0; i < 2; i++){

		c[i] = new TCanvas();

		c[i]->cd();
		h[i]->Draw();

	}
}//close-main

/*
 * This programs fills a couple of histograms with gaussian and landau distributions
 * and passes them onto canvases separately inside a for loop
 */

