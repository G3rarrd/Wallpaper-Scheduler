#include "wallpaper.h"
#include <windows.h>
#include <filesystem>
#include <system_error>
#include <string>

namespace fs = std::filesystem;

namespace wallpaper{
    void set(const fs::path& image) {
        // Absolute image path is needed unless the desktop wallpaper will be black 
        auto absoluteImage = fs::absolute(image);

        // No need to proceed if the absolute path does not exist
        if (!fs::exists(absoluteImage)) {
            throw std::runtime_error("Image file does not exist.");
        }

        // So wallpaper can be read by the Windows APIs SystemParametersInfoW
        std::wstring path = absoluteImage.wstring();

        if (!SystemParametersInfoW(
                SPI_SETDESKWALLPAPER,
                0,
                path.data(),
                SPIF_UPDATEINIFILE | SPIF_SENDCHANGE)) 
        {
            throw std::system_error(
                GetLastError(),
                std::system_category(),
                "Failed to change wallpaper");
        }

    }
}