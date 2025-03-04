#include <stdio.h>

#define TAM 3

void numerosEntrada(int numeros[TAM])
{
    printf("Digite %d numeros: ", TAM);

    for(int i = 0; i < TAM; i++)
    {
        scanf("%d", &numeros[i]);
    }

}

int numeroPesquisa()
{
    int valor;

    printf("Digite um valor para pesquisar no vetor: ");
    scanf("%d", &valor);

    return valor;

}

int quantidadeVetor(int valor, int numeros[TAM])
{
    int quantidade = 0;

    for(int i = 0; i< TAM; i++)
    {
        if(valor == numeros[i])
        {
            quantidade++;
        }
    }

    return quantidade;
}

void resultado(int valor, int quantidade)
{
    printf("O numero %d aparece %d vezes", valor, quantidade);
}




int main()
{
    int numeros[TAM];

    numerosEntrada(numeros);

    int valor = numeroPesquisa();

    int quantidade = quantidadeVetor(valor, numeros);

   resultado(valor,quantidade);

}
