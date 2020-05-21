#ifndef COM112_SORT
#define COM112_SORT

// Insertion Sort
void insertionSort(int *vet, int tam, int *comp, int *mov);

// Selection Sort
void selectionSort(int *vet, int tam, int *comp, int *mov);

// Bubble Sort
void bubbleSort(int *vet, int tam, int *comp, int *mov);

// Merge Sort
void merge(int *v, int inicio, int meio, int fim, int *comparacao, int *movimento);
void mergeSort(int *v, int inicio, int fim, int *comparacao, int *movimento);
#endif