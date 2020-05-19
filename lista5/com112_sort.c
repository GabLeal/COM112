#include "com112_sort.h"
#include "com112_file.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

double dados[3];
clock_t Ticks[2];

   
double *bubble_sort(int vetor[], int len){
    double Tempo;
    int compare = 0;
    int moviment = 0;

    save(vetor,len);

    int position_compare = len-1;
    int aux = 0;

    Ticks[0] = clock();
    for (int x = 0; x < position_compare; x++){
        for (int y = 0; y < position_compare; y++){
            compare += 1;

            if (vetor[y] > vetor[y+1]){
                aux = vetor[y];
                vetor[y] = vetor[y+1];
                vetor[y+1] = aux;

                moviment +=1;
            }
        }
    }
    Ticks[1] = clock();
    Tempo = (Ticks[1] - Ticks[0]) / 3600.0;
    
    dados[0] = Tempo;
    dados[1] = (double)compare;
    dados[2] = (double)moviment;
    
    saida(vetor,len,1);

    return dados;
}

double *selection_sort(int vetor[], int len){
    double Tempo;
    int compare = 0;
    int moviment = 0;
    
    save(vetor,len);
    
    int position_compare = len-1;
    int aux = 0;

    Ticks[0] = clock();
    for(int i = 0; i < len-1; i++){       
      int position_bigger = 0;
       
       for(int j = 0; j < position_compare; j++){
           compare +=1;
            if (vetor[position_bigger] < vetor[j+1]){
                position_bigger = j+1;
                moviment +=1;
            }
            aux = vetor[position_bigger];
       }

       vetor[position_bigger] = vetor[position_compare];
       vetor[position_compare] = aux;

       position_compare--;
    }
    Ticks[1] = clock();
    Tempo = (Ticks[1] - Ticks[0]) / 3600.0;

    dados[0] = Tempo;
    dados[1] = (double)compare;
    dados[2] = (double)moviment;

    saida(vetor,len,1);

    return dados;
}

double *insertion_sort(int vetor[], int len){
    double Tempo;
    int compare = 0;
    int moviment = 0;

    save(vetor,len);
    int position_compare = len-1;
    int aux = 0;

    Ticks[0] = clock();
    for(int j = 1; j <= position_compare; j++ ){  

        for(int k = j; k > 0; k--){
            compare +=1;
            if (vetor[k] < vetor[k-1]){
                aux = vetor[k];
                vetor[k] = vetor[k-1];
                vetor[k-1] = aux;

                moviment +=1;
            }else{
                break;
            }
        }
    } 
    Ticks[1] = clock();
    Tempo = (Ticks[1] - Ticks[0]) / 3600.0;

    dados[0] = Tempo;
    dados[1] = (double)compare;
    dados[2] = (double)moviment;

    saida(vetor,len,1);

    return dados;
}