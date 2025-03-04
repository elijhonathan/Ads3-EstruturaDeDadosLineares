#include <stdio.h>


#define TAM 3

void pegarNumeros(int numeros[TAM])
{
    printf("Digite %d numeros: ", TAM);
    
    for(int i = 0; i < TAM ; i++)
    {
        scanf("%d", &numeros[i]);
        
    }

}

int numerosPar(int numeros[TAM])
{
    int par = 0;

    for(int i = 0; i < TAM ; i++)
    {
        if(numeros[i] % 2 == 0)
        {
            par++;
        }
        
    }

    return par;

}

int  numerosImpar(int numeros[TAM])
{
    int impar =0;

    for(int i = 0; i < TAM ; i++)
    {
        if(numeros[i] % 2 != 0)
        {
            impar++;
        }
        
    }

    return impar;

}

int  numeroMaior( int numeros[TAM])
{
    int maior = numeros[0];


    for(int i = 0; i < TAM ; i++)
    {
        if(maior < numeros[i])
        {
            maior = numeros[i];
        }
        
    }

    return maior;

}

int  numeroMenor(int numeros[TAM])
{
    int menor = numeros[0];

    for(int i = 0; i < TAM ; i++)
    {
        if(menor > numeros[i])
        {
            menor = numeros[i];
        }
        
    }

    return menor;

}

void resultado(int par, int impar, int maior, int menor)
{
    printf("Numero de pares: %d\n", par);
    printf("Numero de impares: %d\n", impar);
    printf("Numero maior: %d\n", maior);
    printf("Numero menor: %d", menor);

}



int main()
{
    int numeros[TAM];

    pegarNumeros(numeros);

    int par = numerosPar(numeros);

    int impar = numerosImpar(numeros);

    int maior = numeroMaior(numeros);

    int menor = numeroMenor(numeros);

    resultado(par, impar, maior, menor);

}
