// ========================================================
/* DADOS
*   vetor de numeros inteiros
*   tamanho do vetor
*   quantidade preenchida do vetor
*/

/* OPERAÇÕES
*   cria vetor
*   destruir vetor
*   inserir numero
*   imprimir vetor
*   espaço livre
*/
// ========================================================

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "Vetor.h"

int main()
{
    // dados que serão usados
    Vetor* p;

    p = criaVetorInteiro(50);
    inserirNumero(22, p);
    inserirNumero(54, p);

    //destroiVetorInteiro(p);

    printf("Tamanho: %d\n", p->tam);
    printf("Quantidade: %d\n", p->qtd);
    printf("Espaco livre: %d\n", espacoLivreVetor(p));
    printf("Vetor:\n");
    imprimeVetorInteiro(p);

    return 0;
}