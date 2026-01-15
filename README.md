# PACMAN-GAME-
Console Pacman in C:  WASD controls, ghosts, power pellets, scoring &amp; high score persistence. Real-time game loop with collision detection. Zero deps.
# 🕹️ Pacman Game in C - Professional README.md


```markdown
# 🕹️ Pacman Game in C

A fully functional **console-based Pacman clone** built entirely in C. Features classic gameplay with configurable ghosts, power pellets, real-time scoring, and persistent high score tracking.

![Pacman Gameplay](screenshots/pacman-gameplay.gif)
*Add gameplay GIF/screenshot here*

## ✨ Core Features

- **Classic Pacman mechanics** - WASD movement in 15×25 maze
- **Configurable ghosts** - 1-10 enemies with random AI movement
- **Power pellet system** - Eat 'O' pellets to turn ghosts edible (50-move duration)
- **Persistent high scores** - Automatically saved to `scores.txt` with timestamps
- **Real-time collision detection** - Wall blocking, ghost interactions
- **Win condition** - Eat all dots to complete the level

## 🎮 How to Play

```
Controls:
W 🡩 Up     A 🡠 Left      Score: Dots(+1) | Power(+5) | Ghost(+10)
S 🡫 Down   D 🡢 Right     Q - Quit Game
```

**Quick Start:**
```bash
gcc Pacman_Game_latest.c -o pacman.exe
./pacman.exe
```
Enter ghost count (1-10), then navigate maze!

## 🏗️ Technical Implementation

```
Game Architecture:
├── 15×25 char map[#walls .dots O power pellets P pacman]
├── Pacman position (px, py) + Ghost array(gx[], gy[])
├── 200ms game loop with non-blocking input (_kbhit/_getch)
├── Power mode state machine (50-move timer)
├── File I/O for timestamped scores (scores.txt)
└── Collision detection + boundary validation
```

## 📊 Game Mechanics Table

| Feature | Implementation | Points |
|---------|---------------|--------|
| **Movement** | WASD → collision check | - |
| **Dots (.)** | `score++`, `totalDots--` | +1 |
| **Power (O)** | `powerMode=1`, timer=50 | +5 |
| **Ghost (G)** | Normal: Game Over<br>Power: Respawn | +10 |
| **Win** | `totalDots == 0` | Victory! |

## 🔨 Build & Dependencies

```bash
# Windows (MinGW/GCC)
gcc Pacman_Game_latest.c -o pacman.exe
./pacman.exe

# Dependencies: stdio.h, stdlib.h, conio.h, windows.h, time.h
# Zero external libraries required!
```

## 📈 Sample scores.txt Output
```
Date: 16-01-2026 Time: 00:40:12 Score: 287
Date: 16-01-2026 Time: 00:42:45 Score: 312
Date: 16-01-2026 Time: 00:45:23 Score: 456
```

## 💻 Code Structure

```c
// Core Functions (600+ lines)
void drawMap()        // Console rendering + score display
void findPositions()  // Initialize Pacman + ghosts
void movePacman()     // WASD collision logic
void moveGhosts()     // Random walk AI
void saveScore()      // Timestamp persistence
```

## 🎯 Skills Demonstrated

✅ **C Programming**: 2D arrays, file I/O, pointers, structs  
✅ **Game Development**: Game loops, collision detection, state machines  
✅ **Systems Programming**: Real-time input, console rendering  
✅ **Algorithm Design**: Random movement, scoring logic  
✅ **Windows API**: `conio.h` non-blocking input  

## 🚀 Future Enhancements

```markdown
- [ ] A* pathfinding ghost AI
- [ ] Multiple lives system  
- [ ] Progressive levels
- [ ] Cross-platform (ncurses)
- [ ] Sound effects (Beep API)
- [ ] Online leaderboard
```

## 👨‍💻 Author

**ECE/CSE Engineering Student**  
📍 **Ghaziabad, Uttar Pradesh**  
🔬 **Focus**: VLSI | Embedded Systems | SOC Design  
💼 **Seeking**: Circuitsutra SOC Modelling Internship

**Portfolio**: [GitHub](https://github.com/YOUR_USERNAME)  
**LinkedIn**: [Your Profile](https://linkedin.com/in/yourprofile)

## 📄 License

MIT License - Free to use, modify, distribute.

---

⭐ **Star if helpful!** 🐛 **Issues welcome!**
```

## Quick GitHub Setup

```bash
# In your project folder
echo "# Pacman Game" > README.md
# Paste the above content
git add README.md Pacman_Game_latest.c
git commit -m "Add Pacman C game + professional README"
git push
```

## Pro Tips
1. **Record 10-sec gameplay** → `screenshots/pacman.gif`
2. **Create `.gitignore`**:
```
*.exe
scores.txt
```
3. **Add topics**: `c, pacman, game-development, console-game`

**This README is recruiter-ready for Circuitsutra!** 🎮✨ [ppl-ai-file-upload.s3.amazonaws](https://ppl-ai-file-upload.s3.amazonaws.com/web/direct-files/attachments/91432622/3bcef75b-7fe9-4612-87e5-17122aab7eea/Pacman_Game_latest.c)
