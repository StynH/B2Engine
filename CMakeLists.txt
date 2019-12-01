cmake_minimum_required(VERSION 3.15)
project(B2BSand C)

set(CMAKE_C_STANDARD 99)
set(SDL2_INCLUDE_DIRS ${CMAKE_CURRENT_LIST_DIR}/extern/SDL2-2.0.10/include/)
set(SDL2_LIBRARIES ${CMAKE_CURRENT_LIST_DIR}/extern/SDL2-2.0.10/lib/x86/)

set(GCC_COVERAGE_LINK_FLAGS -lmingw32 -lSDL_image -lSDLmain -lSDL)

include_directories(${SDL2_INCLUDE_DIRS})

add_executable(B2BSand main.c Entity.c Entity.h Context.c Context.h Game.c Game.h Graphics.c Graphics.h Systems.c Systems.h)
target_link_libraries(B2BSand ${SDL2_LIBRARIES}/SDL2.lib ${SDL2_LIBRARIES}/SDL2main.lib ${SDL2_LIBRARIES}/SDL2_image.lib)