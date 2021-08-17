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