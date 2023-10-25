#include <stdio.h>
#include <stdlib.h>
#include "func.h"
// Функция для добавления строки в массив динамических строк

int main() {
    char** ids = (char**)malloc(sizeof(char*) * 255);
    char** position = (char**)malloc(sizeof(char*) * 255);
    char** type = (char**)malloc(sizeof(char*) * 255);
    char** time = (char**)malloc(sizeof(char*) * 255);
    char** date = (char**)malloc(sizeof(char*) * 255);
    float* value =(float*)malloc(sizeof(float) * 255);
    
    int arraySize = 0;
    
    FILE *file = NULL;
    
    //menu
    int v = 0;
    int n = 0;
    
    /*
    arraySize ++;
    ids = addStringToArray(ids, &arraySize, "A0001", 5);
    arraySize ++;
    ids = addStringToArray(ids, &arraySize, "A0005", 5);
    arraySize ++;
    */
    /*
    for (int i = 0; i < arraySize; i++) {
        free(ids[i]);
    }
    free(ids);
    */

    char menu = ' ';
    while(menu != 'k'){
        scanf("%c", &menu);
        
        switch(menu){
            case 'k':
                fclose(file);
                break;
            case 't':
                addToSystem(&file, v, &n, &ids, &position, &type, &value, &time, &date, &arraySize);
                print(ids, position, type, value, time, date, arraySize);
                break;
            case 'v':
                readFile(&file, &v, n, ids, position, type, value, time, date, arraySize);
                break;
            default:
                break;
        }
    }
    
    return 0;
}
