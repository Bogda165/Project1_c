#pragma once
#include <stdio.h>
#include <stdlib.h>


//create empty arrays
float* create_empty_float(int arraySize){
    float* array = (float*)malloc(sizeof(float) * arraySize);
    return array;
}

double* create_empty_double(int arraySize){
    double* array = (double*)malloc(sizeof(double) * arraySize);
    return array;
}


//converts

//If we can not use atof:( we need our own method
//C does not support default arguments so will imagine that beg by defalut is 0; end = size - 1
//Does to work


double convert_work(const int beg, const int end, int size, char* str){
    
    int index = find_corect(str, size, '.');
    
    //printf("%d", index);
    
    int part1 = 0;
    int part2 = 0;
    int pow = 1;
    
    //there is no point in file
    index = 2 + beg;
    
    for(int i = beg + 1; i <= end; i++){
        if(i <= index){
            part1 *= 10;
            part1 += str[i] - '0';
            //printf("%d", str[i] - '0');
        }else if(i > index){
            pow *= 10;
            part2 *= 10;
            part2 += str[i] - '0';
        }
    }
    //printf("%d.%d\n" ,part1, part2);
    double a =(double)part2 / pow;
    //printf("%lf\n",a);
    double b = part1;
    //printf("%f\n", b);
    //printf("%lf\n", a + b);
    double answer = a + b;
    printf("%c\n", str[beg]);
    if(str[beg] == '-'){
        answer *= -1;
    }
    return answer;
}

long double convert_to_int2(char* str1, char* str2, const int size1, const int size2){
    long double answer = 0;
    
    for(int i = 0; i < size1; i++){
        answer += str1[i] - '0';
        answer *= 10;
    }
    //printf("answer:%Lf\n", answer);
    for(int i = 0; i < size2; i++){
        answer += str2[i] - '0';
        answer *= 10;
    }
    return answer / 10;
}

// swaps
void swap_double(double** value, int index1, int index2){
    double tmp = (*value)[index1];
    (*value)[index1] = (*value)[index2];
    (*value)[index2] = tmp;
}
void swap_float(float** value, int index1, int index2){
    float tmp = (*value)[index1];
    (*value)[index1] = (*value)[index2];
    (*value)[index2] = tmp;
}
