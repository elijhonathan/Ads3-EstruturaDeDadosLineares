#include <stdio.h>
#include <string.h>

#define TAM 10 //numero de alunos [linhas]
#define MAX 250 //tamanho da string [colunas]

void cadastra_alunos(char nomes[TAM][MAX], int idades[TAM], int numero_alunos)
{
    int i;

    printf("Cadastro de nomes de alunos\n");

    for(i=0; i< numero_alunos;i++)
    {
        printf("Nome aluno: ");
        fgets(nomes[i], MAX-1, stdin);

        printf("Digite a idade: ");
        scanf("%d", &idades[i]);
        printf("\n");

        getchar();
    }

}

void mostrar(char nomes[TAM][MAX], int idades[TAM], int numero_alunos)
{
    int i;

    printf("\nNomes dos alunos cadastrados\n");

    for(i=0; i< numero_alunos;i++)
    {
        printf("Nome aluno: %s", nomes[i]);
        printf("Idade: %d\n\n", idades[i]);

    }

}

int le_num_alunos()
{
    int num;

    printf("Entre com o numero de alunos: ");

    do
    {
        scanf("%d", &num);
    }

    while(num > TAM || num < 1);

    getchar();
    return num;
}



int main()
{
    char nomes[TAM][MAX];
    int idades[TAM];

    int numero_alunos;

    numero_alunos = le_num_alunos();

    cadastra_alunos(nomes, idades, numero_alunos);

    mostrar(nomes, idades, numero_alunos);

}
