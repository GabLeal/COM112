#ifndef COM112_ARVOREAVL
#define COM112_ARVOREAVL

typedef struct  NO* AVLTree;

AVLTree* createAVLTree();

void deleteAVLTree(AVLTree *root);

int isEmptyAVLTree(AVLTree *root);

int heightAVLTree(AVLTree *root);

int totalNOAVLTree(AVLTree *root);

void preOrderAVLTree(AVLTree *root);

void emOrderAVLTree(AVLTree *root);

void posOrderAVLTree(AVLTree *root);

int readAVLTree(AVLTree *root, int value);

//AVL
int insertAVLTree(AVLTree *root, int value);

int removeAVLTree(AVLTree *root, int value);
#endif