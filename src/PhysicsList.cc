#include "PhysicsList.hh"

// Подключаем нужные библиотеки физики
#include "G4EmStandardPhysics.hh"          // Электромагнетизм
#include "G4DecayPhysics.hh"               // Распад нестабильных частиц
#include "G4HadronElasticPhysicsHP.hh"     // Упругое рассеяние нейтронов (High Precision)
#include "G4HadronPhysicsFTFP_BERT_HP.hh"  // Неупругое рассеяние и реакции скалывания
#include "G4IonPhysics.hh"                 // Поведение вторичных ионов-осколков

PhysicsList::PhysicsList() : G4VModularPhysicsList() {
    // 1. Базовая физика
    RegisterPhysics(new G4EmStandardPhysics());
    RegisterPhysics(new G4DecayPhysics());

    // 2. Адронная физика для нашего пучка нейтронов 1 ГэВ
    // Включаем сверхточные модели (HP) для медленных нейтронов
    RegisterPhysics(new G4HadronElasticPhysicsHP());
    
    // Включаем модель Фритйофа (FTF) для высоких энергий и каскад Бертини (BERT)
    RegisterPhysics(new G4HadronPhysicsFTFP_BERT_HP());

    // 3. Физика осколков (чтобы видеть, как разлетается металл)
    RegisterPhysics(new G4IonPhysics());
}

PhysicsList::~PhysicsList() {}

void PhysicsList::SetCuts() {
    // Устанавливаем стандартные пороги обрезания для всех частиц
    SetCutsWithDefault();
}