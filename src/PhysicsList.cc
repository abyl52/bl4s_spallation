#include "PhysicsList.hh"


#include "G4EmStandardPhysics.hh"          
#include "G4DecayPhysics.hh"               
#include "G4HadronElasticPhysicsHP.hh"     
#include "G4HadronPhysicsFTFP_BERT_HP.hh"  
#include "G4IonPhysics.hh"                 

PhysicsList::PhysicsList() : G4VModularPhysicsList() {
    
    RegisterPhysics(new G4EmStandardPhysics());
    RegisterPhysics(new G4DecayPhysics());

    
    RegisterPhysics(new G4HadronElasticPhysicsHP());
    
   
    RegisterPhysics(new G4HadronPhysicsFTFP_BERT_HP());

   
    RegisterPhysics(new G4IonPhysics());
}

PhysicsList::~PhysicsList() {}

void PhysicsList::SetCuts() {
    
    SetCutsWithDefault();
}