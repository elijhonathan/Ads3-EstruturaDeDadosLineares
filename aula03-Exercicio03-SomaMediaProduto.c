#include <stdio.h>

#define TAM 3

void lerNumeros(int numeros[TAM])
{
    printf("Digite %d numeros: ", TAM);

    for(int i = 0; i < TAM; i++)
    {
        scanf("%d", &numeros[i]);
    }

}

int somaValores(int numeros[TAM])
{
    int soma = 0;

    for(int i = 0; i < TAM; i++)
    {
        soma = soma + numeros[i];
    }

    return soma;
}

double mediaValores(double soma)
{
    double media = soma / TAM;

    return media;
}

int produtoValores(int numeros[TAM])
{
    int produto = 1;

    for(int i = 0; i < TAM; i++)
    {
        produto = produto * numeros[i];
    }

    return produto;
}

int resultado(int soma, double media, int produto)
{
    printf("A soma dos valores eh %d\n", soma);
    printf("A media dos valores eh %.2f\n", media);
    printf("O produto dos valores eh %d\n", produto);

}



int main()
{
    int numeros[TAM];

    lerNumeros(numeros);

    int soma = somaValores(numeros);

    double media = mediaValores(soma);

    int produto = produtoValores(numeros);

    resultado(soma, media, produto);

}
