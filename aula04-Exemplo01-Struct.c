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

    printf("Entre com o nome: ");
    fgets(pessoa1.nome, MAX-1, stdin);
    printf("Entre com a idade: ");
    scanf("%d", &pessoa1.idade);

    getchar();


    printf("Entre com o nome: ");
    fgets(pessoa2.nome, MAX-1, stdin);
    printf("Entre com a idade: ");
    scanf("%d", &pessoa2.idade);



    printf("Nome: %s", pessoa1.nome);
    printf("Idade: %d\n\n", pessoa1.idade);

    printf("Nome: %s", pessoa2.nome);
    printf("Idade: %d\n", pessoa2.idade);

}