/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <stdio.h>
#include <string.h>

#define MAXNAMES 99

int main() {
    
    char list[MAXNAMES][MAXNAMES];
    int arrayCount = 0;
    char done[MAXNAMES] = "done";
    char name[MAXNAMES];
    int i, j = 0;
    int checker = 0;
    int endCount = 0;
    int nameAmount = 0;
    
    while(checker != 1) {
        printf("Enter a Name: ");
        scanf("%s", name);
        checker = strcmp(done, name);
        //printf("%d\n", checker);
        if(checker != 0) {
            for(j = 0; j < MAXNAMES; j++) {
                list[i][j] = name[j];
                endCount++;
            }
            list[i][endCount - 1] = '\0';
            i++;
            nameAmount++;
        } else {
            break;
        }
        
    }
    
    for(i = 0; i < nameAmount; i++) {
        printf("%s\n", list[i]);
    }
    
    return 0;
}