#include<stdio.h>
#include "Vetor.h"

int main()
{
    Vetor* v = vet_criar();

    vet_anexar(v, 25);
    vet_anexar(v, 40);
    vet_anexar(v, 7);
    vet_imprimir(v);

    return 0;
}