#include <stdio.h>
#include <string.h>

#define MAX 250

struct Pessoa
{
    char nome[MAX];
    int idade;
};
typedef struct Pessoa TPessoa;


int main()
{
    TPessoa pessoa1;
    TPessoa pessoa2;

    strcpy(pessoa1.nome, "ana");
    pessoa1.idade = 20;

    strcpy(pessoa2.nome, "maria");
    pessoa2.idade = 35;

    printf("Nome: %s\n", pessoa1.nome);
    printf("Idade: %d\n\n", pessoa1.idade);

    printf("Nome: %s\n", pessoa2.nome);
    printf("Idade: %d\n", pessoa2.idade);

}