import FWCore.ParameterSet.Config as cms

process = cms.Process("Demo")

process.load("FWCore.MessageService.MessageLogger_cfi")
# initialize MessageLogger and output report
process.load("FWCore.MessageLogger.MessageLogger_cfi")
process.MessageLogger.cerr.threshold = 'INFO'
process.MessageLogger.categories.append('Demo')
process.MessageLogger.cerr.INFO = cms.untracked.PSet(
        limit = cms.untracked.int32(-1)
        )
process.options   = cms.untracked.PSet( wantSummary = cms.untracked.bool(True) )

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(100))

process.source = cms.Source("PoolSource",
    # replace 'myfile.root' with the source file you want to use
    fileNames = cms.untracked.vstring(
#        'file:/afs/cern.ch/cms/Tutorials/TWIKI_DATA/TTJets_8TeV_53X.root'
#	'/store/hidata/HIRun2013/PAMinBiasUPC/RECO/28Sep2013-v1/10000/001397FC-462D-E311-A034-782BCB3BCADD.root'
#	'/store/hidata/HIRun2013/PAHighPt/RECO/28Sep2013-v1/10000/00806FCE-212C-E311-960B-003048F236BC.root'
	'/store/himc/Fall10/Hydjet_Bass_MinBias_2760GeV/GEN-SIM-RECODEBUG/START39_V7HI-v1/0002/46B060AD-C9FA-DF11-B18A-485B3919F121.root'
#	'/store/user/davidlw/PPMinBias/PP2013_FlowCorr_PromptReco_MB_Gplus_v2/e1306249b702130f95e9f12ead4695ee/pp_MB_100_1_HW4.root'
    )
)

process.demo = cms.EDAnalyzer('TrackAnalyzer',
	minTracks = cms.untracked.uint32(0),
	genSrc = cms.InputTag("hiGenParticles"),
	etaMax = cms.double(0.8)
)

#process.GlobalTag.globaltag = 'STAR39_V7HI::All'

process.dump = cms.EDAnalyzer('EventContentAnalyzer')

process.TFileService = cms.Service("TFileService",
                                       fileName = cms.string('_histodemo.root')
                                   )

process.p = cms.Path(process.demo*process.dump)
