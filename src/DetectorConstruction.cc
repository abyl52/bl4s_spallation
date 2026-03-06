#include "DetectorConstruction.hh"
#include "G4Tubs.hh"
// Подключаем нужные инструменты Geant4
#include "G4NistManager.hh"
#include "G4Material.hh"
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"

// Конструктор и деструктор (пока пустые)
DetectorConstruction::DetectorConstruction() : G4VUserDetectorConstruction() {}
DetectorConstruction::~DetectorConstruction() {}

G4VPhysicalVolume* DetectorConstruction::Construct() {
    // Вызываем менеджера материалов
    G4NistManager* nist = G4NistManager::Instance();

    // ==========================================
    // 1. СОЗДАЕМ МИР (ВАКУУМ)
    // ==========================================
    G4Material* world_mat = nist->FindOrBuildMaterial("G4_Galactic");
    
    // Создаем куб размером 2x2x2 метра (задаются полуразмеры 1m, 1m, 1m)
    G4Box* solidWorld = new G4Box("World", 100.*cm, 100.*cm, 100.*cm);
    G4LogicalVolume* logicWorld = new G4LogicalVolume(solidWorld, world_mat, "World");
    
    // Помещаем Мир в координаты 0,0,0
    G4VPhysicalVolume* physWorld = new G4PVPlacement(
        0, G4ThreeVector(), logicWorld, "World", 0, false, 0, true);

    // ==========================================
    // 2. СОЗДАЕМ ЛЕГКИЙ СПЛАВ (AlCrFeMnSi)
    // ==========================================
    // Находим химические элементы в базе Geant4
    G4Element* elAl = nist->FindOrBuildElement("Al");
    G4Element* elCr = nist->FindOrBuildElement("Cr");
    G4Element* elFe = nist->FindOrBuildElement("Fe");
    G4Element* elMn = nist->FindOrBuildElement("Mn");
    G4Element* elSi = nist->FindOrBuildElement("Si");

    // Задаем плотность легкого сплава (~5.5 г/см3) и указываем, что в нем 5 компонентов
    G4Material* heaAlCrFeMnSi = new G4Material("AlCrFeMnSi", 5.5*g/cm3, 5);
    
    // Добавляем элементы в равных пропорциях (эквиатомный состав)
    heaAlCrFeMnSi->AddElement(elAl, 1);
    heaAlCrFeMnSi->AddElement(elCr, 1);
    heaAlCrFeMnSi->AddElement(elFe, 1);
    heaAlCrFeMnSi->AddElement(elMn, 1);
    heaAlCrFeMnSi->AddElement(elSi, 1);

    // ==========================================
    // 3. СОЗДАЕМ МИШЕНЬ ИЗ НОВОГО СПЛАВА
    // ==========================================
    // Создаем сплошной цилиндр
    // В Geant4 длина задается как ПОЛОВИНА от реальной (half-Z), поэтому пишем 30 см
    G4Tubs* solidTarget = new G4Tubs("Target", 
                                 0.*cm,      // Внутренний радиус
                                 15.*cm,     // Внешний радиус (15 см)
                                 30.*cm,     // Половина длины (30 см, итого 60 см)
                                 0.*deg,     // Начальный угол
                                 360.*deg);  // Полный круг
                                 
    // ВАЖНО: Заливаем форму новым материалом heaAlCrFeMnSi
    G4LogicalVolume* logicTarget = new G4LogicalVolume(solidTarget, heaAlCrFeMnSi, "Target");
    
    // Размещаем нашу мишень внутри логического объема "Мира" строго по центру
    new G4PVPlacement(
        0,                        // без вращения
        G4ThreeVector(0, 0, 0),   // в центре координат
        logicTarget,              // логический объем мишени
        "Target",                 // имя
        logicWorld,               // материнский объем (куда помещаем)
        false,                    // без булевых операций
        0,                        // номер копии
        true);                    // проверять пересечения объемов

    // Обязательно возвращаем физический объем Мира, чтобы программа могла его отрисовать
    return physWorld;
}