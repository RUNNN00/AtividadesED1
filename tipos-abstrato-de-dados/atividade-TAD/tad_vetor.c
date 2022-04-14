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
 * funções auxiliares
 *******************************************/
int espacoLivre(Vetor *v)
{
    return v->tam - v->qtd;
}

void definirQtd(int *qtd, int elemento)
{
    if (elemento != 0)
        *qtd += 1;
}

bool dobrarVetor(Vetor *v)
{
    int *vetDobrado = (int *)calloc(v->tam * 2, sizeof(int));

    if (vetDobrado == NULL)
        return false;

    // copia elemento de um vetor para outro
    for (int i = 0; i < v->tam; i++)
    {
        vetDobrado[i] = v->vet[i];
    }

    // desaloca vetor antigo
    free(v->vet);
    v->vet = vetDobrado;
    v->tam *= 2;

    return true;
}

/********************************************
 * Implementação das funções
 *******************************************/
Vetor *vet_criar()
{
    Vetor *v = (Vetor *)malloc(sizeof(Vetor));
    v->vet = (int *)calloc(1, sizeof(int));
    v->tam = 1;
    v->qtd = 0;

    return v;
}

bool vet_anexar(Vetor *v, int elemento)
{
    if (espacoLivre(v) <= 0)
    {
        if (!dobrarVetor(v))
            return false;
    }

    v->vet[v->qtd] = elemento;
    definirQtd(&(v->qtd), elemento);

    return true;
}

bool vet_inserir(Vetor *v, int elemento, int posicao)
{
    if (posicao >= v->tam)
        return false;

    if (espacoLivre(v) <= 0)
    {
        if (!dobrarVetor(v))
            return false;
    }

    if (v->vet[posicao] != 0)
    {
        bool posValida = false;
        for (int i = v->tam - 1; i > posicao; i--)
        {
            if (v->vet[i] == 0)
            {
                v->vet[i] = v->vet[i - 1];
                v->vet[i - 1] = 0;
                posValida = true;
            }
        }

        if (posValida == false)
            return false;
    }

    v->vet[posicao] = elemento;
    v->qtd++;
    return true;
}

bool vet_substituir(Vetor *v, int posicao, int novoElemento)
{
    if (v->tam > posicao)
    {
        v->vet[posicao] = novoElemento;
        return true;
    }

    return false;
}

void vet_imprimir(Vetor *v)
{
    printf("tam: %d\n", v->tam);
    printf("qtd: %d\n", v->qtd);
    printf("[");
    for (int i = 0; i < v->tam; i++)
    {
        printf("%d", v->vet[i]);

        if (i < v->tam - 1)
            printf(", ");
    }
    printf("]\n");
}