#include<stdio.h>
#include<time.h>

#define sizeX 64
#define sizeY 64

int grid[sizeX][sizeY];
int bgrid[sizeX][sizeY];
int steps = 2;
int E = 120;

void ds(int sx, int sy, int size){
    int c1 = grid[sx][sy];
    int c2 = grid[sx+size-1][sy];
    int c3 = grid[sx][sy+size-1];
    int c4 = grid[sx+size-1][sy+size-1];

    int hx = sx + size/2;
    int hy = sy + size/2;

    srand (time(NULL));

    grid[hx][hy] = (c1 + c2 + c3 + c4) / 4 + rand() % E - E/2;
    int d = grid[hx][hy];

    srand (time(NULL));

    // e1
    if(grid[hx][sy] == -1) {
        grid[hx][sy] = (c1 + c2 + d) / 3 + rand() % E - E/2;
    }

    srand (time(NULL));

    // e2
    if(grid[sx + size - 1][hy] == -1) {
        grid[sx + size - 1][hy] = (c2 + c4 + d) / 3 + rand() % E - E/2;
    }

    srand (time(NULL));

    // e3
    if(grid[hx][sy + size - 1] == -1) {
        grid[hx][sy + size - 1] = (c3 + c4 + d) / 3 + rand() % E - E/2;
    }

    srand (time(NULL));

    // e4
    if(grid[sx][hy] == -1) {
        grid[sx][hy] = (c1 + c3 + d) / 3 + rand() % E - E/2;
    }

    if(size == 3) {
        return;
    }

    ds(sx, sy, size / 2 + 1);
    ds(hx, sy, size / 2 + 1);
    ds(sx, hy, size / 2 + 1);
    ds(hx, hy, size / 2 + 1);

}

int main(){
    for(int x = 0;x < sizeX;x ++) {
        for(int y = 0;y < sizeY;y ++) {
            grid[x][y] = -1;
            bgrid[x][y] = -1;
        }
    }

    grid[0][0] = 128;
    grid[sizeX-1][0] = 128;
    grid[0][sizeY-1] = 128;
    grid[sizeX-1][sizeY-1] = 128;

    ds(0, 0, sizeX);

    for(int x = 0;x < sizeX;x ++) {
        for(int y = 0;y < sizeY;y ++) {
            int v = grid[x][y];
            if(v<105){
                printf("%d %d # \n", x, y);
            }else if(v<175){
                printf("%d %d @ \n", x, y);
            }else if(v<245){
                printf("%d %d ! \n", x, y);
            }else{
                printf("%d %d $ \n", x, y);
            }
        }
        printf("\n");
    }
}
