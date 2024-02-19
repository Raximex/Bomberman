<<<<<<<<< Temporary merge branch 1
cmake_minimum_required(VERSION 3.16)
project(Bomberman LANGUAGES CXX)
=========
cmake_minimum_required(VERSION 3.27)

project(Bomberman)
>>>>>>>>> Temporary merge branch 2

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

<<<<<<<<< Temporary merge branch 1
include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)
=========
add_executable(Bomberman main.cpp
        src/Graphics/Graphics.cpp
        src/game/Carte.cpp
        src/Graphics/MainMenu.h
        src/Graphics/MainMenu.cpp
        src/Graphics/Graphics.cpp)
set(SFML_STATIC_LIBRAIRIES TRUE)
set(SFML_DIR /home/raximex/CLionProjects/SFML-2.6.1/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)
>>>>>>>>> Temporary merge branch 2

add_executable(Bomberman main.cpp)
target_link_libraries(Bomberman PRIVATE sfml-graphics sfml-window)
target_compile_features(Bomberman PRIVATE cxx_std_17)

if(WIN32)
    add_custom_command(
        TARGET Bomberman
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:Bomberman>
        VERBATIM)
endif()

install(TARGETS Bomberman)
