#include <stdio.h>
#include <stdlib.h>
#include "com112_arvoreAVL.h"

/*
* PROTOTYPE
*/

int menu();

/*
* FUNCTIONS
*/

int menu(){
    int choice;
    printf(" 1 -  Criar arvore\n");
    printf(" 2 -  Liberar arvore\n");
    printf(" 3 -  Inserir elemento\n");
    printf(" 4 -  Remover elemento\n");
    printf(" 5 -  Consultar elemento\n");
    printf(" 6 -  Imprimir percurso pre-ordem\n");
    printf(" 7 -  Imprimir percurso em ordem\n");
    printf(" 8 -  Imprimir percurso pós-ordem\n");
    printf(" 9 -  Altura da arvore\n");
    printf("10 -  Total de elementos\n");
    printf("11 -  Sair\n");
    printf("opção: ");
    scanf("%d", &choice);

    return choice;
}

/*
* MAIN 
*/
int main(){
    AVLTree* root;
    int choice;
    int value;
    int num;

    do{
        choice = menu();
        printf("\n");
        
        switch (choice){
            case 1:
                root = createAVLTree();
                printf("Arvore criada com sucesso! \n\n");
                break;

            case 2:
                if(isEmptyAVLTree(root)){
                    deleteAVLTree(root);
                     printf("arvore liberada\n\n");
                }else{
                    printf("Você nao possui nenhuma arvore criada ate o momento\n\n");
                }
                
                break;
            case 3:
                    printf("Inserir valor: ");
                    scanf("%d", &value);
                    num = insertAVLTree(root, value);
                    printf("Valor inserido na arvore\n\n");

                break;
            case 4:
                    printf("Remover valor: ");
                    scanf("%d", &value);
                    num = removeAVLTree(root, value);
                    printf("Valor Removido da arvore\n\n");
                break;

            case 5:
                printf("Consultar valor: ");
                scanf("%d", &value);
                if(readAVLTree(root, value)){
                    printf("Numero esta na arvore\n");
                }else{
                    printf("Valor não encontrado\n");
                }

                break;

            case 6:
                preOrderAVLTree(root);
                break;

            case 7:
                emOrderAVLTree(root);
                break;

            case 8:
                posOrderAVLTree(root);
                break;

            case 9:
                printf("Altura da arvore: %d\n", heightAVLTree(root));                
                break;    

            case 10:
                printf("Quantidade de nós: %d\n",totalNOAVLTree(root));
                break;      
                                  
            case 11:  
                //free tree
                deleteAVLTree(root);                 
                break;   
            default:
                break;
        }
    }while(choice != 11);

    if (!isEmptyAVLTree(root)) deleteAVLTree(root);
        
    printf("\n");
    return 0;
}