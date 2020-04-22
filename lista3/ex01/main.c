#include <stdio.h>
#include <stdlib.h>

#define TAM 10

void bubble_sort(int vetor[]){
    int position_compare = TAM-1;
    int aux = 0;

    for (int x = 0; x < position_compare; x++){
        for (int y = 0; y < position_compare; y++){
            if (vetor[y] < vetor[y+1]){
                aux = vetor[y];
                vetor[y] = vetor[y+1];
                vetor[y+1] = aux;
            }
        }
    }
}

int main(){
    int vetor[TAM] = { 8, 3, 2, 5, 1 ,4 ,7, 6, 20, 15};
    printf("Vetor sem ordenação: ");

    for(int i = 0; i < TAM; i++){
        printf("%d ",vetor[i]);
    }
    printf("\n");

    bubble_sort(vetor);

    printf("Vetor ordenado de forma decrescente: ");
    for(int i = 0; i < TAM; i++){
        printf("%d ",vetor[i]);
    }

    printf("\n");
    return 0;
}