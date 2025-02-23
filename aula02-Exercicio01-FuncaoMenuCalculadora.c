#include <stdio.h>

void exibe_menu()
{
    printf("Escolha a opcao:\n");
    printf("1 - Somar:\n");
    printf("2 - Subtrair:\n");
    printf("3 - Multiplicar:\n");
    printf("4 - Dividir:\n");
    printf("5 - Encerra:\n\n");
}

float soma(float a,float b)
{
    float resultado = a + b;
    return resultado;
}

float subtrai(float a,float b)
{
    float resultado = a - b;
    return resultado;
}

float multiplica(float a,float b)
{
    float resultado = a * b;
    return resultado;
}

float dividi(float a,float b)
{
    float resultado = a / b;
    return resultado;
}



int main()
{

    int opcao = 0;
    float a, b, resultado;

    while(opcao != 5)
    {
        exibe_menu();

        scanf("%d", &opcao);

        if (opcao >=1 && opcao <=4)
        {
            printf("Entre com dois numeros: ");
            scanf("%f %f", &a, &b);
        }

        switch (opcao)
        {
            case 1:
                resultado = soma(a,b);
                printf("Soma: %.2f\n", resultado);
                break;
            case 2:
                resultado = subtrai(a,b);
                printf("Subtrai: %.2f\n", resultado);
                break;
            case 3:
                resultado = multiplica(a,b);
                printf("Multiplica: %.2f\n", resultado);
                break;
            case 4:
                resultado = dividi(a,b);
                printf("Dividi: %.2f\n", resultado);
                break;
            case 5:
                printf("Programa encerrado");
                break;
            default:
                printf("Opcao invalida\n");
                break;
        }
    }

}
