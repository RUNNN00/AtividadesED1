typedef struct
{
    int *vetor;
    int tam;
    int qtd;
} Vetor;


Vetor* criaVetorInteiro(int size)
{
    Vetor* vet = (Vetor*) malloc(sizeof(Vetor));
    vet->tam = size;
    vet->qtd = 0;
    vet->vetor = (int*) calloc(size, sizeof(int));

    return vet;
}


void imprimeVetorInteiro(Vetor* vet)
{
    for (int i = 0; i < vet->tam; i++)
    {
        printf("%d", vet->vetor[i]);

        if (i < vet->tam - 1)
            printf(" ");
    }
    printf("\n");
}


void destroiVetorInteiro(Vetor* vet)
{
    free(vet->vetor);
    vet->vetor = NULL;
    free(vet);
    vet = NULL;
}


void inserirNumero(int num, Vetor* vet)
{
    vet->vetor[vet->qtd] = num;
    vet->qtd++;
}


int espacoLivreVetor(Vetor* vet)
{
    return vet->tam - vet->qtd;
}