#include <stdio.h>
#include <stdlib.h>
#include "com112_arvoreAVL.h"

struct NO{
    int info;
    int height;
    struct NO *left;
    struct NO *right;
};

AVLTree* root;

AVLTree* createAVLTree(){
    AVLTree* root = (AVLTree*) malloc(sizeof(AVLTree));
    if(root != NULL){
        *root = NULL;
    }
    return root;
}

//calcula altura do no
int heightNO(struct NO* no){
    if(no == NULL){
        return -1;
    }else{
        return no->height;
    }
}

//calcula o fator de balanceamento de um nó
int balancingFactor(struct NO* no){
    return labs(heightNO(no->left) - heightNO(no->right));
}

//Calcula o maior valor
int bigger(int x, int y){
    if(x > y){
        return x;
    }else{
        return y;
    }
}

void rotationLL(AVLTree *root){
    struct NO *no;
    no = (*root)->left;
    (*root)->left = no->right;
    no->right = *root;
    (*root)->height = bigger(heightNO((*root)->left),heightNO((*root)->right) + 1);

    no->height = bigger(heightNO((*root)->left), (*root)->height+1);

    *root = no;

}

void rotationRR(AVLTree *root){
    struct NO *no;
    no = (*root)->right;
    (*root)->right = no->left;
    no->left = (*root);
    (*root)->height = bigger(heightNO((*root)->left),heightNO((*root)->right) + 1);

    no->height = bigger(heightNO(no->right), (*root)->height) +1;

    (*root) = no;
}

void rotationLR(AVLTree *root){
    rotationRR(&(*root)->left);
    rotationLL(root);
}

void rotationRL(AVLTree *root){
    rotationLL(&(*root)->right);
    rotationRR(root);
}

int insertAVLTree(AVLTree *root, int value){
    int answer;
    if(*root == NULL){
        struct NO *new;
        new = (struct NO*) malloc(sizeof(struct NO));
        if(new == NULL){
            return 0;
        }

        new->info = value;
        new->height = 0;
        new->left = NULL;
        new->right = NULL;
        *root = new;
        return 1;
    }

    struct NO *current = *root;
    if(value < current->info){
        if((answer = insertAVLTree(&(current->left), value)) == 1){
            if(balancingFactor(current) >= 2){
                if(value < (*root)->left->info){
                    rotationLL(root);
                }else{
                    rotationLR(root);
                }
            }
        }
    }else{
        if(value > current->info){
            if(answer = insertAVLTree(&(current->right),value) == 1){
                if(balancingFactor(current) >= 2){
                    if((*root)->right->info < value){
                        rotationRR(root);
                    }else{
                        rotationRL(root);
                    }
                }
            }
        }else{
            printf("Valor duplicado!!\n");
            return 0;
        }
    }
    current->height = bigger(heightNO(current->left), heightNO(current->right) + 1);

    return answer;
}


struct NO* findSmaller(struct NO* current){
    struct NO *no1 = current;
    struct NO *no2 = current->left;
    while (no2 != NULL){
        no1 = no2;
        no2 = no2->left;
    }

    return no1;
    
}

int removeAVLTree(AVLTree *root, int value){
    
    if(*root == NULL){
        printf("Valor não existe!!\n");
        return 0;
    }

    int answer;
    
    if(value < (*root)->info){
        if((answer = removeAVLTree(&(*root)->left, value)) == 1){
            if(balancingFactor(*root) >=2 ){
                if(heightNO((*root)->right->left) <= heightNO((*root)->right->right)){
                    rotationRR(root);
                }else{
                    rotationRL(root);
                }
            }
        }
    }

    if((*root)->info < value){
        if((answer = removeAVLTree(&(*root)->right, value)) == 1){
            if(balancingFactor(*root) >=2 ){
                if(heightNO((*root)->left->right) <= heightNO((*root)->left->left)){
                    rotationLL(root);
                }else{
                    rotationLR(root);
                }
            }
        }
    }

    if((*root)->info == value){
        if(((*root)->left == NULL || (*root)->right == NULL)){
            struct NO *oldNode = (*root);
            
            if((*root)->left != NULL){
                *root = (*root)->left;
            }else{
                *root = (*root)->right;
            }

            free(oldNode);
        }else{
            struct NO* temp = findSmaller((*root)->right);
            (*root)->info = temp->info;
            removeAVLTree(&(*root)->right, (*root)->info);

            if(balancingFactor(*root) >= 2){
                if(heightNO((*root)->left->right) <= heightNO((*root)->left->left)){
                    rotationLL(root);
                }else{
                    rotationLR(root);
                }
            }
        }
        return 1;
    }
    return answer;
}

//BIN Tree
void deleteNO(struct NO* no){
    if(no == NULL){
        return;
    }
    deleteNO(no->left);
    deleteNO(no->right);
    free(no);
    no = NULL;
}

void deleteAVLTree(AVLTree *root){
    if(root == NULL){
        return;
    }
    deleteNO(*root);
    free(root);
}

int isEmptyAVLTree(AVLTree *root){
    if(root == NULL || *root == NULL){
        return 1;
    }
    
    return 0;
}

int heightAVLTree(AVLTree *root){
    if(root == NULL || *root == NULL){
        return 0;
    }

    int heightLeft = heightAVLTree(&((*root)->left));
    int heightRight = heightAVLTree(&((*root)->right));

    if(heightLeft > heightRight){
        return (heightLeft + 1);
    }else{
        return (heightRight + 1);
    }

}

int totalNOAVLTree(AVLTree *root){
    if(root == NULL || *root == NULL){
        return 0;
    }

    int heightLeft = totalNOAVLTree(&((*root)->left));
    int heightRight = totalNOAVLTree(&((*root)->right));

    return(heightLeft + heightRight + 1);
}

void preOrderAVLTree(AVLTree *root){
    if(root == NULL){
        return;
    }

    if(*root != NULL){
        printf("%d\n", (*root)->info);
        preOrderAVLTree((&((*root)->left)));
        preOrderAVLTree((&((*root)->right)));
    }

}

void emOrderAVLTree(AVLTree *root){
    if(root == NULL){
        return;
    }

    if(*root != NULL){
        emOrderAVLTree((&((*root)->left)));
        printf("%d\n", (*root)->info);
        emOrderAVLTree((&((*root)->right)));
    }

}

void posOrderAVLTree(AVLTree *root){
    if(root == NULL){
        return;
    }

    if(*root != NULL){
        posOrderAVLTree((&((*root)->left)));
        posOrderAVLTree((&((*root)->right)));
        printf("%d\n", (*root)->info);
    }

}

int readAVLTree(AVLTree *root, int value){
    if(root == NULL){
        return 0;
    }

    struct NO* current = *root;
    while(current != NULL){
        if(value == current->info){
            return 1;
        }
        if(value > current->info){
            current = current->right;
        }else{
            current = current->left;
        }
    }
    
    return 0;
}
