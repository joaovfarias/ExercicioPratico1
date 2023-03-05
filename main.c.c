#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int judgeCircle(char *moves);


int main(){

    int result1;
    int result2;
    int result3;
    
    // Teste 1
    char *movesTest = malloc(sizeof(char) * 3);
    strcpy(movesTest, "UD");
    result1 = judgeCircle(movesTest);
    printf("Teste 1: %s\n", movesTest);
    printf("Resultado 1: %d\n", result1);
    free(movesTest);

    printf("\n");

    // Teste 2
    movesTest = malloc(sizeof(char) * 9);
    strcpy(movesTest, "UDLRLRUD");
    result2 = judgeCircle(movesTest);
    printf("Teste 2: %s\n", movesTest);
    printf("Resultado 2: %d\n", result2);
    free(movesTest);

    printf("\n");

    // Teste 3
    movesTest = malloc(sizeof(char) * 13);
    strcpy(movesTest, "LDURLDURLDDR");
    result3 = judgeCircle(movesTest);
    printf("Teste 3: %s\n", movesTest);
    printf("Resultado 3: %d\n", result3);
    free(movesTest);
}

int judgeCircle(char *moves){

    int totalMoves = strlen(moves);
    char *beginPointer = moves;
    char *endPointer = &moves[totalMoves - 1];
    int xCoordinate = 0;
    int yCoordinate = 0;

    if (totalMoves % 2 == 1){
        return 0;
    }

    for (int i = 0; i < totalMoves / 2; i++){
        if (*beginPointer == 'U'){
            yCoordinate += 1;
        }
        else if (*beginPointer == 'D'){
            yCoordinate -= 1;
        }
        else if (*beginPointer == 'L'){
            xCoordinate -= 1;
        }
        else if (*beginPointer == 'R'){
            xCoordinate += 1;
        }
        beginPointer++;
        
        if (*endPointer == 'U'){
            yCoordinate += 1;
        }
        else if(*endPointer == 'D'){
            yCoordinate -= 1;
        }
        else if (*endPointer == 'L'){
            xCoordinate -= 1;
        }
        else if (*endPointer == 'R'){
            xCoordinate += 1;
        }
        endPointer--;
    }
    if (xCoordinate == 0 && yCoordinate == 0){
        return 1;
    }
    
    return 0;
}