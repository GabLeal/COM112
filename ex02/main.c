#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 10

typedef struct {
    char nome[50];
    float salario;
}Funcionario;

void print_sort(Funcionario funcionario[]){
    for (int i = 0; i < TAM; i++){
        printf("%d º -----------",i+1);
        printf("%s ", funcionario[i].nome);
        printf("%.2f", funcionario[i].salario);
        printf("\n");
    }
}

int main(){
    Funcionario funcionario[TAM];
    int position_compare = TAM-1;
    Funcionario aux;
    int position_bigger = 0;

    for (int i = 0; i < TAM; i++){

        printf("Nome do funcionario: ");
        scanf("%s", funcionario[i].nome);
        printf("Salario: ");
        scanf("%f",&funcionario[i].salario);
    }

    printf("Ordenados por ordem de inserção: \n");
    print_sort(funcionario);

    //Selection Sort numerico
    for(int i = 0; i < TAM-1; i++){       
       position_bigger = 0;
       
       for(int j = 0; j < position_compare; j++){
           
            if (funcionario[position_bigger].salario > funcionario[j+1].salario){
                position_bigger = j+1;
            }
            aux.salario = funcionario[position_bigger].salario;
       }

       funcionario[position_bigger].salario = funcionario[position_compare].salario;
       funcionario[position_compare].salario = aux.salario;

       position_compare--;
    }
    
    printf("Ordenados por maiores salarios: \n");
    print_sort(funcionario);

    //Selection Sort alfabetico
    position_compare = TAM-1;
    for(int i = 0; i < TAM-1; i++){       
       position_bigger = 0;
       
       for(int j = 0; j < position_compare; j++){
           
            if (strcmp(funcionario[position_bigger].nome, funcionario[j+1].nome) < 0){
                position_bigger = j+1;
            }
            strcpy(aux.nome, funcionario[position_bigger].nome);
        }
        strcpy(funcionario[position_bigger].nome, funcionario[position_compare].nome);
        strcpy(funcionario[position_compare].nome, aux.nome);

       position_compare--;
    }

    printf("Ordenados por ordem alfabetica: \n");
    print_sort(funcionario);
    
    printf("\n");
    
    return 0;
}