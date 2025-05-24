cmake_minimum_required(VERSION 3.15)
project(MusicWalker LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# SDL2 Configuration - Using MSYS2 paths
set(SDL2_ROOT "C:/msys64/mingw32")
set(SDL2_INCLUDE_DIR "${SDL2_ROOT}/include/SDL2")
set(SDL2_LIBRARY "${SDL2_ROOT}/lib/libSDL2.a")

# SDL2_mixer Configuration
set(SDL2_MIXER_DLL "${SDL2_ROOT}/bin/SDL2_mixer.dll")
set(SDL2_MIXER_IMPORT_LIB "${SDL2_ROOT}/lib/libSDL2_mixer.dll.a")

# Qt Configuration
find_package(Qt5 5.5 REQUIRED COMPONENTS Widgets)

# Source files
file(GLOB SOURCES "src/*.cpp" "main.cpp")
file(GLOB HEADERS "include/*.h")

# Windows-specific: Add icon resource
if(WIN32)
    set(WINDOWS_ICON_RESOURCE "resource.rc")
endif()

# Main executable with icon resource (only added on Windows)
add_executable(MusicWalker ${SOURCES} ${HEADERS} ${WINDOWS_ICON_RESOURCE})

# Include directories
target_include_directories(MusicWalker PRIVATE
    include
    ${SDL2_INCLUDE_DIR}
)

# Link libraries
target_link_libraries(MusicWalker
    Qt5::Widgets
    ${SDL2_LIBRARY}
    ${SDL2_MIXER_IMPORT_LIB}
    mingw32
    -lsetupapi
    -lwinmm
    -lversion
    -limm32
    -lole32
)

# Output directory: Executable will go to build/MusicWalker/
set_target_properties(MusicWalker PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/MusicWalker
    WIN32_EXECUTABLE TRUE
)

# Copy necessary DLLs after build
if(WIN32)
    add_custom_command(TARGET MusicWalker POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy "${SDL2_ROOT}/bin/SDL2.dll" $<TARGET_FILE_DIR:MusicWalker>
        COMMAND ${CMAKE_COMMAND} -E copy "${SDL2_MIXER_DLL}" $<TARGET_FILE_DIR:MusicWalker>
        COMMAND ${CMAKE_COMMAND} -E copy "${SDL2_ROOT}/bin/libmpg123-0.dll" $<TARGET_FILE_DIR:MusicWalker>
        COMMENT "Copying required DLLs to output directory"
    )
endif()
