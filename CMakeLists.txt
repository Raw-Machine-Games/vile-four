cmake_minimum_required(VERSION 3.15)
project(SFML_PROJECT)

set(CMAKE_CXX_STANDARD 17)

include_directories(/home/konstantin/build/SFML/include)

link_directories(/home/konstantin/build/SFML/lib)

add_executable(SFML_PROJECT main.cpp UserInput.cpp UserInput.h ActionsConfig.cpp ActionsConfig.h CoreInterface.h)

target_link_libraries(SFML_PROJECT sfml-graphics sfml-window sfml-system)