#include <stdio.h>

int main()
{
	
	float salario;
	float imposto;
	
	
	
	printf("Entre com o seu salario R$ ");
	scanf("%f", &salario);
	
	if (salario <= 1903.98)
	{
		imposto = 0;

	}
	
	else if(salario <= 2826,65)
	{
		imposto = (salario * 0.075);
	}
	
	else if(salario <= 3751,05)
	{
		imposto = (salario <= 0.15);
	
	}
	
	else if(salario <= 4664,68)
	{
		imposto = (salario <= 0,225);
	}
	
	else
	{
		imposto = (salario <= 0,275);
	}
	
	
	printf("O valor a ser pago sera R$ %f ", imposto);
	
	
	
}
