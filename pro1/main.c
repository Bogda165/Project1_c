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
    int tmp_int_tmp = arraySize;
    
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
                tmp_int_tmp = arraySize;
                for(int i = 0; i < tmp_int_tmp; i++){
                    arraySize -= 1;
                    delStringFromArray(&ids, arraySize, i, 5);
                    delStringFromArray(&position, arraySize, i, 14);
                    delStringFromArray(&type, arraySize, i, 2);
                    delFloatFromArrayCorrect(&value, arraySize, i);
                    delStringFromArray(&time, arraySize, i, 4);
                    delStringFromArray(&date, arraySize, i, 8);
                }
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
                
        
                break;
            case 'z':
                case_z(n, &ids, &position, &type, &value, &time, &date, &arraySize);
                break;
            case '0':
                print(ids, position, type, value, time, date, arraySize);
            case 't':
                print(ids, position, type, value, time, date, arraySize);
                break;
            case 's':
                case_s(n, ids, type, date, time, value, position, arraySize);
                break;
            case 'h':
                case_h(type, value, arraySize);
                break;
            default:
                break;
        }
    }
    
    return 0;
}
