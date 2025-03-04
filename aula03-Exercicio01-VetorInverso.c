#include <stdio.h>

#define TAM 3

void lerNumeros(int numeros[TAM])
{
    printf("Digite %d numeros: ", TAM);

    for(int i = 0; i < TAM ; i++)
    {
        scanf("%d", &numeros[i]);
    }
}

void imprimirNumeros(int numeros[TAM])
{
    for(int i = 0; i < TAM ; i++)
    {
        printf("%d", numeros[i]);
        printf(" ");
    }

}

void ordemInversa(int numeros[TAM])
{
    printf("\n");

    for(int i = TAM -1; i >= 0; i--)
    {
        printf("%d", numeros[i]);
        printf(" ");
    }

}



int main()
{

    int numeros[TAM];

    lerNumeros(numeros);

    imprimirNumeros(numeros);

    ordemInversa(numeros);


}
