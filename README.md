# MusicWalker
<!-- ALL-CONTRIBUTORS-BADGE:START - Do not remove or modify this section -->
[![All Contributors](https://img.shields.io/badge/all_contributors-3-orange.svg?style=flat-square)](#contributors-)
<!-- ALL-CONTRIBUTORS-BADGE:END -->

**MusicWalker** is a modern, sleek MP3 music player built with **Qt** and **SDL\_mixer**. It provides a clean and intuitive interface for playing your music files with an easy-to-use queue system.

-----

## Features

  * **MP3 Playback:** Supports playback of your MP3 audio files.
  * **Music Queue:** Easily manage your music with a robust queue system.
  * **Modern UI:** Enjoy a sleek, dark-themed interface.
  * **Responsive Design:** The interface adapts seamlessly to different window sizes.
  * **High-Quality Audio:** Delivers crisp, clear sound using **SDL\_mixer**.
  * **Memory-Efficient:** Designed for optimal performance with a lightweight playback engine.

-----

## Quick Start (Using Release)

Get MusicWalker up and running in no time\!

1.  Go to the [Releases]() page.
2.  Download the latest `MusicWalker-vX.X.X.zip` archive.
3.  Extract the ZIP file to your preferred location.
4.  Run `MusicWalker.exe`.

No installation is required – just extract and play\!

-----

## Build from Source

Want to build MusicWalker yourself? Here's how.

### Prerequisites

  * **Operating System:** Windows 10 or higher.
  * **MSYS2:** Installed to `C:\msys64`.
  * **Qt:** **Qt 5.5.1 (MinGW 32-bit version)**.
  * **CMake:** Version 3.15 or higher.
  * **Editor:** Visual Studio Code with C++ extensions (recommended).

### Setup Steps

1.  **Install MSYS2 Dependencies:**
    Open the **MSYS2 MINGW32 terminal** and run:

    ```powershell
    pacman -Syu
    pacman -S mingw-w64-i686-gcc mingw-w64-i686-ninja mingw-w64-i686-SDL2 mingw-w64-i686-SDL2_mixer
    ```

2.  **Set Up Qt:**

      * Install **Qt 5.5.1 MinGW 32-bit**.
      * Add the `bin` folder of your Qt installation to your system's **PATH** environment variable.

3.  **Clone & Build:**

    ```powershell
    git clone https://github.com/Shailesh-Singh-Bisht/MusicWalker
    cd MusicWalker
    mkdir build
    cd build
    cmake .. -G "MinGW Makefiles" 
    cmake --build .
    ```

4.  **Deploy:**
    From the `build` directory, run:

    ```powershell
    windeployqt MusicWalker/MusicWalker.exe
    ```

    This command collects all necessary Qt DLLs for distribution.

-----

## Project Structure

```
MusicWalker/
├── asset/              # Icons and resources
├── include/            # Header files
│   ├── AudioPlayer.h   # SDL_mixer audio interface
│   ├── MainWindow.h    # Main application window
│   ├── PlayerArea.h    # Music visualization area
│   ├── PlayerWidget.h  # Playback controls
│   └── QueueManager.h  # Music queue handling
├── src/                # Implementation files
├── CMakeLists.txt      # Build configuration
├── main.cpp            # Application entry point
└── resource.rc         # Windows resources
```

-----

## Key Files Explained

  * **`AudioPlayer`**: Manages MP3 playback using **SDL\_mixer**.
  * **`QueueManager`**: Handles the music playlist and playback history.
  * **`PlayerWidget`**: Contains all playback controls (play, pause, next, etc.).
  * **`PlayerArea`**: Displays information about the currently playing track.
  * **`MainWindow`**: The main application window responsible for overall coordination.

-----

## Development Notes

  * Utilizes **C++11** features for modern coding practices.
  * **Qt 5.5** powers the entire user interface.
  * **SDL2** and **SDL2\_mixer** are used for robust audio playback.
  * **CMake** simplifies the build configuration process.
  * Designed with a contemporary dark theme.

-----

## Building Tips

  * Ensure all paths in `CMakeLists.txt` correctly match your system setup.
  * The **SDL2** configuration is optimized for **MSYS2** paths.
  * For distributing your build, remember to use `windeployqt`.
  * Building in **Release** mode is recommended for final distribution.

-----

## Known Issues

  * Currently supports only **MP3** format.
  * The playback queue is not persistent between sessions.
  * Volume control is not available in the current version.

-----

## Contributing

We welcome contributions\! To contribute:

1.  Fork the repository.
2.  Create a new feature branch: `git checkout -b my-new-feature`.
3.  Commit your changes: `git commit -am 'Add some feature'`.
4.  Push to the branch: `git push origin my-new-feature`.
5.  Submit a pull request.

-----

## License

This project is licensed under the **MIT License** – see the `LICENSE` file for full details.

-----

## Acknowledgments

  * The **Qt Framework** team.
  * **SDL** and **SDL\_mixer** developers.
  * **MSYS2** project maintainers.
## Contributors ✨

Thanks goes to these wonderful people ([emoji key](https://allcontributors.org/docs/en/emoji-key)):

<!-- ALL-CONTRIBUTORS-LIST:START - Do not remove or modify this section -->
<!-- prettier-ignore-start -->
<!-- markdownlint-disable -->
<table>
  <tbody>
    <tr>
      <td align="center" valign="top" width="14.28%"><a href="https://github.com/Vivek-Pokhriyal"><img src="https://avatars.githubusercontent.com/u/202429019?v=4?s=100" width="100px;" alt="Vivek-Pokhriyal"/><br /><sub><b>Vivek-Pokhriyal</b></sub></a><br /><a href="https://github.com/Shailesh-Singh-Bisht/MusicWalker/commits?author=Vivek-Pokhriyal" title="Code">💻</a></td>
      <td align="center" valign="top" width="14.28%"><a href="https://shailesh-singh-bisht-portfolio.vercel.app/"><img src="https://avatars.githubusercontent.com/u/107263955?v=4?s=100" width="100px;" alt="Shailesh Singh Bisht"/><br /><sub><b>Shailesh Singh Bisht</b></sub></a><br /><a href="#design-Shailesh-Singh-Bisht" title="Design">🎨</a> <a href="#maintenance-Shailesh-Singh-Bisht" title="Maintenance">🚧</a></td>
      <td align="center" valign="top" width="14.28%"><a href="https://github.com/Akhilnautiyal5"><img src="https://avatars.githubusercontent.com/u/113812781?v=4?s=100" width="100px;" alt="Akhil Nautiyal"/><br /><sub><b>Akhil Nautiyal</b></sub></a><br /><a href="https://github.com/Shailesh-Singh-Bisht/MusicWalker/commits?author=Akhilnautiyal5" title="Code">💻</a></td>
    </tr>
  </tbody>
  <tfoot>
    <tr>
      <td align="center" size="13px" colspan="7">
        <img src="https://raw.githubusercontent.com/all-contributors/all-contributors-cli/1b8533af435da9854653492b1327a23a4dbd0a10/assets/logo-small.svg">
          <a href="https://all-contributors.js.org/docs/en/bot/usage">Add your contributions</a>
        </img>
      </td>
    </tr>
  </tfoot>
</table>

<!-- markdownlint-restore -->
<!-- prettier-ignore-end -->

<!-- ALL-CONTRIBUTORS-LIST:END -->

This project follows the [all-contributors](https://github.com/all-contributors/all-contributors) specification. Contributions of any kind welcome!