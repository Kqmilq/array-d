#include "array.h"
#define SIZE 10
#include <stdio.h>
#include <stdlib.h>
FILE * fptr;


int FindMax(int tab[]){

    int max = tab[1];

    for (int i = 0; i < SIZE; ++i) {

        if(tab[i] > max){

            max = tab[i];

        }

    }

    return max;

}

int FindMin(int tab[]) {

    int min = tab[1];

    for (int i = 0; i < SIZE; ++i) {

        if (tab[i] < min) {

            min = tab[i];

        }

    }

    return min;

}

float FindAverage(int tab[]) {
    int sum = 0;
    for (int i = 0; i < SIZE; ++i) {
        sum += tab[i];
    }
    float srednia = (float)sum / SIZE;
    return srednia;
}
void enterValue(int tab[]){
    printf("wprowadz wartosci do tablicy:\n");
    for (int i = 0; i < SIZE; ++i) {
        printf("tab[%d] = ", i);
        scanf("%d", &tab[i]);
    }
}
void printArray(int tab[]){
    for (int i = 0; i < SIZE; ++i) {
        printf("tab[%d] = %d\n", i, tab[i]);
    }
}
void enter(int tab[]){
    fptr = fopen("tab.txt", "w+");
    if (fptr == 0)
    {
        exit(1);
    }
    for (int i = 0; i < SIZE ; ++i){
        fputc(tab[i], fptr);
    }
    fclose(fptr);
}
void read(int tab[]){
    fptr = fopen("tab.txt", "r+");
    fseek(fptr, 0, SEEK_SET);
    printf("Zapisana tabela:\n");
    for (int i = 0; i < SIZE; i++)
    {
        tab [i] = fgetc(fptr);
        fseek(fptr, 0, SEEK_CUR);
        printf("%d\n", tab [i]);
    }
    printf("\n");
    fclose(fptr);
}
