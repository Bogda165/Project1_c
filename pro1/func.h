#include <stdio.h>
#include <stdlib.h>


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


void addToSystem(FILE** file, const int v, int* n , char*** ids, char*** position, char*** type, float **value, char*** time, char*** date, int* arraySize){
    
    char tmp_ids[6];
    char tmp_position[15];
    char tmp_type[3];
    float tmp_value = 0;
    char tmp_time[5];
    char tmp_date[9];
    
    if(v == 1 || v == 0){
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
            printf("%s\n%s\n%s\n%f\n%s\n%s\n\n", tmp_ids, tmp_position, tmp_type, tmp_value, tmp_time, tmp_date);

            (*arraySize)++;
            addStringToArrayCorrect(ids, arraySize, tmp_ids, 5);
            addStringToArrayCorrect(position, arraySize, tmp_position, 14);
            addStringToArrayCorrect(type, arraySize, tmp_type, 2);
            addStringToArrayCorrect(date, arraySize, tmp_time, 4);
            addStringToArrayCorrect(time, arraySize, tmp_date, 8);
            addFloatToArrayCorrect(value, arraySize, tmp_value);
            
            printf("%s\n", (*ids)[*arraySize - 1]);
            printf("%s\n", (*position)[*arraySize - 1]);
            printf("%s\n", (*type)[*arraySize - 1]);
            printf("%f\n", (*value)[*arraySize - 1]);
            printf("%s\n", (*date)[*arraySize - 1]);
            printf("%s\n", (*time)[*arraySize - 1]);
            printf("\n");
        }
        //print for test
        
        printf("Size: %d\n", *arraySize);
        for(int i = 0; i < *arraySize; i++){
            printf("%s\n", (*ids)[i]);
            printf("%s\n", (*position)[i]);
            printf("%s\n", (*type)[i]);
            printf("%f\n", (*value)[i]);
            printf("%s\n", (*date)[i]);
            printf("%s\n", (*time)[i]);
            printf("\n");
        }
        
        
        
    }else{
        printf("Neotvoreny subor.\n");
    }
}

void readFile(FILE** file, int* v, const int n){
    char tmp_ids[6];
    char tmp_position[15];
    char tmp_type[3];
    float tmp_value = 0;
    char tmp_time[5];
    char tmp_date[9];
    //char buffer[100];
    if(*v == 0){
        if((*file = fopen("dataloger.txt", "r")) != NULL){
            if(n == 0){
                
                while(fscanf(*file, "%s\n%s\n%s\n%f\n%s\n%s\n", tmp_ids, tmp_position, tmp_type, &tmp_value, tmp_time, tmp_date) == 6){
                    
                    //reading from file
                    printf("%s\n%s\n%s\n%f\n%s\n%s\n\n", tmp_ids, tmp_position, tmp_type, tmp_value, tmp_time, tmp_date);
                    
                }
                
            }else{
                //print from arrays
            }
        }else{
            printf("Neotvoreny subor\n");
        }
    }else{
        printf("Subor uz bol otvereny\n");
    }
}
