
#include <TCanvas.h>
#include <TH3D.h>
#include <TRandom3.h>

void RScatterPlot3D(){
   TCanvas *c06 = new TCanvas("c06","c06",600,400);
   gStyle->SetOptStat(kFALSE);
   TH3F *h3scat = new TH3F("h3scat","Option SCAT (default) ",15,-2,2,15,-2,2,15,0,4);
   Double_t x, y, z;
   for (Int_t i=0;i<10000;i++) {
      gRandom->Rannor(x, y);
      z = x*x + y*y;
      h3scat->Fill(x,y,z);
   }
   h3scat->Draw();
}
