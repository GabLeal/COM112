#ifndef COM112_SORT
#define COM112_SORT

void bubbleSort(int *vector, int len, int *moves, int *comparies);

void selectionSort(int *vector, int tam, int *moves, int *comparies);

void insertionSort(int *vector, int tam, int *moves, int *comparies);

void merge(int *vector, int begin, int middle, int end, int *moves, int *comparies);
void mergeSort(int *vector, int begin, int end, int *moves, int *comparies);

void quickSort(int *vector, int begin, int end, int *moves, int *comparies);
int partition(int *vector, int begin, int end, int *moves, int *comparies);

#endif