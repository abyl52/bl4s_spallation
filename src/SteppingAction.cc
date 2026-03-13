#include "SteppingAction.hh"
#include "G4Step.hh"
#include "G4Neutron.hh"
#include "G4AnalysisManager.hh"
#include "G4SystemOfUnits.hh"

SteppingAction::SteppingAction() {}
SteppingAction::~SteppingAction() {}

void SteppingAction::UserSteppingAction(const G4Step* step) {
   
    if (step->GetTrack()->GetDefinition() != G4Neutron::NeutronDefinition()) return;

    G4StepPoint* prePoint = step->GetPreStepPoint();
    G4StepPoint* postPoint = step->GetPostStepPoint();

    
    if (postPoint->GetStepStatus() == fGeomBoundary) {
        
        
        if (prePoint->GetPhysicalVolume()->GetName() == "Target") {
            
            
            G4double energy = step->GetTrack()->GetKineticEnergy();
            
            
            if (energy >= 50.0 * MeV) {
                
                
                G4double angle = step->GetTrack()->GetMomentumDirection().theta();
                G4AnalysisManager::Instance()->FillH1(0, angle / deg);
                
            }
        }
    }
}