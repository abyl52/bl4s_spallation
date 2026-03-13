#include "RunAction.hh"
#include "G4AnalysisManager.hh"

RunAction::RunAction() {
    auto analysisManager = G4AnalysisManager::Instance();
    analysisManager->SetDefaultFileType("csv");
    
    analysisManager->CreateH1("0", "Neutron Angular Distribution", 180, 0., 180.);
}

RunAction::~RunAction() {}

void RunAction::BeginOfRunAction(const G4Run*) {
    auto analysisManager = G4AnalysisManager::Instance();
    analysisManager->OpenFile("neutron_angles.csv"); 
}
void RunAction::EndOfRunAction(const G4Run*) {
    auto analysisManager = G4AnalysisManager::Instance();
    analysisManager->Write();
    analysisManager->CloseFile();
}