# Указываем минимальную версию CMake
cmake_minimum_required(VERSION 3.16)

# Называем наш проект (симуляция высокоэнтропийного сплава)
project(CantorAlloySimulation)

# Просим систему найти установленный Geant4 на твоей Ubuntu
# ui_all и vis_all нужны, чтобы потом мы могли смотреть на протоны и нейтроны глазками в 3D
find_package(Geant4 REQUIRED ui_all vis_all)

# Подключаем настройки Geant4
include(${Geant4_USE_FILE})

# Говорим, где лежат наши будущие файлы с кодом
include_directories(${PROJECT_SOURCE_DIR}/include)
file(GLOB SOURCES "src/*.cc")
file(GLOB HEADERS "include/*.hh")

# Создаем исполняемый файл (назовем программу bl4s_sim)
add_executable(bl4s_sim main.cc ${SOURCES} ${HEADERS})

# Связываем нашу программу с физическими библиотеками Geant4
target_link_libraries(bl4s_sim ${Geant4_LIBRARIES})