#include "G4RunManagerFactory.hh"
#include "G4UImanager.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"
#include "G4ScoringManager.hh" 


#include "DetectorConstruction.hh"
#include "PhysicsList.hh"
#include "ActionInitialization.hh" 

int main(int argc, char** argv) {
    
    G4UIExecutive* ui = nullptr;
    if (argc == 1) { 
        ui = new G4UIExecutive(argc, argv); 
    }

    
    auto* runManager = G4RunManagerFactory::CreateRunManager(G4RunManagerType::Default);

    
    G4ScoringManager::GetScoringManager(); 

   
    runManager->SetUserInitialization(new DetectorConstruction());

    
    runManager->SetUserInitialization(new PhysicsList());

   
    runManager->SetUserInitialization(new ActionInitialization()); 

  
    G4VisManager* visManager = new G4VisExecutive;
    visManager->Initialize();

    
    G4UImanager* UImanager = G4UImanager::GetUIpointer();

    if (!ui) { 
       
        G4String command = "/control/execute ";
        G4String fileName = argv[1];
        UImanager->ApplyCommand(command + fileName);
    } else { 
      
        ui->SessionStart();
        delete ui;
    }

   
    delete visManager;
    delete runManager;
    return 0;
}