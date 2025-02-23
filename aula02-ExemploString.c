#include <stdio.h>
#include <string.h>

#define MAX 250

int main()
{
    char nome[MAX];

    printf("Entre com o nome: ");
    fgets(nome,MAX-1, stdin);

    printf("Nome: %s\n", nome);

}
