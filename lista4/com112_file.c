#include <stdlib.h>
#include <stdio.h>

void saida(int vetor[], int n, int sort){

    FILE *arq;

    arq = fopen("com112_saida.txt", "w");
    
    fprintf(arq,"%d\n",n);
    for (int i = 0; i < n; i++){
       fprintf(arq, "%d ", vetor[i]);
    }

    fclose(arq);
}

void save(int vetor[], int n){

    FILE *arq;

    arq = fopen("com112_entrada.txt", "w");


    fprintf(arq,"%d\n",n);
    for (int i = 0; i < n; i++){
       fprintf(arq, "%d ", vetor[i]);
    }
        
    fclose(arq);
}

void relatorio_file(char *sort, double dados[],int len){

    FILE *arq;
    arq = fopen("com112_relatorio.txt", "a");

    fprintf(arq,"Numero de elementos ordenados: %d\n", len);

    fprintf(arq, "%s", sort);
    fprintf(arq,"tempo: %.2f\n", dados[0]);
    fprintf(arq,"comparações: %.0f\n", dados[1]);
    fprintf(arq,"movimentações: %.0f\n\n", dados[2]);

    fclose(arq);
    printf("\n");
}