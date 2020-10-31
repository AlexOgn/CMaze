#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

#define HEIGHT 25
#define WIDTH 25
#define SIZE 25

int maze[HEIGHT][WIDTH];
int posX = 1, posY = 1;

void updateMaze();

int main(void){
    for(int i=0;i<SIZE;i++){
        maze[i][0] = 1;
        maze[i][WIDTH-1] = 1;
        maze[0][i] = 1;
        maze[HEIGHT-1][i] = 1;
    }
    maze[posX][posY] = 2;
    updateMaze();
    while(1) {
        int posX1 = posX;
        int posY1 = posY;
        if(GetAsyncKeyState(VK_NUMPAD4)){
                if(posX > 1){
                    posX -= 1;
                }
        }
        if(GetAsyncKeyState(VK_NUMPAD6)){
                if(posX < WIDTH-2){
                    posX += 1;
                }
        }

        if(GetAsyncKeyState(VK_NUMPAD8)){
                if(posY > 1){
                    posY -= 1;
                }
        }

        if(GetAsyncKeyState(VK_NUMPAD5)){
                if(posY < HEIGHT){
                    posY += 1;
                }
        }
        if(posX != posX1 || posY != posY1){
            maze[posY1][posX1] = 0;
            maze[posY][posX] = 2;
            updateMaze();
        }
        Sleep(100);
    }

    updateMaze(maze[HEIGHT][WIDTH]);
}

void updateMaze(){
    system("cls");
    for(int y=0;y<HEIGHT;y++) {
		printf("\n");
		for(int x=0;x<WIDTH;x++) {
			if(maze[y][x] == 0){
                printf("  ");
			}else if(maze[y][x] == 1){
                printf("# ");
			}else if(maze[y][x] == 2){
                    printf("F ");
			}else{
                printf("?");
			}
        }
	}

}
