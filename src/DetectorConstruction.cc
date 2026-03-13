#include "DetectorConstruction.hh"
#include "G4Tubs.hh"
#include "G4NistManager.hh"
#include "G4Material.hh"
#include "G4Element.hh"
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"

DetectorConstruction::DetectorConstruction() : G4VUserDetectorConstruction() {}
DetectorConstruction::~DetectorConstruction() {}

G4VPhysicalVolume* DetectorConstruction::Construct() {
    G4NistManager* nist = G4NistManager::Instance();

    
    G4Material* world_mat = nist->FindOrBuildMaterial("G4_Galactic");

    G4Element* elMn = nist->FindOrBuildElement("Mn"); 
    G4Element* elCo = nist->FindOrBuildElement("Co");
    G4Element* elCr = nist->FindOrBuildElement("Cr");
    G4Element* elFe = nist->FindOrBuildElement("Fe");
    G4Element* elNi = nist->FindOrBuildElement("Ni");

    
    G4Material* heaMnCoCrFeNi = new G4Material("AlCoCrFeNi", 7.15*g/cm3, 5);
    heaMnCoCrFeNi->AddElement(elMn, 1);
    heaMnCoCrFeNi->AddElement(elCo, 1);
    heaMnCoCrFeNi->AddElement(elCr, 1);
    heaMnCoCrFeNi->AddElement(elFe, 1);
    heaMnCoCrFeNi->AddElement(elNi, 1);

   
    G4double world_size = 100.*cm;
    G4Box* solidWorld = new G4Box("World", world_size, world_size, world_size);
    G4LogicalVolume* logicWorld = new G4LogicalVolume(solidWorld, world_mat, "World");
    G4VPhysicalVolume* physWorld = new G4PVPlacement(0, G4ThreeVector(), logicWorld, "World", 0, false, 0, true);

    
    G4Tubs* solidTarget = new G4Tubs("Target", 
                                     0.*cm,       
                                     5.*cm,       
                                     3.0*cm,      
                                     0.*deg, 
                                     360.*deg); 

    G4LogicalVolume* logicTarget = new G4LogicalVolume(solidTarget, heaMnCoCrFeNi, "Target");

   
    new G4PVPlacement(
        0,                        
        G4ThreeVector(0, 0, 3.0*cm), 
        logicTarget,              
        "Target",                 
        logicWorld,               
        false, 
        0, 
        true);

    
    return physWorld;
}