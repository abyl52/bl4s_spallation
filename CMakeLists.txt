
cmake_minimum_required(VERSION 3.16)


project(CantorAlloySimulation)


find_package(Geant4 REQUIRED ui_all vis_all)


include(${Geant4_USE_FILE})


include_directories(${PROJECT_SOURCE_DIR}/include)
file(GLOB SOURCES "src/*.cc")
file(GLOB HEADERS "include/*.hh")


add_executable(bl4s_sim main.cc ${SOURCES} ${HEADERS})


target_link_libraries(bl4s_sim ${Geant4_LIBRARIES})