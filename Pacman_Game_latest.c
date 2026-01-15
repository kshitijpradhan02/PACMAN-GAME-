#include <stdio.h>
#include <stdlib.h> // to generate random function  
#include <conio.h> // to take keybord input 
#include <windows.h> // add time delay between different modes 
#include <time.h> //get score time in .txt file 

#define ROWS 15
#define COLS 25
#define MAX_GHOSTS 10

char map[ROWS][COLS + 1] =
{
    "########################",
    "#...O...#.......#.....#",
    "#.####...#...#...#..#.#",
    "#.#  #.......#.....##.#",
    "#.#..#####.#####.##..O#",
    "#......#.......#....#.#",
    "#.####.#.#####.#.##.#.#",
    "#P.....#........#....#.#",
    "#.###.####.#####.###.#O",
    "#.....#.............#..#",
    "#.###.#.###########.#..#",
    "#.....#.....#.......#..#",
    "#.#########.###.#####..#",
    "#.........#.....#......#",
    "########################"
};

int score = 0;
int totalDots = 0; // Baits for pacman 
int px, py;
int gx[MAX_GHOSTS]; // Enemy of Pacman 
int gy[MAX_GHOSTS];
int GHOST_COUNT;


int powerMode = 0;
int powerTimer = 0;

void drawMap()
{
    system("cls"); // enhance map location and clarity 
    for (int i = 0; i < ROWS; i++)
    {
        printf("%s\n", map[i]);
       
    }
     printf(" 12345678");
    printf("\nScore: %d\n", score);
    if (powerMode) //  Note : if char ='O' optimiser if will get value 1 here 
    {
        printf("POWER MODE ACTIVE! Ghosts are edible!\n");
    }
    printf("Use W A S D to move, Q to quit\n"); //keyboard control keys 
    
}

void findPositions()
{
    totalDots = 0;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (map[i][j] == 'P')
            {
                px = i; // placing pacman  at char P 
                py = j;
            }
            else if (map[i][j] == '.')
                totalDots++; // Counting dots of Pacman to eat 
        }
    }


    for (int i = 0; i < GHOST_COUNT; i++)
    {
        int x, y;
        do
        {
            x = rand() % ROWS; // ghost x coordinate 
            y = rand() % COLS; // ghost y coordinate 
        }
        while (map[x][y] != ' ' && map[x][y] != '.');
        gx[i] = x;
        gy[i] = y;
        map[x][y] = 'G'; //assigning ghost at random place onto 2D Map 
    }
}

void movePacman(char dir)
{
    int nx = px, ny = py;
    if (dir == 'w')
     nx--; // up 
    else if (dir == 's') 
    nx++; //down 
    else if (dir == 'a') 
    ny--; //left 
    else if (dir == 'd') 
    ny++; // right 

    if (map[nx][ny] == '#')
        return;

    if (map[nx][ny] == '.')
      
    {
        score++;
        totalDots--;
    }

    if (map[nx][ny] == 'O')
    {
        powerMode = 1;
        powerTimer = 50;
        score += 5;
    }

    map[px][py] = ' ';
    px = nx;
    py = ny;
    map[px][py] = 'P';
}

void moveGhosts()
{
    for (int i = 0; i < GHOST_COUNT; i++)
    {
        int dir = rand() % 4;
        int nx = gx[i], ny = gy[i];

        if (dir == 0) 
        nx--; // move ghost upwards 
        else if (dir == 1) 
        nx++; // move ghost downwards 
        else if (dir == 2) 
        ny--; //move  ghost left 
        else if (dir == 3) 
        ny++; // move ghost right 

        if (map[nx][ny] == '#' || map[nx][ny] == 'G' || map[nx][ny] == 'B')
            continue; // skip and move ghost to next random space in map 

        map[gx[i]][gy[i]] = ' ';
        gx[i] = nx;
        gy[i] = ny;
        map[gx[i]][gy[i]] = powerMode ? 'B' : 'G'; // changing of char in case of eating 'O'
    }
}

void saveScore(int finalScore)
{
    FILE *fp = fopen("scores.txt", "a"); //open in append mode here to add new scores 
    if (fp == NULL)
    {
        perror("Error opening score file");
        return;
    }

    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    fprintf(fp, "Date: %02d-%02d-%04d  Time: %02d:%02d:%02d  Score: %d\n", // local time 
            t->tm_mday, t->tm_mon + 1, t->tm_year + 1900,
            t->tm_hour, t->tm_min, t->tm_sec, finalScore);
    fclose(fp);
    printf("\nYour score has been saved to 'scores.txt'.\n");
}

int main()
{
    srand(time(NULL)); // change plot everytime 

    printf("Enter number of ghosts (1-%d): ", MAX_GHOSTS);
    scanf("%d", &GHOST_COUNT);
    if (GHOST_COUNT < 1 || GHOST_COUNT > MAX_GHOSTS) 
        GHOST_COUNT = 5; // check entered ghost number 

    findPositions();

    while (1)
    {
        drawMap();

        if (totalDots == 0)
        {
            printf("\nYOU WIN! Score: %d\n", score); 
            saveScore(score);
            break;
        }

        for (int i = 0; i < GHOST_COUNT; i++)
        {
            if (px == gx[i] && py == gy[i])
            {
                if (powerMode)  // two possible cases
                {
                    score += 10;
                    map[gx[i]][gy[i]] = ' ';
                    gx[i] = rand() % ROWS;
                    gy[i] = rand() % COLS;
                }
                else  // no O eaten by pacman 
                {
                    printf("\nGAME OVER! A ghost caught you!\n");
                    saveScore(score);
                    goto END;
                }
            }
        }

        if (_kbhit()) 
        {         
            char ch = _getch();
            if (ch == 'q')
            {
                printf("\nYou quit the game. Final Score: %d\n", score);
                saveScore(score);
                goto END;
            }
            movePacman(ch);
        }

        moveGhosts();

        if (powerMode)
        {
            powerTimer--; // clock ticking back to 0 
            if (powerTimer <= 0)
            {
                powerMode = 0;
                for (int i = 0; i < GHOST_COUNT; i++)
                    map[gx[i]][gy[i]] = 'G';
            }
        }

        Sleep(200);
    }

END:
    printf("\nThanks for playing!\n");
    return 0;
}
