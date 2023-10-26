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
            case 'n':
                addToSystem(&file, v, &n, &ids, &position, &type, &value, &time, &date, &arraySize);
                print(ids, position, type, value, time, date, arraySize);
                break;
            case 'v':
                readFile(&file, &v, n, ids, position, type, value, time, date, arraySize);
                break;
            case 'c':
                arraySize--;
                printf("------------------------\n");
                delStringToArray(&ids, arraySize, 2, 5);
                delStringToArray(&position, arraySize, 2, 14);
                delStringToArray(&type, arraySize, 2, 2);
                //delStringToArray(&value, arraySize, 2, 15);
                delStringToArray(&time, arraySize, 2, 4);
                delStringToArray(&date, arraySize, 2, 8);
        
                print(ids, position, type, value, time, date, arraySize);
                break;
            default:
                break;
        }
    }
    
    return 0;
}
