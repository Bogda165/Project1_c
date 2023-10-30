#include <stdio.h>
#include <stdlib.h>

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
int compare_string(char* str1, char* str2, int size){
    
    for(int i = 0; i < size; i++){
        if (str1[i] != str2[i]){
            return 0;
        }
    }
    return 1;
}
// set copry string 1 to string 2
void copy_string(char** str1, char** str2, int size){
    for(int i = 0; i < size; i++){
        (*str2)[i] = (*str1)[i];
    }
}

char** create_empty(int arraySize, int strLenght){
    char** str = (char**)malloc(sizeof(char*) * arraySize);
    for(int i = 0; i < arraySize; i++){
        str[i] = malloc(sizeof(char*) * strLenght);
    }
    return str;
}
float* create_empty_float(int arraySize){
    float* array = (float*)malloc(sizeof(float) * arraySize);
    return array;
}

double* create_empty_double(int arraySize){
    double* array = (double*)malloc(sizeof(double) * arraySize);
    return array;
}
//If we can not use atof:( we need our own method
//C does not support default arguments so will imagine that beg by defalut is 0; end = size - 1
//Does to work

int find_corect(char* str, int size, char c){
    
    for(int i = 0; i < size; i++){
        if(str[i] ==  c){
            return i;
        }
    }
    
    return 0;
}

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
    return a + b;
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
                //printf("First: %s", id_tmp_tmp);
                //printf("Second: %s\n", ids[i]);
                /*
                if(compare_string(id_tmp_tmp, ids[i], 5) == 1){
                    position_tmp[i] = convert_work(0, 6, 7, position[i]);
                    position_tmp2[i] = convert_work(7, 13, 7, position[i]);
                    copy_string(type[i], type_tmp[size_tmp], 2);
                    copy_string(time[i], time_tmp[size_tmp], 4);
                    copy_string(date[i], date_tmp[size_tmp], 8);
                    value_tmp[size_tmp] = value[i];
                    size_tmp++;
                    printf(" yes\n");
                }
                 */
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
                fprintf(file, "%0.4lf\t", position_tmp[i]);
                fprintf(file, "%0.4lf\n", position_tmp2[i]);
            }
            
            printf("Pre dany vstup je vytvoreny txt subor\n");
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
    printf("%d", k + 1);
}
