#include<stdio.h>

float calcula_imc(float p, float a)
{
    float imc;
    imc = (p)/(a * a);
    return imc;
}


int main()
{

    float altura, peso;
    

    printf("Entre com o peso: ");
    scanf("%f", &peso);

    printf("Entre com a altura: ");
    scanf("%f", &altura);



    float resultado = calcula_imc(peso, altura);

    printf("IMC: %f\n", resultado);

    return 0;

}
