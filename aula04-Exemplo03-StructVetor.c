#include <stdio.h>
#include <string.h>


#define TAM 2
#define MAX 250

struct Pessoa
{
    char nome[MAX];
    int idade;
};
typedef struct Pessoa TPessoa;


int main()
{
    TPessoa pessoas[TAM];
    int i;

    for(i=0; i<TAM; i++)
    {
        printf("Nome: ");
        fgets(pessoas[i].nome, MAX-1, stdin);

        printf("Idade: ");
        scanf("%d", &pessoas[i].idade);

        getchar();

    }

    for(i=0; i<TAM; i++)
    {
        printf("Nome: %s", pessoas[i].nome);
        printf("Idade: %d\n", pessoas[i].idade);
        
    }

}