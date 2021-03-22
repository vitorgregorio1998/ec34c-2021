#include <stdio.h>
#include <time.h>

void selecao(int *num, int tam) { 
  int i, j, min, aux;
  for (i = 0; i < (tam-1); i++) 
  {
     min = i;
     for (j = (i+1); j < tam; j++) {
       if(num[j] < num[min]) 
         min = j;
     }
     if (i != min) {
       aux = num[i];
       num[i] = num[min];
       num[min] = aux;
     }
  }
}

void insercao(int *num, int tam){
    int i, j, chave;

    for(i=1; i< tam; i++){
        chave = num[i];
        j=i-1;
        while(j>=0 && num[j]>=chave){
            num[j+1]= num[j];
            j = j-1;
        }
        num[j+1]= chave;
    }

}


int main(){

    int num[10] = {6, 4, 2, 7, 5, 1, 0, 8, 9, 3};
    int i;
    clock_t Ti, Tf;

    printf("Vetor original: ");
    for(i=0; i<10; i++){
        printf("%d ", num[i]);
    }

    Ti = clock();

    //selecao(num, 10);
    insercao(num,10);

    Tf = clock();

    printf("\n\nvetor novo:     ");
    for(i=0; i<10; i++){
        printf("%d ", num[i]);
    }
    printf("\n\ntempo= %f\n\n", ((float)Tf - (float)Ti));

    return 0;
}