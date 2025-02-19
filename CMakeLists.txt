cmake_minimum_required(VERSION 3.29.3)
project (space_invaders VERSION 0.1.0 LANGUAGES CXX)
set(CXX_STANDARD 23)

add_compile_options(
    -pedantic-errors
    -Wall
    -Weffc++
    -Wextra
    -Wconversion
    -Wsign-conversion
    -Werror
)

set(SOURCE_FILES
        "src/main.cpp"
        "src/Game.cpp"
        "src/TextureManager.cpp"
        )

add_executable(space_invaders ${SOURCE_FILES})

if(NOT PNG AND WIN32 AND NOT MSVC)
    set(PNG_LIBRARY "C:/Program Files(x86)/libpng")
    set(PNG_PNG_INCLUDE_DIR "C:/Program Files(x86)/libpng/include")
endif()

find_package(SDL3 REQUIRED)
find_package(SDL3_image REQUIRED)

target_include_directories(space_invaders
    PUBLIC ${SDL3_INCLUDE_DIRS}
    PUBLIC ${SDL3IMAGE_INCLUDE_DIRS}
)

if(WIN32 AND NOT MSVC)
    target_link_libraries(space_invaders PUBLIC ${SDL3_LIBRARIES} SDL3_image::SDL3_image mingw32)
else()
    target_link_libraries(space_invaders PUBLIC ${SDL3_LIBRARIES} SDL3_image::SDL3_image)
endif()
