

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include "util.h"

#define MAP_WIDTH 19
#define MAP_HEIGHT 17
#define MAX_LENGTH 255


#define LEFT		75
#define RIGHT		77
#define UP			72
#define DOWN		80
#define ESC			27


int key = 0;
int snakeX[323], snakeY[323];
int length;
int dir;
int game_speed;
int foodX, foodY;
int isStart;
int score = 0;

void KeyProcess() {
    int key = 0;
    if (_kbhit())
    {
        isStart = 1;
        key = _getch();
        if (key == 224)
        {
            key = _getch();
            switch (key) {
            case LEFT:
                if ((dir == LEFT && key != RIGHT) ||
                    (dir == RIGHT && key != LEFT) ||
                    (dir == UP && key != DOWN) ||
                    (dir == DOWN && key != UP)) {
                    dir = key;
                }
                else {
                    
                }
                
                break;
            case RIGHT:
                if ((dir == LEFT && key != RIGHT) ||
                    (dir == RIGHT && key != LEFT) ||
                    (dir == UP && key != DOWN) ||
                    (dir == DOWN && key != UP)) {
                    dir = key;
                }
                else {

                }
                break;
            case UP:
                if ((dir == LEFT && key != RIGHT) ||
                    (dir == RIGHT && key != LEFT) ||
                    (dir == UP && key != DOWN) ||
                    (dir == DOWN && key != UP)) {
                    dir = key;
                }
                else {

                }
                break;
            case DOWN:
                if ((dir == LEFT && key != RIGHT) ||
                    (dir == RIGHT && key != LEFT) ||
                    (dir == UP && key != DOWN) ||
                    (dir == DOWN && key != UP)) {
                    dir = key;
                }
                else {

                }
                break;
            }
        }
    }
}

void ClearMap() {
    for (int y = 1; y < MAP_HEIGHT - 1; y++) {
        for (int x = 1; x < MAP_WIDTH - 1; x++) {
            gotoxy(x, y);
            printf("  ");
        }
    }
    gotoxy(0, 19);
    printf("         ");
    gotoxy(0, 20);
    printf("                                                                              ");
}

void Initialize() {
    game_speed = 500;
    dir = RIGHT;
    isStart = 0;
    length = 4;
    score = 0;
    snakeX[0] = MAP_WIDTH / 2 - 4;
    snakeY[0] = MAP_HEIGHT / 2;
    gotoxy(snakeX[0], snakeY[0]);
    printf("★");
    for (int i = 1; i < length; i++)
    {
        snakeX[i] = snakeX[0] - i;
        snakeY[i] = snakeY[0];
        gotoxy(snakeX[i], snakeY[i]);
        printf("□");
    }
    foodX = MAP_WIDTH / 2;
    foodY = MAP_HEIGHT / 2;
    gotoxy(foodX, foodY);
    printf("♣");
}

int map[MAP_HEIGHT][MAP_WIDTH] = {
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void DrawMap() {
    for (int x = 0; x < MAP_WIDTH; x++)
    {
        gotoxy(x, 0);
        printf("▩");
        gotoxy(x, MAP_HEIGHT - 1);
        printf("▩");
    }
    for (int y = 0; y < MAP_HEIGHT; y++)
    {
        gotoxy(0, y);
        printf("▩");
        gotoxy(MAP_WIDTH - 1, y);
        printf("▩");
    }
    /*for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            gotoxy(x, y);
            if (map[y][x] == 1)
                printf("▩");
            else
                printf("  ");
        }
    }*/

    //똑같이 그리지만 규칙을 찾아 명령 실행수가 훨씬 적은 방법
}

void MoveSnake() {
    gotoxy(snakeX[0], snakeY[0]);
    printf("□");
    gotoxy(snakeX[length - 1], snakeY[length - 1]);
    printf("  ");
    for (int i = length - 1; i > 0; i--) {
        snakeX[i] = snakeX[i - 1];
        snakeY[i] = snakeY[i - 1];
    }
    switch (dir) {
    case LEFT:
        snakeX[0]--;
        break;
    case RIGHT:
        snakeX[0]++;
        break;
    case UP:
        snakeY[0]--;
        break;
    case DOWN:
        snakeY[0]++;
        break;
    }
    gotoxy(snakeX[0], snakeY[0]);
    printf("★");
}


void MakeFood() {
    bool isTry;
    do {
        isTry = false;
        foodX = (rand() % (MAP_WIDTH - 2)) + 1;
        foodY = (rand() % (MAP_HEIGHT - 2)) + 1;
        for (int i = 0; i < length; i++) {
            if (foodX == snakeX[i] && foodY == snakeY[i]) {
                isTry = true;
                break;
            }
        }
    } while (isTry == true);
    gotoxy(foodX, foodY);
    printf("♣");
    
}

void GameProcess() {
    if (snakeX[0] == foodX && snakeY[0] == foodY) {
        length++;
        score++;
        snakeX[length] = snakeX[length - 1];
        snakeY[length] = snakeY[length - 1];
        game_speed -= 20;
        if (game_speed < 100) {
            game_speed = 100;
            
        }
        MakeFood();
    }
    gotoxy(0, 18);
    printf("Score : %d\n", score);
    if (snakeX[0] <= 0 || snakeX[0] >= MAP_WIDTH - 1 ||
        snakeY[0] <= 0 || snakeY[0] >= MAP_HEIGHT - 1)
    {
        gotoxy(0, 19);
        printf("Game Over\n");
        system("pause");
        ClearMap();
        Initialize();
    }
    for (int i = 1; i < length; i++)
    {
        if (snakeX[0] == snakeX[i] && snakeY[0] == snakeY[i])
        {
            gotoxy(0, 19);
            printf("Game Over\n");
            system("pause");
            ClearMap();
            Initialize();
            
        }
    }
}

int main()
{
    
    setcursortype(NOCURSOR);
    Initialize();
    while (true) {
        DrawMap();
        KeyProcess();
        if (isStart == 0) {
            continue;
        }
        GameProcess();
        MoveSnake();
        Sleep(game_speed);
    }
    

   

}

