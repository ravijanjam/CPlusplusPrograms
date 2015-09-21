// -*- C++ -*-
//
// Package:    TrackAnalyzer/TrackAnalyzer
// Class:      TrackAnalyzer
// 
/**\class TrackAnalyzer TrackAnalyzer.cc TrackAnalyzer/TrackAnalyzer/plugins/TrackAnalyzer.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  Ravi Kishore Janjam
//         Created:  Mon, 03 Aug 2015 21:05:19 GMT
//
//


// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
//#include "DataFormats/HeavyIonEvent/interface/CentralityProvider.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "DataFormats/TrackReco/interface/Track.h"
#include "DataFormats/TrackReco/interface/TrackFwd.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"

#include <DataFormats/HepMCCandidate/interface/GenParticle.h>
#include <DataFormats/HepMCCandidate/interface/GenParticleFwd.h>
#include "DataFormats/BeamSpot/interface/BeamSpot.h"

#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"
#include "TH1.h"

//
// class declaration
//

using namespace edm;
using namespace std; 
using namespace reco;

class TrackAnalyzer : public edm::EDAnalyzer {
   public:
      explicit TrackAnalyzer(const edm::ParameterSet&);
      ~TrackAnalyzer();

      static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);


   private:
      virtual void beginJob() override;
      virtual void analyze(const edm::Event&, const edm::EventSetup&) override;
      virtual void endJob() override;

	// ----------member data ---------------------------
	unsigned int minTracks_;
	TH1D *demohisto;
	TH1D* chargedHadrons_[10];
	TH1D* beamSpotHisto;
	TH1D* testDir;

	edm::InputTag genSrc_;
	double etaMax_;
	double x0;

//	CentralityProvider *centrality_;	

      //virtual void beginRun(edm::Run const&, edm::EventSetup const&) override;
      //virtual void endRun(edm::Run const&, edm::EventSetup const&) override;
      //virtual void beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&) override;
      //virtual void endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&) override;

      // ----------member data ---------------------------
};

//
// constants, enums and typedefs
//

//
// static data member definitions
//

//
// constructors and destructor
//
TrackAnalyzer::TrackAnalyzer(const edm::ParameterSet& iConfig)
: minTracks_(iConfig.getUntrackedParameter<unsigned int>("minTracks",0)),
genSrc_(iConfig.getParameter<edm::InputTag>("genSrc")),
etaMax_(iConfig.getParameter<double>("etaMax"))
{
   //now do what ever initialization is needed
	edm::Service<TFileService> fs;


//	char centString[10][256] = { "0-10%", "10-20%", "20-30%", "30-40%", "40-50%",
//					"50-60%", "60-70%", "70-80%", "80-90%", "90-100%" };
	TH1D::SetDefaultSumw2();
	TFileDirectory test = fs->mkdir("Test");
	demohisto = fs->make<TH1D>("tracks" , "Tracks" , 100 , 0 , 5000 );
	beamSpotHisto = fs->make<TH1D>("beamSpot" , "beam" , 100 , 0 , 5000 );

	testDir = test.make<TH1D>("testDir", "", 100, 0, 1);

	for (int i=0; i<10; i++) {
		chargedHadrons_[i] = fs->make<TH1D>(Form("chargedHadrons%d", i),
		 Form("Charged Hadron Spectrum, |#eta| < %f", etaMax_), 30, 0., 3.);

	}

//	centbins_ = fs->make<TH1I>("centbins","Centrality Distribution", 40, 0, 39);
//	centrality_ = 0;

}


TrackAnalyzer::~TrackAnalyzer()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called for each event  ------------
void
TrackAnalyzer::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
	cout << "=============== INSIDE ANALYZE ==================== " << endl;

	
	

	Handle<reco::TrackCollection> tracks;
	iEvent.getByLabel("generalTracks", tracks);
//	iEvent.getByLabel("hiSelectedTracks", tracks);
//
//
//	if(!centrality_) centrality_ = new CentralityProvider(iSetup);
//
//	centrality_->newEvent(iEvent,iSetup); // make sure you do this first in every event
//	//double c = centrality_->centralityValue();
//	int bin = centrality_->getBin();
//	centbins_->Fill(bin);
//
//
	demohisto->Fill(tracks->size());
	cout << tracks->size() << endl;

	if( minTracks_ <= tracks->size()){
		LogInfo("Demo") << "number of tracks "<<tracks->size();
	}

/*

	Handle<reco::GenParticleCollection> kgenparticles;
	iEvent.getByLabel(genSrc_, kgenparticles);

	for (reco::GenParticleCollection::const_iterator particle = kgenparticles->begin();
		particle != kgenparticles->end(); ++particle ){

		if (particle->status() == 1 &&
		    particle->charge() != 0 &&
		    fabs(particle->eta()) <= etaMax_ ) {
			chargedHadrons_[1]->Fill( particle->pt() );
	
		 }

	}
*/

	reco::BeamSpot beamSpot;
	edm::Handle<reco::BeamSpot> beamSpotHandle;
	iEvent.getByLabel("offlineBeamSpot", beamSpotHandle);

	if (beamSpotHandle.isValid())	
	{
		beamSpot = *beamSpotHandle;
	}else
	{

		edm::LogInfo("TrackAnalyzer")
			<< "No beam spot available from EventSetup \n" ;
	}

	
	double x0 = beamSpot.x0();
	beamSpotHisto->Fill(x0);
/*
	double y0 = beamSpot.y0();
	double z0 = beamSpot.z0();
	double sigmaz = beamSpot.sigmaZ();
	double dxdz = beamSpot.dxdz();
	double BeamWidthX = beamSpot.BeamWidthX();
	double BeamWidthY = beamSpot.BeamWidthY();
*/
	// print the beam spot object
	cout << beamSpot << endl;
	


#ifdef THIS_IS_AN_EVENT_EXAMPLE
   Handle<ExampleData> pIn;
   iEvent.getByLabel("example",pIn);
#endif
   
#ifdef THIS_IS_AN_EVENTSETUP_EXAMPLE
   ESHandle<SetupData> pSetup;
   iSetup.get<SetupRecord>().get(pSetup);
#endif
}


// ------------ method called once each job just before starting event loop  ------------
void 
TrackAnalyzer::beginJob()
{
}

// ------------ method called once each job just after ending the event loop  ------------
void 
TrackAnalyzer::endJob() 
{
}

// ------------ method called when starting to processes a run  ------------
/*
void 
TrackAnalyzer::beginRun(edm::Run const&, edm::EventSetup const&)
{
}
*/

// ------------ method called when ending the processing of a run  ------------
/*
void 
TrackAnalyzer::endRun(edm::Run const&, edm::EventSetup const&)
{
}
*/

// ------------ method called when starting to processes a luminosity block  ------------
/*
void 
TrackAnalyzer::beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}
*/

// ------------ method called when ending the processing of a luminosity block  ------------
/*
void 
TrackAnalyzer::endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}
*/

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
TrackAnalyzer::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(TrackAnalyzer);
