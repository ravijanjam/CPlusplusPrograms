from CRABClient.UserUtilities import config, getUsernameFromSiteDB
config = config()

config.General.requestName = 'tutorial_May2015_Data_analysis'
config.General.workArea = 'crab_projects'
config.General.transferOutputs = True
config.General.transferLogs = False

config.JobType.pluginName = 'Analysis'
config.JobType.psetName = 'TrackAnalyzer_cfg.py'

config.Data.inputDataset = '/PAHighPt/HIRun2013-PromptReco-v1/RECO'
config.Data.inputDBS = 'global'
config.Data.splitting = 'LumiBased'
config.Data.unitsPerJob = 20
config.Data.lumiMask = 'https://cms-service-dqm.web.cern.ch/cms-service-dqm/CAF/certification/Collisions13/pPb/Prompt/Cert_210498-211631_HI_PromptReco_Collisions13_JSON_v2.txt'
config.Data.runRange = '211275-211629' # '193093-194075'
config.Data.outLFNDirBase = '/store/user/%s/' % (getUsernameFromSiteDB())
config.Data.publication = True
config.Data.publishDataName = 'CRAB3_tutorial_May2015_Data_analysis'

config.Site.storageSite = 'T2_US_Vanderbilt'
