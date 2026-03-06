#include "ActionInitialization.hh"
#include "PrimaryGeneratorAction.hh"
#include "RunAction.hh"
#include "SteppingAction.hh"

ActionInitialization::ActionInitialization() : G4VUserActionInitialization() {}
ActionInitialization::~ActionInitialization() {}

void ActionInitialization::BuildForMaster() const {
    // Выдаем "Блокнот" главному потоку
    SetUserAction(new RunAction());
}

void ActionInitialization::Build() const {
    // 1. Передаем нашу пушку в ядро
    SetUserAction(new PrimaryGeneratorAction());
    
    // 2. Подключаем наш "Блокнот" (для создания и сохранения файла)
    SetUserAction(new RunAction());
    
    // 3. Подключаем наш "Радар" (для слежки за углами вылета)
    SetUserAction(new SteppingAction());
}