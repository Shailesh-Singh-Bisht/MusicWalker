# MusicWalker

A modern, sleek MP3 music player built with Qt and SDL_mixer. MusicWalker provides a clean and intuitive interface for playing your music files with an easy-to-use queue system.

![MusicWalker Screenshot](asset/screenshot.png)

## Features

- 🎵 MP3 file playback support
- 📑 Music queue management system
- 🎨 Modern dark theme UI
- ⌨️ Keyboard shortcuts for common actions
- 📱 Responsive design that adapts to window size
- 🔊 High-quality audio playback using SDL_mixer
- 📁 Simple drag-and-drop file support
- 🎯 Memory-efficient playback engine

## Quick Start (Using Release)

1. Go to the [Releases](https://github.com/yourusername/MusicWalker/releases) page
2. Download the latest `MusicWalker-vX.X.X.zip`
3. Extract the ZIP file
4. Run `MusicWalker.exe`

No installation required - just extract and run!

## Build from Source

### Prerequisites

- Windows 10 or higher
- [MSYS2](https://www.msys2.org/) installed to `C:\msys64`
- [Qt 5.5.1](https://download.qt.io/archive/qt/5.5/5.5.1/) (MinGW 32-bit version)
- [CMake](https://cmake.org/download/) (3.15 or higher)
- [Visual Studio Code](https://code.visualstudio.com/) with C++ extensions

### Setup Steps

1. **Install MSYS2 Dependencies:**

   ```powershell
   # Open MSYS2 MINGW32 terminal and run:
   pacman -Syu
   pacman -S mingw-w64-i686-gcc mingw-w64-i686-ninja mingw-w64-i686-SDL2 mingw-w64-i686-SDL2_mixer
   ```

2. **Set Up Qt:**

   - Install Qt 5.5.1 MinGW 32-bit to `C:\Qt\Qt5.5.1`
   - Add `C:\Qt\Qt5.5.1\bin` to your system's PATH

3. **Clone & Build:**

   ```powershell
   git clone https://github.com/yourusername/MusicWalker.git
   cd MusicWalker
   mkdir build
   cd build
   cmake .. -G Ninja -DCMAKE_PREFIX_PATH="C:/Qt/Qt5.5.1/mingw32"
   ninja
   ```

4. **Deploy:**
   ```powershell
   # From the build directory:
   windeployqt MusicWalker/MusicWalker.exe
   ```

### Project Structure

```
MusicWalker/
├── asset/               # Icons and resources
├── include/            # Header files
│   ├── AudioPlayer.h   # SDL_mixer audio interface
│   ├── MainWindow.h    # Main application window
│   ├── PlayerArea.h    # Music visualization area
│   ├── PlayerWidget.h  # Playback controls
│   └── QueueManager.h  # Music queue handling
├── src/                # Implementation files
├── CMakeLists.txt     # Build configuration
├── main.cpp           # Application entry point
└── resource.rc        # Windows resources
```

## Key Files

- `AudioPlayer`: Handles MP3 playback using SDL_mixer
- `QueueManager`: Manages the music playlist and history
- `PlayerWidget`: Contains playback controls (play, pause, etc.)
- `PlayerArea`: Shows current track information
- `MainWindow`: Main application window and coordination

## Development Notes

The project uses:

- C++11 features
- Qt 5.5 for the UI framework
- SDL2 and SDL2_mixer for audio playback
- CMake for build configuration
- Modern dark theme design

## Building Tips

1. Make sure all paths in CMakeLists.txt match your system
2. The SDL2 configuration assumes MSYS2 paths
3. Qt deployment requires windeployqt for distribution
4. Building in Release mode is recommended for distribution

## Known Issues

- Only supports MP3 format currently
- Queue is not persistent between sessions
- No volume control in current version

## Contributing

1. Fork the repository
2. Create a feature branch: `git checkout -b my-new-feature`
3. Commit your changes: `git commit -am 'Add some feature'`
4. Push to the branch: `git push origin my-new-feature`
5. Submit a pull request

## License

This project is licensed under the MIT License - see the LICENSE file for details.

## Acknowledgments

- Qt Framework team
- SDL and SDL_mixer developers
- MSYS2 project maintainers

---

Made with ❤️ by [Your Name]
