# Snake C++

<div align="center">
    <img src="https://drive.google.com/uc?export=download&id=1c7Hx_bf5FCJ5GIVVmZxw7asXJ7AM1JRn" width="40%">
</div>

### A full implementation of the Snake game using C++.

- Full Object Oriented Design
- Array List with objects for body and food positions
- Memory Safe
- Follows Standards

## Features

- Normal Snake Gameplay
- 'X' Food is bad. Increases length by 3, and score by 1.
- '$' Food is good. Does not increase length, but does increase score by 10.
- 'o' Normal food, increases both length and score by 1.

## Usage

You can run the provided `Project.exe`.

Alternatively, you can build the program. First, ensure you have the GCC compiler setup correctly.
Then, build the program using `make`. You can delete the object files/executables using `make clean`.

Currently, the makefile and MacUILib.h is configured for Windows. To run on Mac:
- Uncomment line 5 in the makefile, the POSTLINKER.
- Comment out line 4 in MacUILib.h and uncomment line 5.

<hr>

Created for COMPENG 2SH4 at McMaster
