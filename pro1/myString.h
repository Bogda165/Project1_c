#pragma once
#include <stdio.h>
#include <stdlib.h>
//#include "func.h"
//create emty array

char** create_empty(int arraySize, int strLenght){
    char** str = (char**)malloc(sizeof(char*) * arraySize);
    for(int i = 0; i < arraySize; i++){
        str[i] = malloc(sizeof(char*) * strLenght);
    }
    return str;
}

// set copry string 1 to string 2
void copy_string(char** str1, char** str2, int size){
    for(int i = 0; i < size; i++){
        (*str2)[i] = (*str1)[i];
    }
}
//comparte 2 strings
int compare_string(char* str1, char* str2, int size){
    
    for(int i = 0; i < size; i++){
        if (str1[i] != str2[i]){
            return 0;
        }
    }
    return 1;
}

int find_corect(char* str, int size, char c){
    
    for(int i = 0; i < size; i++){
        if(str[i] ==  c){
            return i;
        }
    }
    
    return 0;
}
// swap 2 strings
void swap_string(char ***str, int index1, int index2, const int length){
    char *tmp = (char*)malloc(sizeof(char) * length);
    //printf("str1:%s str2:%s tmp:%s\n", (*str)[index1], (*str)[index2], tmp);
    copy_string(&(*str)[index1], &tmp, length);
    //printf("str1:%s str2:%s tmp:%s\n", (*str)[index1], (*str)[index2], tmp);
    copy_string(&(*str)[index2], &(*str)[index1], length);
    //printf("str1:%s str2:%s tmp:%s\n", (*str)[index1], (*str)[index2], tmp);
    copy_string(&tmp, &(*str)[index2], length);
    //printf("str1:%s str2:%s tmp:%s\n", (*str)[index1], (*str)[index2], tmp);
}

