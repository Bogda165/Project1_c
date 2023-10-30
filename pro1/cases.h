#pragma once

#include <stdio.h>
#include <stdlib.h>

void addToSystem(FILE** file, const int v, int* n , char*** ids, char*** position, char*** type, float **value, char*** time, char*** date, int* arraySize){
    
    char tmp_ids[6];
    char tmp_position[15];
    char tmp_type[3];
    float tmp_value = 0;
    char tmp_time[5];
    char tmp_date[9];
    
    if(v == 1){
        //clead memory
        if(*n == 1){
            for(int i = 0; i < *arraySize; i++){
                free((*ids)[i]);
                free((*position)[i]);
                free((*type)[i]);
                free((*time)[i]);
                free((*date)[i]);
            }
            free(*ids);
            free(*position);
            free(*type);
            free(*value);
            free(*time);
            free(*date);
        }
        *n = 1;
        fseek(*file, 0, SEEK_SET);
        // reading + writing into arrays
        //printf("Size before: %d", *arraySize);
        *arraySize = 0;
        while(fscanf(*file, "%s\n%s\n%s\n%f\n%s\n%s\n", tmp_ids, tmp_position, tmp_type, &tmp_value, tmp_time, tmp_date) == 6){
            //add size to arrays
            //reading from file

            (*arraySize)++;
            addStringToArrayCorrect(ids, arraySize, tmp_ids, 5);
            addStringToArrayCorrect(position, arraySize, tmp_position, 14);
            addStringToArrayCorrect(type, arraySize, tmp_type, 2);
            addStringToArrayCorrect(date, arraySize, tmp_date, 8);
            addStringToArrayCorrect(time, arraySize, tmp_time, 4);
            addFloatToArrayCorrect(value, arraySize, tmp_value);
            
        }

    }else{
        printf("Neotvoreny subor.\n");
    }
}
