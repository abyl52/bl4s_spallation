#include "SteppingAction.hh"
#include "G4Step.hh"
#include "G4Neutron.hh"
#include "G4AnalysisManager.hh"
#include "G4SystemOfUnits.hh"

SteppingAction::SteppingAction() {}
SteppingAction::~SteppingAction() {}

void SteppingAction::UserSteppingAction(const G4Step* step) {
    // 1. Ищем только нейтроны
    if (step->GetTrack()->GetDefinition() != G4Neutron::NeutronDefinition()) return;

    // 2. Смотрим, где была частица шаг назад и где сейчас
    G4StepPoint* prePoint = step->GetPreStepPoint();
    G4StepPoint* postPoint = step->GetPostStepPoint();

    // 3. Если нейтрон пересекает границу объема...
    if (postPoint->GetStepStatus() == fGeomBoundary) {
        // ...и этот объем был нашей мишенью (Target)
        if (prePoint->GetPhysicalVolume()->GetName() == "Target") {
            
            // Вычисляем угол отклонения от оси Z (от 0 до 180 градусов)
            G4double angle = step->GetTrack()->GetMomentumDirection().theta();
            
            // Записываем угол в наш график
            G4AnalysisManager::Instance()->FillH1(0, angle / deg);
        }
    }
}