#include "Vetor.h"

/********************************************
 * Especificação dos dados
 *******************************************/
struct vetor
{
    int *vet;
    int tam;
    int qtd;
};

/********************************************
 * Implementação das funções
 *******************************************/
Vetor* vet_criar()
{
    Vetor *v = (Vetor*) malloc(sizeof(Vetor));
    v->vet = (int*) calloc(1, sizeof(int));
    v->tam = 1;
    v->qtd = 0;

    return v;
}

bool vet_anexar(Vetor* v, int elemento)
{
    int livre = v->tam - v->qtd;

    if (livre > 0)
    {
        v->vet[v->tam - 1] = elemento;
        return true;
    }

    return false;
}

void vet_imprimir(Vetor *v)
{
    printf("[");
    for (int i=0; i<v->tam; i++)
    {
        printf("%d", v->vet[i]);

        if (i < v->tam - 1)
            printf(", ");
    }
    printf("]\n");
}