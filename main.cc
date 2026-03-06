#include "G4RunManagerFactory.hh"
#include "G4UImanager.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"
#include "G4ScoringManager.hh" // <-- ДОБАВИЛИ: Подключаем библиотеку счетчиков

// Подключаем файлы, которые мы напишем на следующих этапах
#include "DetectorConstruction.hh"
#include "PhysicsList.hh"
#include "ActionInitialization.hh" 

int main(int argc, char** argv) {
    // 1. Создаем графический интерфейс (чтобы мы могли видеть всё в 3D)
    G4UIExecutive* ui = nullptr;
    if (argc == 1) { 
        ui = new G4UIExecutive(argc, argv); 
    }

    // 2. Создаем главное ядро симуляции (RunManager)
    auto* runManager = G4RunManagerFactory::CreateRunManager(G4RunManagerType::Default);

    // <-- ДОБАВИЛИ: Включаем менеджер счетчиков сразу после ядра
    G4ScoringManager::GetScoringManager(); 

    // 3. Загружаем нашу лабораторию: мишень и детекторы
    runManager->SetUserInitialization(new DetectorConstruction());

    // 4. Загружаем физику: законы взаимодействия нейтронов с ядрами металлов
    runManager->SetUserInitialization(new PhysicsList());

    // 5. Загружаем "действия": запуск пушки частиц и сбор данных
    runManager->SetUserInitialization(new ActionInitialization()); 

    // 6. Запускаем менеджер визуализации
    G4VisManager* visManager = new G4VisExecutive;
    visManager->Initialize();

    // 7. Настраиваем управление командами
    G4UImanager* UImanager = G4UImanager::GetUIpointer();

    if (!ui) { 
        // Если запускаем программу через терминал с файлом макроса (для массовых расчетов)
        G4String command = "/control/execute ";
        G4String fileName = argv[1];
        UImanager->ApplyCommand(command + fileName);
    } else { 
        // Если запускаем просто так — открываем красивое окно
        // UImanager->ApplyCommand("/control/execute init_vis.mac"); 
        ui->SessionStart();
        delete ui;
    }

    // Завершаем работу и очищаем память
    delete visManager;
    delete runManager;
    return 0;
}