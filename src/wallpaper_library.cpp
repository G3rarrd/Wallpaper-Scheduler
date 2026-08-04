#include "wallpaper_library.h"

#include <filesystem>

namespace fs = std::filesystem;

WallpaperLibrary::WallpaperLibrary(const fs::path& folder) {
    for (const auto& entry : fs::directory_iterator(folder)){
        if (!entry.is_regular_file()) continue;

        auto ext = entry.path().extension().string();

        if (ext == ".jpg" || ext == "jpeg" || ext == ".png" || ext == ".bmp") {
            wallpapers_.push_back(entry.path());
        }
    }
}

std::size_t WallpaperLibrary::size() const {
    return wallpapers_.size();
}

const fs::path& WallpaperLibrary::get(std::size_t index) const{
    return wallpapers_.at(index);
}