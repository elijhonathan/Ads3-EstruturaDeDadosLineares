#include <stdio.h>
#include <string.h>


#define TAM 10
#define MAX 250

struct Pessoa
{
    char nome[MAX];
    int idade;
};
typedef struct Pessoa TPessoa;

void cadastraPessoas(TPessoa pessoas[TAM], int n)
{
    int i;

    for(i=0; i<n; i++)
    {
        printf("Nome: ");
        fgets(pessoas[i].nome, MAX-1, stdin);

        printf("Idade: ");
        scanf("%d", &pessoas[i].idade);

        getchar();
    }
}

void mostrarPessoas(TPessoa pessoas[TAM], int n)
{
    int i;

    for(i=0; i<n; i++)
    {
        printf("\nNome: %s", pessoas[i].nome);
        printf("Idade: %d\n", pessoas[i].idade);
        
    }
}

void pesquisaNome(TPessoa pessoas[TAM], int n)
{
    char nome[MAX];
    int i;
    int encontrou = 0;

    printf("Entre com o nome para pesquisar: ");
    fgets(nome, MAX-1, stdin);

    for(i=0; i<n; i++)
    {
        if(strcmp(pessoas[i].nome, nome) == 0)
        {
            encontrou =1;
            printf("\nNome: %s", pessoas[i].nome);
            printf("Idade: %d\n", pessoas[i].idade);  
        }

    }

    if (encontrou == 0)
    {
        printf("Pessoa nao encontrada!");
    }

    printf("\n");
}

int numeroPessoas()
{
    int n;

    do{
    printf("Entre com o numero de pessoas de 1 a 10: ");
    scanf("%d", &n);
    }
    while(n>TAM || n<=0);

    getchar();
    return n;
}


int main()
{
    TPessoa pessoas[TAM];

    int n = numeroPessoas();
    cadastraPessoas(pessoas, n);
    pesquisaNome(pessoas, n);
    mostrarPessoas(pessoas, n);

}