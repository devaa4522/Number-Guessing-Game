# 🎲 Number Guessing Game (CLI — C++17)

> Project idea on roadmap.sh  
> https://roadmap.sh/projects/number-guessing-game

A tiny command-line game written in modern **C++17**.  
The computer secretly picks a number between **1** and **100**; you try to guess it within a limited number of attempts that depends on the selected difficulty level.

---

## Features
* Three difficulty levels  
  * Easy – 10 guesses  
  * Medium – 5 guesses  
  * Hard – 3 guesses
* “Higher / Lower” feedback after each wrong guess
* Win / lose detection with replay prompt
* Pure standard-library code — no external dependencies
* Uses C++’s `<random>` facilities in `get_random()` for stronger randomness than the old `rand()` API

---

## Quick Demo
=== Welcome to the Number Guessing Game! ===
Select the difficulty level:

Easy (10 tries)

Medium (5 tries)

Hard (3 tries)
Enter choice: 2

You have 5 tries to guess the secret number (1-100).

Enter your guess: 50
Lower than the secret number. 4 tries left.

Enter your guess: 25
Higher than the secret number. 3 tries left.

Enter your guess: 30
🎉 Congratulations! You guessed it in 3 attempts.

Play again? (y/n): n
Thanks for playing!


---

## Build Instructions

### Requirements
* C++17-capable compiler  
  * **Windows** – MSVC (Visual Studio 2022 / Build Tools) or MinGW-w64 (`g++`)  
  * **Linux / macOS** – `g++` or `clang++`

### One-liner builds

| Platform | Command |
|----------|---------|
| GCC / Clang | `g++ -std=c++17 -Wall -O2 main.cpp -o guess` |
| MSVC (Dev Cmd Prompt) | `cl /std:c++17 /W4 /EHsc /O2 main.cpp` |
| CMake | `cmake -S . -B build -DCMAKE_BUILD_TYPE=Release && cmake --build build` |

> **Tip:** Close any running **guess.exe** before rebuilding to avoid a *permission denied* linker error on Windows.

---

## Usage
./guess # Windows: .\guess.exe

---

## Key Source-Code Highlights
// Ask for difficulty
int difficulty();

// Better random number generator
int get_random() {
static std::random_device rd;
static std::mt19937 gen(rd()); // Mersenne Twister engine
static std::uniform_int_distribution<int> dist(1, 100);
return dist(gen);
}

// Main game loop
void play() { /* ... */ }

int main() {
std::cout << "=== Welcome to the Number Guessing Game! ===\n\n";
char again;
do {
play();
std::cout << "Wanna play again (y/n): ";
std::cin >> again;
} while (again == 'y' || again == 'Y');
}

---

## Project Layout
.
├─ main.cpp # complete game source
└─ README.md


---

## Roadmap / Ideas
* Persistent scoreboard (wins / losses stored in a file)  
* Input validation for non-numeric data  
* “Warm / Cold” hints based on distance  
* Unit tests with Catch2  
* GUI port (Qt / ImGui) or WebAssembly build  

Contributions are welcome!

---

## License
Released under the MIT License. See `LICENSE` for details.

Happy guessing! 🎉
