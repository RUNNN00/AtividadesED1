#ifndef _TAD_VETOR_
#define _TAD_VETOR_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/********************************************
 * DADOS
 *******************************************/
typedef struct vetor Vetor;

/********************************************
 * OPERAÇÕES
 *******************************************/
Vetor *vet_criar();
bool vet_anexar(Vetor *v, int elemento);
bool vet_inserir(Vetor *v, int elemento, int posicao);
bool vet_substituir(Vetor *v, int posicao, int novoElemento);
bool vet_removerPosicao(Vetor *v, int posicao, int *endereco);
int vet_removerElemento(Vetor *v, int elemento);
int vet_tamanho(Vetor *v);
bool vet_elemento(Vetor *v, int posicao, int *saida);
int vet_posicao(Vetor *v, int elemento);
void vet_imprimir(Vetor *v);
void vet_desalocar(Vetor **endVetor);
bool vet_toString(Vetor *v, char *saida);

#endif