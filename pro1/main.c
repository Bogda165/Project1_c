#include <stdio.h>
#include <stdlib.h>
#include "cases.h"
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
                //print(ids, position, type, value, time, date, arraySize);
                break;
            case 'v':
                readFile(&file, &v, n, ids, position, type, value, time, date, arraySize);
                break;
            case 'c':
                arraySize--;
                printf("------------------------\n");
                delStringFromArray(&ids, arraySize, 0, 5);
                delStringFromArray(&position, arraySize, 0, 14);
                delStringFromArray(&type, arraySize, 0, 2);
                delFloatFromArrayCorrect(&value, arraySize, 0);
                delStringFromArray(&time, arraySize, 0, 4);
                delStringFromArray(&date, arraySize, 0, 8);
        
                break;
            case 'z':
                case_z(n, &ids, &position, &type, &value, &time, &date, &arraySize);
                break;
            case '0':
                print(ids, position, type, value, time, date, arraySize);
            case 't':
                /*check swap
                for(int i = 0; i < arraySize; i++){
                    printf("%s\n", ids[i]);
                }
                swap_string(&ids, 0, arraySize - 1, 5);
                printf("\nSwap:::\n\n");
                for(int i = 0; i < arraySize; i++){
                    printf("%s\n", ids[i]);
                }
                 */
                //sort(&type, &date, &time, &value, &position, arraySize);
                //printf("%d->%s%s\n", find_min(date, time, arraySize, 0), date[find_min(date, time, arraySize, 0)], time[find_min(date, time, arraySize, 0)]);
                print(ids, position, type, value, time, date, arraySize);
                break;
            case 's':
                case_s(n, ids, type, date, time, value, position, arraySize);
                break;
            default:
                break;
        }
    }
    
    return 0;
}
