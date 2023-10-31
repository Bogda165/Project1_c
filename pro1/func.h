#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "myString.h"
#include "PoweredNumbers.h"

// in ADD and DELEETE methods change array size before!!!!!!!!!!!!!!!!!!
void addStringToArrayCorrect(char*** array, const int* arraySize, const char* newString, int stringLength){
    char** tmp = (char**)malloc(*arraySize * sizeof(char*));
    if((*arraySize) != 1){
        for(int i = 0; i < *arraySize - 1; i++){
            tmp[i] = (char*)malloc((stringLength + 1) * sizeof(char*));
            for(int j = 0; j < stringLength; j++){
                tmp[i][j] = (*array)[i][j];
            }
            tmp[i][stringLength] = '\0';
        }
    }
    
    tmp[*arraySize - 1] = (char*)malloc((stringLength + 1) * sizeof(char));
    
    for (int i = 0; i < stringLength; i++) {
        //printf("I:%d\n EL: %c\n", i, newString[i]);
        tmp[*arraySize - 1][i] = newString[i];
    }
    
    tmp[*arraySize - 1][stringLength] = '\0';
    
    
    //memory
    //changed
    if(*arraySize > 1){
        for(int i = 0; i < *arraySize - 1; i++){
            
            free((*array)[i]);
        }
        free((*array));
    }
    
    (*array) = tmp;
}

void delStringFromArray(char*** array, const int arraySize, int index, const int stringLength){
    char** tmp = (char**)malloc(arraySize * sizeof(char*));
    int del = 0;
    for(int i = 0; i < arraySize; i++){
        if (i == index){
            del = 1;
        }
        tmp[i] = (char*)malloc((stringLength + 1) * sizeof(char*));
        for(int j = 0; j < stringLength; j++){
            tmp[i][j] = (*array)[i + del][j];
        }
        tmp[i][stringLength] = '\0';
    }
    if(arraySize > 1){
        for(int i = 0; i < arraySize - 1; i++){
            
            free((*array)[i]);
        }
        free((*array));
    }
    
    (*array) = tmp;
}

void delFloatFromArrayCorrect(float** array, const int arraySize, const int index){
    float* tmp = (float*)malloc(arraySize * sizeof(float));
    int del = 0;
    if((arraySize != 0)){
        for(int i = 0; i < arraySize; i++){
            if (i == index){
                del = 1;
            }
            tmp[i] = (*array)[i + del];
        }
    }
    
    
    //memory
    if(arraySize > 1){
        free((*array));
    }
    
    
    (*array) = tmp;
}


void addFloatToArrayCorrect(float** array, const int* arraySize, const float newFloat){
    float* tmp = (float*)malloc(*arraySize * sizeof(float));
    if((*arraySize != 0)){
        for(int i = 0; i < *arraySize - 1; i++){
            tmp[i] = (*array)[i];
        }
    }
    
    tmp[*arraySize - 1] = newFloat;
    
    //memory
    if(*arraySize > 1){
        free((*array));
    }
    
    
    (*array) = tmp;
}

void addDoubleToArrayCorrect(double** array, const int* arraySize, const double newDouble){
    double* tmp = (double*)malloc(*arraySize * sizeof(double));
    if((*arraySize != 0)){
        for(int i = 0; i < *arraySize - 1; i++){
            tmp[i] = (*array)[i];
        }
    }
    
    tmp[*arraySize - 1] = newDouble;
    
    //memory
    if(*arraySize > 1){
        free((*array));
    }
    
    
    (*array) = tmp;
}

void delDoubleFromArrayCorrect(double** array, const int arraySize, const int index){
    double* tmp = (double*)malloc(arraySize * sizeof(double));
    int del = 0;
    if((arraySize != 0)){
        for(int i = 0; i < arraySize; i++){
            if (i == index){
                del = 1;
            }
            tmp[i] = (*array)[i + del];
        }
    }
    
    
    //memory
    if(arraySize > 1){
        free((*array));
    }
    
    
    (*array) = tmp;
}

// prints
void print(char** ids, char** position, char** type, float *value, char** time, char** date, int arraySize){
    
    for(int i = 0; i < arraySize; i++){
        printf("ID. mer. modulu:%s\nPozícia modulu:%s\nTyp mer. veliciny:%s\nHodnota:%f\nCas merania: %s\nDatum merania:%s\n\n", ids[i], position[i], type[i], value[i], time[i], date[i]);
    }
}

void print_c(char** ids, const int arraySize){
    for(int i = 0; i < arraySize; i++){
        printf("%s\n", ids[i]);
    }
}

//for sort and sort
int find_min(char** date, char** time, const int size, const int beg){
    long double min = convert_to_int2(date[beg], time[beg], 8, 4);
    int index = beg;
    for(int i = beg + 1; i < size; i++){
        if(min > convert_to_int2(date[i], time[i], 8, 4)){
            min = convert_to_int2(date[i], time[i], 8, 4);
            index = i;
        }
    }
    
    return index;
}

void sort(char ***type, char ***date, char ***time, float **value, double** position_1, double** position_2, const int size){
    for(int i = 0; i < size - 1; i++){
        int min_index = find_min(*date, *time, size, i);
        //printf("%d->%s\n", min_index, (*time)[i]);
        //printf("%s %s\n", (*date[i]), (*time)[i]);
        //swap_string(type, i, find_min(*date, *time, size, i), 2);
        swap_string(type, i, min_index, 2);
        swap_string(date, i, min_index, 8);
        swap_string(time, i, min_index, 4);
        swap_float(value, i, min_index);
        swap_double(position_1, i, min_index);
        swap_double(position_2, i, min_index);
    }
}

int in_list(char *str, char** array, int size, int length){
    int k = 0;
    for(int i = 0; i < size; i++){
        //printf("%s %s->", str, array[i]);
        if(compare_string(str, array[i], length) == 1){
            //printf("yes\n");
            k = 1;
        }
        //printf("no\n");
    }
    if(size == 0){return 1;}
    return (k == 1)? 0: 1;
}

