#pragma once
#include "func.h"
#include "myString.h"

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


void readFile(FILE** file, int* v, const int n, char** ids, char** position, char** type, float *value, char** time, char** date, int arraySize){
    char tmp_ids[6];
    char tmp_position[15];
    char tmp_type[3];
    float tmp_value = 0;
    char tmp_time[5];
    char tmp_date[9];
    //char buffer[100];
    if(1 == 1){
        if((*file = fopen("dataloger.txt", "r")) != NULL){
            if(n == 0){
                
                while(fscanf(*file, "%s\n%s\n%s\n%f\n%s\n%s\n", tmp_ids, tmp_position, tmp_type, &tmp_value, tmp_time, tmp_date) == 6){
                    
                    //reading from file
                    printf("ID. mer. modulu:%s\nPozícia modulu:%s\nTyp mer. veliciny:%s\nHodnota:%f\nCas merania: %s\nDatum merania:%s\n\n", tmp_ids, tmp_position, tmp_type, tmp_value, tmp_time, tmp_date);
                    
                }
                
            }else{
                //print from arrays
                //printf("Printed from arrays\n");
                print(ids, position, type, value, time, date, arraySize);
            }
            *v = 1;
            
        }else{
            printf("Neotvoreny subor\n");
        }
    }
}


void case_s(const int n, char** ids, char** type, char** date, char** time, float* value, char** position, int arraySize){
    
    char id_tmp_tmp[6];
    char type_tmp_tmp[3];
    
    //printf("Enter string:");
    scanf("%s %s", id_tmp_tmp, type_tmp_tmp);
    
    double* position_tmp;
    double* position_tmp2;
    char** type_tmp;
    char** date_tmp;
    char** time_tmp;
    float* value_tmp;
    int size_tmp = 0;
    
    FILE* file;
    file = fopen("vystup_S.txt", "w");
    
    if(file != NULL){
        if(n == 0){
            printf("Polia nie su vytvorene.\n");
        }else{
            // coppy strings into new arrays
            for(int i = 0; i < arraySize; i++){
                if(compare_string(id_tmp_tmp, ids[i], 5) == 1 && compare_string(type_tmp_tmp, type[i], 2) == 1){
                    size_tmp++;
                    addDoubleToArrayCorrect(&position_tmp, &size_tmp, convert_work(0, 6, 7, position[i]));
                    addDoubleToArrayCorrect(&position_tmp2, &size_tmp, convert_work(7, 13, 7, position[i]));
                    addStringToArrayCorrect(&type_tmp, &size_tmp, type[i], 2);
                    addStringToArrayCorrect(&time_tmp, &size_tmp, time[i], 4);
                    addStringToArrayCorrect(&date_tmp, &size_tmp, date[i], 8);
                    addFloatToArrayCorrect(&value_tmp, &size_tmp, value[i]);
                    
                }
            }
            
            //sort array
            
            sort(&type_tmp, &date_tmp, &time_tmp, &value_tmp, &position_tmp, &position_tmp2, size_tmp);
            
            for(int i = 0; i < size_tmp; i++){
                fprintf(file, "%s", date_tmp[i]);
                fprintf(file, "%s\t", time_tmp[i]);
                fprintf(file, "%0.2f\t", value_tmp[i]);
                if(position_tmp[i] > 0){
                    fprintf(file, "+");
                }
                fprintf(file, "%0.4lf   ", position_tmp[i]);
                if(position_tmp2[i] > 0){
                    fprintf(file, "+");
                }
                fprintf(file, "%0.4lf\n", position_tmp2[i]);
            }
            if(size_tmp == 0){
                printf("Pre dany vstup neexistuju zaznamy.\n");
            }else{
                printf("Pre dany vstup je vytvoreny txt subor\n");
            }
            // delete[]
            int tmp =  size_tmp;
            for(int i = 0; i < tmp; i++){
                size_tmp -= 1;
                delStringFromArray(&type_tmp, size_tmp, i, 2);
                delStringFromArray(&time_tmp, size_tmp, i, 4);
                delStringFromArray(&date_tmp, size_tmp, i, 8);
                delFloatFromArrayCorrect(&value_tmp, size_tmp, i);
                delDoubleFromArrayCorrect(&position_tmp, size_tmp, i);
                delDoubleFromArrayCorrect(&position_tmp2, size_tmp, i);
            }
        }
    }else{
        printf("Pre dany vstup nie je vytvoreny txt subor.\n");
    }
    fclose(file);
}


void case_z(const int n, char*** ids, char*** position, char*** type, float **value, char*** time, char*** date, int* arraySize){
    
    char id_tmp[6];
    
    //printf("Enter string:");
    scanf("%s", id_tmp);
    int k = 0;
    
    for(int i = 0; i < *arraySize; i ++){
        if(compare_string((*ids)[i], id_tmp, 5) == 1){
            k ++;
        }
    }
    
    int for_delete[k];
    int index = 0;
    //printf("Indexes deleted: ");
    for(int i = 0; i < *arraySize; i++){
        if(compare_string((*ids)[i], id_tmp, 5) == 1){
            
            //printf("%d ", i);
            for_delete[index] = i - index;
            index ++;
        }
    }
    
    for(int i = 0; i < k; i++){
        *arraySize -= 1;
        //printf("DELETE: %d", for_delete[i]);
        delStringFromArray(ids, *arraySize, for_delete[i], 5);
        delStringFromArray(position, *arraySize, for_delete[i], 14);
        delStringFromArray(type, *arraySize, for_delete[i], 2);
        delFloatFromArrayCorrect(value, *arraySize, for_delete[i]);
        delStringFromArray(time, *arraySize, for_delete[i], 4);
        delStringFromArray(date, *arraySize, for_delete[i], 8);
    }
    printf("Vymazalo sa : %d zaznamov !", k);
}

void oper_case_h(char **type, float *value, const int arraySize, char* str){
    int amount = 0;
    float min = 100000, max = -100000;
    for(int i = 0; i < arraySize; i++){
        if(compare_string(type[i], str, 2) == 1){
            amount ++;
            min = (min < value[i])? min: value[i];
            max = (max > value[i])? max: value[i];
        }
    }
    
    printf("\t%s\t\t\t\t%d\t\t\t %0.2f\t %0.2f\n", str, amount, min, max);
}

void case_h(char **type, float *value, const int arraySize){
    char **array;
    int array_size = 0;
    for(int i = 0; i < arraySize; i++){
        if(in_list(type[i], array, array_size, 2) == 1){
            array_size += 1;
            addStringToArrayCorrect(&array, &array_size, type[i], 2);
        }
    }
    printf("Typ mer.vel.    Pocetnost\t\tMinimum  Maximum\n");

    for(int i = 0; i < array_size; i++){
        oper_case_h(type, value, arraySize, array[i]);
    }
    int tmp = array_size;
    for(int i = 0; i < tmp; i++){
        array_size -= 1;
        delStringFromArray(&array, array_size, i, 2);
    }
    free(array);
}
