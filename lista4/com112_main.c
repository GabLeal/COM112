#include <stdio.h>
#include <stdlib.h>
#include "com112_sort.h"
#include "com112_file.h"

int menu(int len){
    int choice = 0;
    printf("SEJA BEM VINDO - TESTE UM METODO DE ORDENAÇÃO\n");
    printf("0 - Gerar numeros para ordenação\n");
    printf("1 - Bubble Sort\n");
    printf("2 - Selection Sort\n");
    printf("3 - Insertion Sort\n");
    printf("4 - Relatorio\n");
    printf("5 - Sair\n");
    printf("Opção: ");
    scanf("%d", &choice);

    return choice;
}

void relatorio(double dados[], int sort, int len){
    int opc = 0;

    char sort_name[3][30] =
	{ 
        "Método Bubble Sot\n",
	    "Método Selectin Sort\n",
	    "Método Insertion Sortn\n",
	};

    printf("%s", sort_name[0]);
    switch (sort){
    case 1:
        opc = 0;
        break;
    case 2:
        opc = 1;
        break;
    case 3:
        opc = 2;
        break;
    }
    
    printf("tempo: %.2f\n", dados[0]);
    printf("comparações: %.0f\n", dados[1]);
    printf("movimentações: %.0f\n", dados[2]);

    relatorio_file(sort_name[opc],dados,len);
}

int random_number(int vetor1[],int vetor2[],int vetor3[]){
    int len = 0;

    printf("quantidade de numeros a serem gerados e ordenados: ");
    scanf("%d", &len);

    for (int i = 0; i < len; i++){
        vetor1[i] = vetor2[i] = vetor3[i] = rand() % 100;
        vetor1[i] = rand() % 100;
        vetor2[i] = rand() % 100;
        vetor3[i] = rand() % 100;

    }

    return len;
}

void copiar_vetor(int vetor[],int vetor_copia[], int len){
    for (int i = 0; i < len; i++){
        vetor_copia[i] = vetor[i];
        printf("%d ", vetor[i]);
    }
    
}

int main(){

    int choice = 0;
    
    int vetor1[] = {};
    int vetor2[] = {};
    int vetor3[] = {};
    
    double *dados;
    int len = 0;
    int r = 0;
    int row = 0;

    do{
        choice = menu(len);
        printf("\n");
        switch (choice) {
            case 0 :
                len = random_number(vetor1,vetor2,vetor3);
                for (int i = 0; i < len; i++){
                    
                    printf("%d ", vetor1[i]);
                }
                printf("\n");
                for (int i = 0; i < len; i++){
                    printf("%d ", vetor2[i]);
                }
                printf("\n");
                for (int i = 0; i < len; i++){   
                    printf("%d ", vetor3[i]);
                }  
                printf("\n");          
                break;
            case 1:
                
                dados = bubble_sort(vetor1,len);
                r = 1;
                break;
            case 2:
                
                dados = selection_sort(vetor2,len);
                r = 2;
                break;
            case 3:
                
                dados = insertion_sort(vetor3,len);
                r = 3;
                break;
            case 4:
                relatorio(dados, r,len);
                break;
            case 5:
                break;
        }

    }while(choice != 5);


    return 0;
}