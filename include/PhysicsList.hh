#ifndef PhysicsList_h
#define PhysicsList_h 1

#include "G4VModularPhysicsList.hh"

// Наследуем наш класс от базового модульного списка Geant4
class PhysicsList : public G4VModularPhysicsList {
  public:
    PhysicsList();
    virtual ~PhysicsList();

    // Функция установки порогов (на каком расстоянии прекращать считать трек частицы)
    virtual void SetCuts();
};

#endif