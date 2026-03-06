#ifndef DetectorConstruction_h
#define DetectorConstruction_h 1

#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"

// Говорим компилятору, что такие классы существуют
class G4VPhysicalVolume;
class G4LogicalVolume;

// Наш класс наследуется от базового класса Geant4
class DetectorConstruction : public G4VUserDetectorConstruction {
  public:
    DetectorConstruction();  // Конструктор
    virtual ~DetectorConstruction(); // Деструктор

    // Главная функция, которая построит нашу геометрию и вернет "Мир"
    virtual G4VPhysicalVolume* Construct(); 
};

#endif