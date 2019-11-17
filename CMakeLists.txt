project(VILE_FOUR)

set(CMAKE_CXX_STANDARD 17)

if (NOT DEFINED SFML_ROOT)
    message(FATAL_ERROR "SFML_ROOT is not set or SFML library not found.")
endif ()

set(SFML_DIR "${SFML_ROOT}/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

file(GLOB SOURCE_FILES ${PROJECT_SOURCE_DIR}/*.cpp ${PROJECT_SOURCE_DIR}/*.h)

add_executable(VILE_FOUR ${SOURCE_FILES})

target_link_libraries(VILE_FOUR sfml-graphics sfml-window sfml-system)