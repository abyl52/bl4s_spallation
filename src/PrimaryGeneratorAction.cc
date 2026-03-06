#include "PrimaryGeneratorAction.hh"

// Подключаем нужные инструменты
#include "G4ParticleGun.hh"
#include "G4Neutron.hh"
#include "G4SystemOfUnits.hh"
#include "G4Event.hh"

// ==========================================
// КОНСТРУКТОР: НАСТРОЙКА ПУШКИ
// ==========================================
PrimaryGeneratorAction::PrimaryGeneratorAction()
: G4VUserPrimaryGeneratorAction(),
  fParticleGun(nullptr)
{
    // Создаем пушку, которая выпускает 1 частицу за раз
    fParticleGun = new G4ParticleGun(1);

    // 1. Выбираем частицу — Нейтрон
    fParticleGun->SetParticleDefinition(G4Neutron::NeutronDefinition());
    
    // 2. Устанавливаем энергию (1 ГэВ)
    fParticleGun->SetParticleEnergy(1.0 * GeV);
    
    // 3. Задаем направление выстрела — прямо по оси Z
    fParticleGun->SetParticleMomentumDirection(G4ThreeVector(0., 0., 1.));
    
    // 4. Устанавливаем позицию пушки перед мишенью (по оси Z на -15 см)
    fParticleGun->SetParticlePosition(G4ThreeVector(0., 0., -40.*cm));
}

PrimaryGeneratorAction::~PrimaryGeneratorAction() {
    delete fParticleGun;
}

// ==========================================
// ВЫСТРЕЛ (ГЕНЕРАЦИЯ СОБЫТИЯ)
// ==========================================
void PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent) {
    // Эта функция нажимает на "курок" для каждой новой симуляции
    fParticleGun->GeneratePrimaryVertex(anEvent);
}