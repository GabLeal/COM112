#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include "com112_sort.h"
#include "com112_file.h"

#define MAX 99999

int menu(){
	int opcao;
	system("cls");
	printf("--|Metodos de Ordenacao|--\n");
	printf("\n   0 - Gerar numeros aleatorios");
	printf("\n   1 - Bubble Sort");
	printf("\n   2 - Selection Sort");
	printf("\n   3 - Insertion Sort");
	printf("\n   4 - Merge Sort");
	printf("\n   5 - Relatorio");
 	printf("\n   6 - Sair");
 	printf("\n\nOpcao: ");
 	scanf("%d", &opcao);
 	system("cls");
 	return opcao;
}

int gerarNumerosAleatorios(int vet1[], int vet2[], int vet3[], int vet4[]){
	int i, r;
	int t = 0;
    printf("Qual o tamanho do vetor: ");
    scanf("%d", &t);
    printf("\n");
	for(i=0;i<t;i++){
		r = rand() % 100;
		vet1[i] = r;
		vet2[i] = r;
		vet3[i] = r;
		vet4[i] = r;
		printf("%d ",vet1[i]);
	}
	
	// Gravando no arquivo de entrada
	entrada(vet1,t);
	
	printf("\n\n");
	system("pause");
	return t;
}

void relatorio(double data[], int ans){
	int i = ans - 1;
    char sort_name[4][30] =
	{ 
        "Metodo Bubble Sort\n",
	    "Metodo Selectin Sort\n",
	    "Metodo Insertion Sort\n",
	    "Metodo Merge Sort\n",
	};

    printf("%s", sort_name[i]);
    
    printf("Tempo de execucao: %.2f\n", data[0]);
    printf("Numero de comparacoes: %.0f\n", data[1]);
    printf("Numero de movimentacoes: %.0f\n", data[2]);
}

int main(){
	srand(time(NULL));
    int opcao = 0;
    double aux[3];
    double tempo;
    int t = 0;
    int comp;
    int mov;
    int ans = 0;
	int vet1[MAX] = {};
	int vet2[MAX] = {};
	int vet3[MAX] = {};
	int vet4[MAX] = {};
	int flag = 0;
	
    do{
        opcao = menu();
        printf("\n");
        switch (opcao) {
            case 0 :
				t = gerarNumerosAleatorios(vet1, vet2, vet3, vet4);
				flag = 0;        
                break;
            case 1:    
				comp = 0;
                mov = 0;
                tempo = clock();
                bubbleSort(vet1, t, &comp, &mov);
                tempo = clock() - tempo;
                aux[0] = tempo;
                aux[1] = (double)comp;
    			aux[2] = (double)mov;
				printf("O vetor foi ordenado atraves do metodo Bubble Sort, clique na opcao relatiorio para visualizar estatisticas.\n\n");
				system("pause");
                ans = 1;
                // Gravando no arquivo de relatorio
				relatorio_file("Metodo Bubble Sort\n",aux,t,flag);
                if(flag==0){
					// Gravando no arquivo de saida
					saida(vet1,t);
					flag = 1;
				}
                break;
            case 2:
                comp = 0;
                mov = 0;
                tempo = clock();
                selectionSort(vet2, t, &comp, &mov);
                tempo = clock() - tempo;
                aux[0] = tempo;
                aux[1] = (double)comp;
    			aux[2] = (double)mov;
				printf("O vetor foi ordenado atraves do metodo Selection Sort, clique na opcao relatiorio para visualizar estatisticas.\n\n"); 
				system("pause");
                ans = 2;
                // Gravando no arquivo de relatorio
				relatorio_file("Metodo Selectin Sort\n",aux,t,flag);
                if(flag==0){
					// Gravando no arquivo de saida
					saida(vet2,t);
					flag = 1;
				}
                break;
            case 3:
                comp = 0;
                mov = 0;
                tempo = clock();
                insertionSort(vet3, t, &comp, &mov);
                tempo = clock() - tempo;
                aux[0] = tempo;
                aux[1] = (double)comp;
    			aux[2] = (double)mov;
				printf("O vetor foi ordenado atraves do metodo Insertion Sort, clique na opcao relatiorio para visualizar estatisticas.\n\n");
				system("pause");
                ans = 3;
                // Gravando no arquivo de relatorio
				relatorio_file("Metodo Insertion Sort\n",aux,t,flag);
                if(flag==0){
					// Gravando no arquivo de saida
					saida(vet3,t);
					flag = 1;
				}
                break;
            case 4:
                comp = 0;
                mov = 0;
                tempo = clock();
                mergeSort(vet4, 0, t-1, &comp, &mov);
                tempo = clock() - tempo;
                aux[0] = tempo;
                aux[1] = (double)comp;
    			aux[2] = (double)mov;
				printf("O vetor foi ordenado atraves do metodo Merge Sort, clique na opcao relatiorio para visualizar estatisticas.\n\n");
				system("pause");
                ans = 4;
                // Gravando no arquivo de relatorio
				relatorio_file("Metodo Merge Sort\n",aux,t,flag);
                if(flag==0){
					// Gravando no arquivo de saida
					saida(vet4,t);
					flag = 1;
				}
                break;
            case 5:
                relatorio(aux, ans);
                system("pause");
                break;
            case 6:
            	printf("Saindo...\n\n");
            	system("pause");
                break;
        }

    }while(opcao != 6);

    return 0;
}


