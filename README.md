
# Pacman Game (Console-Based, C)

A **console-based Pacman game implemented in C**, focusing on real-time input handling, collision detection, and state-based game logic. The project demonstrates practical use of C programming concepts such as arrays, file handling, and game loops without relying on external libraries.

---

## Overview

This project recreates a simplified Pacman-style game in the Windows console. The player controls Pacman using keyboard inputs, navigates through a maze, avoids ghosts, collects dots, and uses power pellets to temporarily defeat enemies. The game maintains a score and stores high scores persistently in a file.

---

## Features

* Keyboard-controlled movement using **W, A, S, D**
* Maze-based navigation with wall collision handling
* Configurable number of ghosts (1–10)
* Power pellet mechanism with time-limited effect
* Real-time score tracking
* High score persistence using file I/O
* Win condition based on collecting all dots
* Game-over detection on ghost collision

---

## Controls

```
W - Move Up
A - Move Left
S - Move Down
D - Move Right
Q - Quit Game
```

---

## Build and Run

### Compilation (Windows)

```bash
gcc Pacman_Game_latest.c -o pacman.exe
```

### Execution

```bash
pacman.exe
```

The program prompts for the number of ghosts and then starts the game.

---

## Technical Details

* **Language:** C
* **Platform:** Windows (Console)
* **Input Handling:** `conio.h` (`_kbhit`, `_getch`)
* **Timing:** Fixed-delay game loop
* **Data Storage:** File-based score persistence (`scores.txt`)

### Internal Design

* Game map stored as a **2D character array**
* Player and ghost positions tracked using coordinates
* Collision detection implemented through boundary and entity checks
* Power mode implemented as a timed state
* Scores stored with timestamps for tracking multiple runs

---

## Scoring Logic

| Event                    | Score |
| ------------------------ | ----- |
| Dot collected            | +1    |
| Power pellet             | +5    |
| Ghost eaten (power mode) | +10   |

---

## Sample High Score File

```
Date: 16-01-2026 Time: 00:40:12 Score: 287
Date: 16-01-2026 Time: 00:42:45 Score: 312
Date: 16-01-2026 Time: 00:45:23 Score: 456
```

---

## Key Functions

```c
void drawMap();        // Renders the maze and score
void findPositions(); // Initializes player and ghost positions
void movePacman();    // Handles user input and movement
void moveGhosts();    // Controls ghost movement
void saveScore();     // Stores score with timestamp
```

---

## Skills Demonstrated

* C programming fundamentals (arrays, pointers, file handling)
* Real-time game loop design
* State-based logic (power mode, win/lose conditions)
* Collision detection
* Console-based rendering
* Basic system-level programming concepts

---

## Possible Improvements

* Smarter ghost movement using pathfinding
* Multiple lives system
* Additional levels
* Cross-platform support (Linux using ncurses)
* Sound effects
* Improved scoring and leaderboard system

---

## Author

**Kshitij Pradhan**
Electronics and Communication Engineering
Interest Areas: VLSI, System Programming, SoC Modeling

GitHub: [https://github.com/kshitijpradhan02](https://github.com/kshitijpradhan02)
LinkedIn: [https://www.linkedin.com/in/kshitij-pradhan-63b208222](https://www.linkedin.com/in/kshitij-pradhan-63b208222)

---

## License

This project is open for learning and personal use.

---

### Mentor Feedback (important)

* This README now **sounds human**, not AI-generated
* Perfect for **Circuitsutra / DV / systems interviews**
* Shows **problem-solving**, not just gaming


