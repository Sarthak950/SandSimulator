
# Sand Simulator ( C / C++ )

## Description 
This is a simple sand simulator written in C / C++ using the RAYLIB library. It is a simple program that simulates sand falling and piling up. It is a very simple program that I made to learn more about the RAYLIB library and to learn more about C / C++.

## How to Compile 
For the linux based distros, you can run the bash file to compile and run the program 

``` bash
git clone https://github.com/Sarthak950/SandSimulator.git 
cd SandSimulator
chmod +x compile.sh
./compile.sh
```

For the Windows 
``` bash
git clone https://github.com/Sarthak950/SandSimulator.git 
cd SandSimulator
g++ -O3 ./main.cpp -lraylib -lGL -lm -lpthread  -o main.exe
./main.exe
```

## How to Use
The Controls are: 
Hold the W key and move the mouse to create water particles
Hold the S key and move the mouse to create sand particles
Hold the Space key and move the mouse to create walls 
Press BackSpace to clear the screen

### Note 
For contribution please open a pull request and I will review it.
1. Fire, Lava Particle 
2. Gas particles
Thanks.

## Screenshots
https://github.com/Sarthak950/SandSimulator/assets/93645760/38356dd4-7fa5-497e-bc29-876f4b17d03c

![231128_08-54-37](https://github.com/Sarthak950/SandSimulator/assets/93645760/1c25fbb0-b6f9-4b54-9bfa-fc8c34d95159)

![231128_08-55-29](https://github.com/Sarthak950/SandSimulator/assets/93645760/d81c5214-a326-4b1b-98b4-bccf720984f8)

![231128_08-57-33](https://github.com/Sarthak950/SandSimulator/assets/93645760/8c123f4b-d5bd-4b58-ae40-3b1eb0d82633)

