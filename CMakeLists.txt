cmake_minimum_required(VERSION 3.27)
project(Bomberman)

set(CMAKE_CXX_STANDARD 23)

add_executable(Bomberman main.cpp
        src/Graphics/Graphics.cpp
        src/game/Carte.cpp)
set(SFML_STATIC_LIBRAIRIES TRUE)
set(SFML_DIR /home/raximex/CLionProjects/SFML-2.6.1/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(/home/raximex/CLionProjects/SFML-2.6.1/include/SFML)

target_link_libraries(Bomberman sfml-system sfml-window sfml-audio sfml-graphics)