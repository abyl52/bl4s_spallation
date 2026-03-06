#ifndef PrimaryGeneratorAction_h
#define PrimaryGeneratorAction_h 1

#include "G4VUserPrimaryGeneratorAction.hh"
#include "globals.hh"

// Говорим компилятору, что будем использовать классы пушки и события
class G4ParticleGun;
class G4Event;

class PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction {
  public:
    PrimaryGeneratorAction();  // Конструктор
    virtual ~PrimaryGeneratorAction(); // Деструктор

    // Главная функция, которая вызывается для каждого нового "выстрела"
    virtual void GeneratePrimaries(G4Event*);

  private:
    G4ParticleGun* fParticleGun; // Переменная нашей пушки
};

#endif