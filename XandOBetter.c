//Simple Naughts and Crosses
#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAXSIZE 3
#define MAXTURNS 9
#define LOWESTWINNINGTURN 3

int main() {
   
   int i;
   int j;
   int newGrid[MAXSIZE][MAXSIZE];
   char grid[MAXSIZE][MAXSIZE];
   
   for(i = 0; i < MAXSIZE; i++) {
       for(j = 0; j < MAXSIZE; j++) {
           newGrid[i][j] = 0;
           grid[i][j] = '0';
       }
   }
   
   int row;
   int column;
   int turn;
   int winR = 0;
   int winC = 0;
   int winD = 0;
   
   for(turn = 0; turn < MAXTURNS; turn++) {
       for(i = 0; i < MAXSIZE; i++) {
           for(j = 0; j < MAXSIZE; j++) {
               printf("%c ", grid[i][j]);
               if(j == (MAXSIZE - 1)) {
                   printf("\n");
               }
           }
       }
       
       printf("turn = %d\n", turn);
       
       if(turn == 0 || (turn % 2) == 0) {
           printf("It's X's turn\nInput row for X: ");
           scanf("%d", &row);
           printf("Input column for X: ");
           scanf("%d", &column);
           grid[row - 1][column - 1] = 'X';
       } else {
           printf("It's O's turn\nInput row for O: ");
           scanf("%d", &row);
           printf("Input column for O: ");
           scanf("%d", &column);
           grid[row - 1][column - 1] = 'O';
       }
       if(turn > LOWESTWINNINGTURN) {
           winR = winCheckRows(grid);
           winC = winCheckColumns(grid);
           winD = winCheckDiag(grid);
           if(winR == 1) {
               printf("Winner!\n");
               return 0;
           } else if(winC == 1) {
               printf("Winner!\n");
               return 0;
           } else if(winD == 1) {
               printf("Winner\n");
           }
           //printf("wR %d\nwC %d\n", winCheckRows, winCheckColumns);
       }   
   }   
   
    return 0;
}

int winCheckRows(char rowCheck[MAXSIZE][MAXSIZE]) {
    
    int i;
    int j = 0;
    int winCheckR = 0;
    
    for(i = 0; i < MAXSIZE; i++) {
        if(rowCheck[i][j] == rowCheck[i][j + 1]) {
            if(rowCheck[i][j] != '0') {
                if(rowCheck[i][j] == rowCheck[i][j + 2]) {
                    winCheckR = 1;
                } else { 
                    winCheckR = 0;
                }
            }
        }
    }
    
    if(winCheckR == 1) {
        return 1;
    } else {
        return 0;
    }
    
}

int winCheckColumns(char columnCheck[MAXSIZE][MAXSIZE]) {
    
    int winColumn;
    int i = 0;
    int j;
    int winCheckC = 0;
    
    for(j = 0; j < MAXSIZE; j++) {
        if(columnCheck[i][j] == columnCheck[i + 1][j]) {
            if(columnCheck[i][j] != '0') {
                if(columnCheck[i][j] == columnCheck[i + 2][j]) {
                    winCheckC = 1;
                } else {
                    winCheckC = 0;
                }
            }
        }     
    }
    
    if(winCheckC == 1) {
        return 1;
    } else {
        return 0;
    }
}

int winCheckDiag(char diagCheck[MAXSIZE][MAXSIZE]) {
    
    //This'll only work with a 3x3 grid
    int winCheckD = 0;
    
    if(diagCheck[0][0] == diagCheck[1][1]) {
        if(diagCheck[0][0] == diagCheck[MAXSIZE][MAXSIZE]) {
            winCheckD = 1;
        }
    } else if(diagCheck[0][0] == diagCheck[MAXSIZE][MAXSIZE]) {
        if(diagCheck[0][0] == diagCheck[1][1]) {
            winCheckD = 1;
        }
    }
    
    if(diagCheck[0][MAXSIZE] == diagCheck[1][1]) {
        if(diagCheck[0][MAXSIZE] == diagCheck[MAXSIZE][MAXSIZE]) {
            winCheckD = 1;
        }
    } else if(diagCheck[0][MAXSIZE] == diagCheck[MAXSIZE][MAXSIZE]) {
        if(diagCheck[0][MAXSIZE] == diagCheck[1][1]) {
            winCheckD = 1;
        }
    }
    
    return winCheckD;
}
