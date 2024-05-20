cmake_minimum_required(VERSION 3.24)
project(hex)

set(CMAKE_CXX_STANDARD 17)
set(BUILD_SHARED_LIBS FALSE)

include(FetchContent)

FETCHCONTENT_DECLARE(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git)
FETCHCONTENT_MAKEAVAILABLE(SFML)

add_executable(hex main.cpp Menu.h Button.cpp Button.h Pawn.cpp Pawn.h PlayerColor.h Hex.cpp Hex.h Board.cpp Board.h Globals.h Globals.cpp MenuState.h GameState.h)
target_link_libraries(hex
        sfml-system
        sfml-window
        sfml-graphics)
