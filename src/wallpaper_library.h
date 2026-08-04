#pragma once

#include <filesystem>
#include <vector>

class WallpaperLibrary {
    public:
        explicit WallpaperLibrary(const std::filesystem::path& imageFolder);

        std::size_t size() const;

        const std::filesystem::path& get(std::size_t index) const;

    private:
        std::vector<std::filesystem::path> wallpapers_;
};
