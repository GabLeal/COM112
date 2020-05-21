#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include "com112_sort.h"
#include "com112_file.h"

void bubbleSort(int *vet, int tam, int *comp, int *mov)
{

  int i, continua, aux;

  do
  {
    continua = 0;
    for (i = 0; i < tam - 1; i++)
    {

      *comp += 1;
      if (vet[i] > vet[i + 1])
      {

        *mov += 1;
        aux = vet[i];
        vet[i] = vet[i + 1];
        vet[i + 1] = aux;
        continua = i;
      }
    }
    tam--;
  } while (continua != 0);
}

void selectionSort(int *vet, int tam, int *comp, int *mov)
{

  int i, j, menor, troca;

  for (i = 0; i < tam - 1; i++)
  {
    menor = i;
    for (j = i + 1; j < tam; j++)
    {

      *comp += 1;
      if (vet[j] < vet[menor])
      {
        menor = j;
      }
    }
    if (i != menor)
    {
      *mov += 1;
      troca = vet[i];
      vet[i] = vet[menor];
      vet[menor] = troca;
    }
  }
}

void insertionSort(int *vet, int tam, int *comp, int *mov)
{

  int i, j, aux;

  for (i = 1; i < tam; i++)
  {
    aux = vet[i];
    for (j = i; ((j > 0) && (aux < vet[j - 1])); j--)
    {
      *comp += 1;
      *mov += 1;
      vet[j] = vet[j - 1];
    }
    vet[j] = aux;
  }
}

void merge(int *v, int inicio, int meio, int fim, int *comparacao, int *movimento)
{
    int *temp, p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0;
    tamanho = fim-inicio+1;
    p1 = inicio;
    p2 = meio+1;
    temp = (int *) malloc(tamanho*sizeof(int));
    if(temp != NULL)
    {
        for(i=0; i<tamanho; i++)
        {
            if(!fim1 && !fim2)
            {
                *comparacao = *comparacao + 1;
                if(v[p1] < v[p2])
                {
                    *movimento = *movimento + 1;
                    temp[i]=v[p1++];
                }
                else
                {
                    *movimento = *movimento + 1;
                    temp[i]=v[p2++];
                }
                if(p1>meio)
                {
                    fim1=1;
                }
                if(p2>fim)
                {
                    fim2=1;
                }
            }
            else
            {
                if(!fim1)
                {
                    *movimento = *movimento + 1;
                    temp[i]=v[p1++];
                }
                else
                {
                    *movimento = *movimento + 1;
                    temp[i]=v[p2++];
                }
            }
        }
        for(j=0, k=inicio; j<tamanho; j++, k++)
        {
            v[k]=temp[j];
        }
    }
    free(temp);
}

void mergeSort(int *v, int inicio, int fim, int *comparacao, int *movimento)
{
    int meio;
    if(inicio < fim){
        meio = floor((inicio+fim)/2);
        mergeSort(v,inicio,meio, comparacao, movimento);
        mergeSort(v,meio+1,fim, comparacao, movimento);
        merge(v,inicio,meio,fim, comparacao, movimento);
    }
}