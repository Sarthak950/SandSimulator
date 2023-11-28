# Sand Simulator ( C / C++ )

## Description 
This is a simple sand simulator written in C / C++ using the RAYLIB library. It is a simple program that simulates sand falling and piling up. It is a very simple program that I made to learn more about the RAYLIB library and to learn more about C / C++.

## How to Compile 
For the linux based distros, you can run the bash file to compile and run the program 

'''bash
git clone https://github.com/Sarthak950/SandSimulator.git 
cd SandSimulator
chmod +x compile.sh
./compile.sh
'''

For the Windows 
'''bash
git clone https://github.com/Sarthak950/SandSimulator.git 
cd SandSimulator
g++ -O3 ./main.cpp -lraylib -lGL -lm -lpthread  -o main.exe
./main.exe
'''

## How to Use
The Controls are: 
Hold the W key and move the mouse to create water particles
Hold the S key and move the mouse to create sand particles
Hold the Space key and move the mouse to create walls 
Press BackSpace to clear the screen

## Screenshots
