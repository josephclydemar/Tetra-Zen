# Tetra Zen
`Tetra Zen` is a desktop app implementation of the classic Tetris game, writen in C and [Raylib](https://github.com/raysan5/raylib). This desktop application offers a minimalist design and soothing audio experience, providing a serene and engaging environment for players to enjoy the timeless challenge of block placement.

<br>

### Building on Windows
To build on Windows, you will need to have **GCC** and **Make** installed.      

#### MinGW-W64/GCC
**MinGW-W64/GCC** is an open-source toolchain for C/C++ that includes **GCC** and **Make**. The recommended method for obtaining **MinGW-W64/GCC** is through the [W64Devkit](https://github.com/skeeto/w64devkit/). Download the **W64Devkit** zip file, extract it, and execute `W64Devkit.exe` to access a pre-configured terminal.              

#### Clone the Repository
```
git clone git@github.com:josephclydemar/Tetra-Zen.git
cd Tetra-Zen
```

#### Build
```
make
```

<br>


### Building on Linux/Ubuntu
On Linux/Ubuntu systems, **GCC** and **Make** are typically pre-installed, so no additional installation is necessary.      

#### Clone the Repository
```
git clone git@github.com:josephclydemar/Tetra-Zen.git
cd Tetra-Zen
```

#### Build
```
make
```

<br>
<br>
<br>

### Usage
#### Open the Game Window
```
make run
```

#### Game Controls
- Press the `A` key to rotate the brick counter-clockwise.
- Press the `D` key to rotate the brick clockwise.
- Press the `LEFT` key to move left the brick normally.
- Press the `RIGHT` key to move right the brick normally.
- Press the `Z` key to move left fast the brick.
- Press the `C` key to move right fast the brick.
- Press the `SPACE` key to make the brick drop fast.




