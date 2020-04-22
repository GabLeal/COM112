#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 10

typedef struct{
    int cod;
    char description[50];
    float price;
}Product;

int findProductByCod(Product product[],int cod){
    for(int i = 0; i < TAM; i++){
        if(product[i].cod == cod){
            return i+1;
        }
    }

    return -1;
}

void insertion_sort(Product product[]){
    char aux[50]; 

    for(int j = 1; j < TAM; j++ ){  

        for(int k = j; k > 0; k--){
            if (strcmp(product[k].description, product[k-1].description) < 0){
                strcpy(aux, product[k].description);
                strcpy(product[k].description, product[k-1].description);
                strcpy(product[k-1].description, aux);
            }else{
                break;
            }
        }
    } 
}

int main(){
    Product product[TAM];
    int findCod = 0;

    for (int i = 0; i < TAM; i++){
        printf("Codigo: ");
        scanf("%d", &product[i].cod);    
        printf("Descrição: ");
        scanf("%s", product[i].description);    
        printf("Preço:");
        scanf("%f", &product[i].price);
    } 
 
    insertion_sort(product);

    for (int i = 0; i < TAM; i++){
        printf("%d º -----------\n",i+1);
        printf("%d ", product[i].cod);
        printf("%s ", product[i].description);
        printf("%.2f", product[i].price);
        printf("\n\n");
    }

    printf("Codigo do numero a ser encontrado: ");
    scanf("%d", &findCod);

    int find = findProductByCod(product,findCod);

    if (find != -1){
        printf("Foram necessarios %d comparação para achar o produto abaixo: \n", find);
        printf("Cod: %d\n", product[find-1].cod);
        printf("Descrição: %s\n", product[find-1].description);
        printf("Preço: %.2f", product[find-1].price);
    }else{
        printf("Não possuimos nenhum produto com este Codigo em nosso sistema");
    }
    
    printf("\n");
    return 0;
}