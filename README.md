# Wallpaper Scheduler

A lightweight C++ utility for automatically cycling desktop wallpapers throughout the day.

## Demo
![demo](https://github.com/G3rarrd/Wallpaper-Scheduler/blob/main/readme_assets/wallpaper_scheduler_demo.gif)

## Overview

Cycle through a folder of images and rotate them at a defined interval with wallpaper scheduler, with an optional startup behavior and a simple Windows-focused desktop integration.

## Features

- Cycle through images from a selected folder
- Set custom refresh interval
- Randomize or sequential order
- Run at startup or as a background process
- Lightweight C++ implementation
- Easy to build and extend

## Requirements

- Windows 10 or newer
- C++ compiler with C++20 support
- A folder containing valid image files (for example `.jpg`, `.jpeg`, `.png`, `.bmp`, `.webp` depending on your implementation)


## Building

Using `g++`:

```bash
g++ -std=c++20 -O2 main.cpp wallpaper_scheduler.cpp -o wallpaper_scheduler.exe
```

Using MSBuild or Visual Studio:

1. Open the project in Visual Studio.
2. Set the configuration to `Debug` or `Release`.
3. Build the solution.
4. Run the generated executable.

## Usage

Run the application from the terminal or from Explorer:

```bash
wallpaper_scheduler.exe
```

## Notes

This project is designed to be simple and easy to modify. If you want to add support for more file formats, custom UI settings, or a tray icon, those are natural extensions of the current design.

## License

This project does not include a license file. If you are publishing or distributing it, add a license appropriate for your use case before sharing it externally.

## Contributing

Contributions are welcome. If you improve the scheduler, add features, or fix bugs, open a pull request with a short description of the change.
