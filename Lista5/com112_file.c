#include <stdlib.h>
#include <stdio.h>
#include "com112_file.h"
#include "com112_sort.h"

void saida(int vetor[], int n){
    FILE *arq;
    arq = fopen("com112_saida.txt", "a");
    
    fprintf(arq,"%d\n",n);
    int i;
    for (i = 0; i < n; i++){
       fprintf(arq, "%d ", vetor[i]);
    }
	fprintf(arq,"\n\n");  
    fclose(arq);
}

void entrada(int vetor[], int n){
    FILE *arq;
    arq = fopen("com112_entrada.txt", "a");

    fprintf(arq,"%d\n",n);
    int i;
	for (i = 0; i < n; i++){
       fprintf(arq, "%d ", vetor[i]);
    }
	fprintf(arq,"\n\n");   
    fclose(arq);
}

void relatorio_file(char *sort, double data[], int t, int flag){
    FILE *arq;
    arq = fopen("com112_relatorio.txt", "a");
	
	if(!flag){
    	fprintf(arq,"\nNumero de elementos ordenados: %d\n", t);
	}

    fprintf(arq,"%s", sort);
    fprintf(arq,"	tempo: %.2f\n", data[0]);
    fprintf(arq,"	comparações: %.0f\n", data[1]);
    fprintf(arq,"	movimentações: %.0f\n", data[2]);

    fclose(arq);
    printf("\n");
}