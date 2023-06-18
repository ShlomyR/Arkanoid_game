# Arkoined Brick Style Game

Arkoined Brick Style Game is a classic arcade game inspired by the popular brick-breaking games of the past. The objective of the game is to control a paddle and use it to bounce a ball, breaking bricks that are arranged in various patterns. The player must aim to clear all the bricks on the screen while preventing the ball from falling off the bottom of the screen.

## Features

- Intuitive paddle control using keyboard.
- Physics-based ball movement and collision detection.
- Different types of bricks with varying point values.
- 3 levels with increasing difficulty.
- Score tracking and high score leaderboard.
- Sound effects and visual effects for an immersive experience.

## Installation

### Linux OS:
1. Clone the repository.
    * 1.1. if you don't have Cmake installed:
    ```sh
    sudo apt update
    sudo apt install cmake
    ```
2. Compile the source code using a Cmake.
3. In the terminal run "cmake .".
4. Then run "make".
5. Then "./main' enjoy!!!.

### Mac OS:
1. Clone the repository.
    * 1.1. if you don't have brew installed install it by using the following command:
     ```sh
    /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
    ```
    * 1.2. to install Cmake using brew:
     ```sh
    brew install cmake
    ```
    
2. Compile the source code using a Cmake.
3. In the terminal run "cmake .".
4. Then run "make".
5. Then "./main" enjoy!!!.

if you have an error of - `We got a Keyboard without any keys (1)` .

to fix it go to `System Setting`-->`Privacy & Security`-->`Input Monitoring` and allow your application in this section for example: `IDE VS code`.

# Arkoined Brick Style Game

Arkoined Brick Style Game is a classic arcade game inspired by the popular brick-breaking games of the past. The objective of the game is to control a paddle and use it to bounce a ball, breaking bricks that are arranged in various patterns. The player must aim to clear all the bricks on the screen while preventing the ball from falling off the bottom of the screen.

## Features

- Intuitive paddle control using keyboard.
- Physics-based ball movement and collision detection.
- Different types of bricks with varying point values.
- 3 levels with increasing difficulty.
- Score tracking and high score leaderboard.
- Sound effects and visual effects for an immersive experience.

## Installation

### Linux OS:
1. Clone the repository.
    * 1.1. if you don't have Cmake installed:
    ```sh
    sudo apt update
    sudo apt install cmake
    ```
2. Compile the source code using a Cmake.
3. In the terminal run "cmake .".
4. Then run "make".
5. Then "./main' enjoy!!!.

### Mac OS:
1. Clone the repository.
    * 1.1. if you don't have brew installed install it by using the following command:
     ```sh
    /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
    ```
    * 1.2. to install Cmake using brew:
     ```sh
    brew install cmake
    ```
    
2. Compile the source code using a Cmake.
3. In the terminal run "cmake .".
4. Then run "make".
5. Then "./main" enjoy!!!.

if you have an error of - `We got a Keyboard without any keys (1)` .

to fix it go to `System Setting`-->`Privacy & Security`-->`Input Monitoring` and allow your application in this section for example: `IDE VS code`.

### Windows OS:
1. Clone the repository.
    * 1.1. if you don't have Cmake installed:
    To install CMake on Windows, you can follow these steps:

        1.2. Visit the CMake download page: https://cmake.org/download/.

        1.3. Scroll down to the "Binary distributions" section and find the "Windows" subsection.

        1.4. Download the "Windows win64-x64 Installer" if you have a 64-bit Windows installation.If you have a 32-bit Windows installation, download the "Windows win32-x86 Installer".

        1.5. Run the downloaded installer.

        1.6. In the installer, select the "Add CMake to the system PATH for all users" option. This will allow you to use CMake from any directory in the command prompt.

        1.7. Choose the installation directory for CMake. The default location is usually fine.

        1.8. Click "Next" to proceed with the installation.
        
        1.9. On the next screen, you can optionally choose to create desktop and start menu shortcuts for CMake.

        1.10. Click "Install" to start the installation process.

        1.11. Once the installation is complete, you can click "Finish" to exit the installer.

        After installing CMake, you can verify that it is correctly installed by opening a command prompt and running the following command:
        ```sh
        cmake --version
        ```
2. download the latest version of `boost` from here - https://www.boost.org .
3. download the GCC 7.3.0 MinGW `(SEH)` - 64-bit version of `sfml` from here - https://www.sfml-dev.org/download/sfml/2.5.1 .
4. download the `msys2` from here - https://www.msys2.org .
5. create a folder in c drive by the name `lib` - (C:/lib).
6. move all the files you download to there .
7. extract the files and install msys2.
8. after finish go to the directory `C:/msys64`
9. pressed on msys2 exe file and run the following command:
    ```sh
    pacman -Syu
    ```
    after it will close the terminal. open again the msys2 exe and run the following command:
    ```sh
    pacman -Su
    ``` 
    after put this command:
    ```sh
    pacman -S --needed base-devel mingw-w64-x86_64-toolchain
     ```
    in `Enter a selection (default=all)` just pressed enter.
    and then `y`.
    also when finish put this in the terminal `pacman -S mingw-w64-x86_64-boost`
10. close terminal when finished then go to boost folder that you extracted in lib folder and pressed on bootstrap wait until it finished
    then pressed om the b2 file wait until it finished (taking like 5-10 min) it will add a folder by the name stage.
    ```sh

    ```
11. now to the fun part of using windows (not really :\ ) :
    in windows 10 pressed on the search from the bottom bar and type `edit environment variables for your account`
    on the above section pressed double click on `Path`.
    pressed on the `new` button and add the directory `C:\msys64\mingw64\bin`
    and also pressed on the `new` button again and add the directory `C:\lib\SFML-2.5.1\bin`
    and also pressed on the `new` button again and add the directory `C:\lib\SFML-2.5.1\include`
    and also pressed on the `new` button again and add the directory `C:\lib\Boost-1_82_0\stage\lib\cmake\boost_filesystem-1.82.0`
    and also pressed on the `new` button again and add the directory `C:\lib\Boost-1_82_0\stage\lib`
    and also pressed on the `new` button again and add the directory `C:\lib\Boost-1_82_01`
12. In the terminal run `cmake -G "MinGW Makefiles" .` .
13. Then run `mingw32-make` .
14. Then `.\main` enjoy!!!.

## Usage

- Use the left and right arrow keys to control the paddle.
- Launch the ball by pressing the spacebar.
- Bounce the ball off the paddle to break the bricks.
- Clear all the bricks to advance to the next level.
- Avoid letting the ball fall off the bottom of the screen.
- Aim for a high score and try to beat your previous records.


## License

Arkoined Brick Style Game is released under the [MIT License](LICENSE).

## Acknowledgements

This game was developed using the SFML library (Simple and Fast Multimedia Library). Special thanks to the SFML community for their contributions and support.

## Contact

For any questions, suggestions, or issues, please contact rshlomy@gmail.com.

