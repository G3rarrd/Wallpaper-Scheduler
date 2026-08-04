cmake_minimum_required(VERSION 3.20)

project(wallpaper_scheduler)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(WallpaperScheduler WIN32
    src/main.cpp
    src/scheduler.cpp
    src/wallpaper.cpp
    src/wallpaper_library.cpp
)

target_include_directories(WallpaperScheduler PRIVATE include)

add_custom_command(TARGET WallpaperScheduler POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/assets
        $<TARGET_FILE_DIR:WallpaperScheduler>/assets
)