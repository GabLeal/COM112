#include <stdlib.h>
#include <stdio.h>
#include "com112_file.h"

void output(int *vector, int len){

    FILE *arq;
    int i;
    arq = fopen("com112_saida.txt", "w");
    
    fprintf(arq,"%d\n", len);
    for (i = 0; i < len; i++){
       fprintf(arq, "%d ", vector[i]);
    }

    fclose(arq);
}

void input(int *vector, int len){

    FILE *arq;
    int i;
    arq = fopen("com112_entrada.txt", "w");


    fprintf(arq,"%d\n", len);
    for (i = 0; i < len; i++){
       fprintf(arq, "%d ", vector[i]);
    }
        
    fclose(arq);
} 

void reportFile(char *sort, int len, int moves, int comparies, double time){

    FILE *arq;
    arq = fopen("com112_relatorio.txt", "a");

    fprintf(arq,"Numero de elementos ordenados: %d\n", len);

    fprintf(arq, "%s", sort);
    fprintf(arq,"Tempo: %.2f\n", time);
    fprintf(arq,"Comparações: %d\n", comparies);
    fprintf(arq,"Movimentações: %d\n\n", moves);

    fclose(arq);
    printf("\n");
}
