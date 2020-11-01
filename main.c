#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

#define HEIGHT 25
#define WIDTH 25
#define SIZE 25

int maze[HEIGHT][WIDTH];
int posX = 1, posY = 1;

void updateMaze(HANDLE, WORD);

int main(void){
    /* color setup deaznam*/
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    for(int i=0;i<SIZE;i++){
        maze[i][0] = 1;
        maze[i][WIDTH-1] = 1;
        maze[0][i] = 1;
        maze[HEIGHT-1][i] = 1;
    }
    maze[posX][posY] = 2;
    maze[4][13] = 1;
    updateMaze(hConsole, saved_attributes);
    while(1) {
        int posX1 = posX;
        int posY1 = posY;
        if(GetAsyncKeyState(VK_NUMPAD4)){
                if(maze[posY][posX-1] != 1){
                    posX -= 1;
                }
        }
        if(GetAsyncKeyState(VK_NUMPAD6)){
                if(maze[posY][posX+1] != 1){
                    posX += 1;
                }
        }

        if(GetAsyncKeyState(VK_NUMPAD8)){
                if(maze[posY-1][posX] != 1){
                    posY -= 1;
                }
        }

        if(GetAsyncKeyState(VK_NUMPAD5)){
                if(maze[posY+1][posX] != 1){
                    posY += 1;
                }
        }
        if(posX != posX1 || posY != posY1){
            maze[posY1][posX1] = 0;
            maze[posY][posX] = 2;
            updateMaze(hConsole, saved_attributes);
        }
        Sleep(100);
    }

    updateMaze(hConsole, saved_attributes);
    CloseHandle(hConsole);
}

void updateMaze(HANDLE console,WORD attr){
    system("cls");
    for(int y=0;y<HEIGHT;y++) {
		printf("\n");
		for(int x=0;x<WIDTH;x++) {
			if(maze[y][x] == 0){
                printf("  ");
			}else if(maze[y][x] == 1){
			    SetConsoleTextAttribute(console, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
                printf("  ");
                SetConsoleTextAttribute(console, attr);
			}else if(maze[y][x] == 2){
			    SetConsoleTextAttribute(console, BACKGROUND_GREEN);
                printf("  ");
                SetConsoleTextAttribute(console, attr);
			}else{
                printf("?");
			}
        }
	}

}
