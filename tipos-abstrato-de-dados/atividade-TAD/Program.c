#include<stdio.h>
#include "Vetor.h"

int main()
{
    Vetor* v = vet_criar();

    vet_anexar(v, 1);
    vet_imprimir(v);
    printf("\n");

    vet_anexar(v, 2);
    vet_imprimir(v);
    printf("\n");

    vet_anexar(v, 3);
    vet_imprimir(v);
    printf("\n");

    vet_inserir(v, 24, 2);
    vet_imprimir(v);
    printf("\n");

    vet_inserir(v, 99, 0);
    vet_imprimir(v);
    printf("\n");

    return 0;
}