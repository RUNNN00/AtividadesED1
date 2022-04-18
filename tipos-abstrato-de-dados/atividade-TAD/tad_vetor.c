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

void addQtd(int *qtd, int elemento)
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
    addQtd(&(v->qtd), elemento);

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
    addQtd(&(v->qtd), elemento);
    return true;
}

bool vet_substituir(Vetor *v, int posicao, int novoElemento)
{
    if (v->tam <= posicao)
        return false;

    v->vet[posicao] = novoElemento;

    return true;
}

void vet_imprimir(Vetor *v)
{
    printf("tam: %d\n", vet_tamanho(v));
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

bool vet_removerPosicao(Vetor *v, int posicao, int *endereco)
{
    if (v->tam <= posicao)
        return false;

    *endereco = v->vet[posicao];
    v->vet[posicao] = 0;
    v->qtd--;

    return true;
}

int vet_removerElemento(Vetor *v, int elemento)
{
    for (int i = 0; i < v->tam; i++)
    {
        if (v->vet[i] == elemento)
        {
            v->vet[i] = 0;
            v->qtd--;
            return i;
        }
    }

    return -1;
}

int vet_tamanho(Vetor *v)
{
    return v->tam;
}

bool vet_elemento(Vetor *v, int posicao, int *saida)
{
    if (v->tam <= posicao)
        return false;

    *saida = v->vet[posicao];

    return true;
}

int vet_posicao(Vetor *v, int elemento)
{
    for (int i = 0; i < v->tam; i++)
    {
        if (v->vet[i] == elemento)
            return i;
    }

    return -1;
}

void vet_desalocar(Vetor **endVetor)
{
    free(*endVetor);
    *endVetor = NULL;
}

bool vet_toString(Vetor *v, char *saida)
{
    int tamChar = v->tam * 2 + 1;
    // saida = (char *)malloc(sizeof(char) * tamChar);

    if (saida == NULL || v->tam == 0)
        return false;

    saida[0] = '[';
    int j = 1;
    for (int i = 1; i < tamChar; i++)
    {
        if (i % 2 == 1)
        {
            // saida[i] = v->vet[i - j] + '0';
            saida[i] = '0';
            j++;
        }
        else
        {
            if (i < tamChar - 2)
                saida[i] = ',';
        }
    }
    saida[tamChar - 1] = ']';
    saida[tamChar] = '\0';
    vet_imprimir(v);

    return true;
}
