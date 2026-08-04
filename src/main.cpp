#include <iostream>
#include <windows.h>
#include <filesystem>
#include <system_error>
#include <string>
#include <vector>
#include <chrono>
#include <thread>

#include "scheduler.h"
#include "wallpaper.h"
#include "wallpaper_library.h"

namespace fs = std::filesystem;
using namespace std::chrono_literals;

fs::path executableDirectory(){
    wchar_t buffer[MAX_PATH]; // wide character buffer to hold a windows path

    GetModuleFileNameW(
        nullptr,  // Give me the filename of this executable
        buffer, // store the result here
        MAX_PATH // The buffer can hold up to 260 characters
    ); // 

    return fs::path(buffer).parent_path(); // the parent path is what we need not the executable path
}

int main() {
    WallpaperLibrary library(executableDirectory() / "assets");
    int offsetHour = 10; // align the images with the time of day that best suits you
    int previousIndex = -1;
    std::cout << "Wallpaper Scheduler Running" << std::endl; 
    while (true) {
        int index = scheduler::currentIndex(library.size(), offsetHour);

        if (index != previousIndex) {
            wallpaper::set(library.get(index));
            previousIndex = index;
        }
        std::this_thread::sleep_for(1s);
    }

    return 0;
}