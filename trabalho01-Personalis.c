#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 250

struct Treino
{
    char diaSemana[MAX];
    char nomeExercicio[MAX];
};
typedef struct Treino TTreino;

struct Aluno
{
    int id;
    int status;
    char nome[MAX];
    int idade;
    float peso, altura, imc;

    TTreino treinos[MAX];
    int quantidadeTreinos;

};
typedef struct Aluno TAluno;




void mostrarPessoas(TAluno *alunos, int n)
{
    int i;

    printf("\nPessoas cadastradas: ");

    for (i = 0; i < n; i++)
    {
        if (alunos[i].status == 1)
        {
            printf("\nID: %d\n", alunos[i].id);
            printf("Nome: %s", alunos[i].nome);
            printf("Idade: %d\n", alunos[i].idade);
            printf("Peso: %.2f\n", alunos[i].peso);
            printf("altura: %.2f\n", alunos[i].altura);
        }
    }
}

void pesquisaNome(TAluno *alunos, int n)
{
    char nome[MAX];
    int i;
    int encontrou = 0;

    printf("Entre com o nome para pesquisar: ");
    fgets(nome, MAX - 1, stdin);

    for (i = 0; i < n; i++)
    {
        if (alunos[i].status == 1 && strcmp(alunos[i].nome, nome) == 0)
        {
            encontrou = 1;
            printf("\nNome: %s", alunos[i].nome);
            printf("Idade: %d\n", alunos[i].idade);
            printf("Peso: %.2f\n", alunos[i].peso);
            printf("altura: %.2f\n", alunos[i].altura);
        }
    }

    if (!encontrou)
    {
        printf("Pessoa nao encontrada!\n");
    }
}

void cadastraPessoa(TAluno *alunos, int pos)
{
    alunos[pos].id = pos;
    alunos[pos].status = 1;

    printf("\nNome: ");
    fgets(alunos[pos].nome, MAX - 1, stdin);
    printf("Idade: ");
    scanf("%d", &alunos[pos].idade);
    getchar();  
    printf("Peso: ");
    scanf("%f", &alunos[pos].peso);
    getchar();  
    printf("Altura: ");
    scanf("%f", &alunos[pos].altura);
    getchar();  
}

void removeId(TAluno *alunos, int n)
{
    int id;

    printf("Entre com o Id: ");
    scanf("%d", &id);

    if (id >= 0 && id < n)
    {
        alunos[id].status = 0;
    }
}

void atualizarId(TAluno *alunos, int n)
{
    int id;

    printf("Entre com o Id: ");
    scanf("%d", &id);
    getchar();  

    if (id >= 0 && id < n)
    {
        printf("\nDigite o nome: ");
        fgets(alunos[id].nome, MAX - 1, stdin);
        printf("Digite a nova idade: ");
        scanf("%d", &alunos[id].idade);
        getchar();  
        printf("Peso: ");
        scanf("%f", &alunos[id].peso);
        getchar();  
        printf("Altura: ");
        scanf("%f", &alunos[id].altura);
        getchar();  


    }
}

void imprimeMenu()
{

    printf("                  _________   \n");
    printf("                /  20 KG   \\  \n");
    printf("               /            \\ \n");
    printf("              |      O       |\n");
    printf("               \\   20 KG    / \n");
    printf("                \\__________/  \n");

    printf("\n|------------Bem vindo ao Personalis--------------|\n");
    printf("|--Solucao para o profissional, na palma da mao---|\n");

    printf("\n|--------1 - Cadastrar aluno ---------------------|\n");
    printf("|--------2 - Mostrar alunos cadastrados ----------|\n");
    printf("|--------3 - Pesquisa por nome de aluno ----------|\n");
    printf("|--------4 - Remover aluno pelo ID ---------------|\n");
    printf("|--------5 - Atualizar cadastro de aluno pelo ID--|\n");
    printf("|--------6 - Calcular IMC de aluno pelo ID--------|\n");
    printf("|--------7 - Cadastrar Treino de aluno pelo ID----|\n");
    printf("|--------8 - Mostrar treino de aluno pelo ID------|\n");
    printf("|--------9 - Atualizar treino de aluno pelo ID----|\n");

    printf("\n|--------10 - Encerrar utilizacao de aplicativo---|\n");
}

void calcularImc(TAluno *alunos, int n)
{
    int id;
    float imc;

    printf("Entre com o ID so aluno que deseja calcular o IMC: ");
    scanf("%d", &id);

    if (id >= 0 && id < n && alunos[id].status == 1)
    {
        imc = alunos[id].peso / (alunos[id].altura * alunos[id].altura);
        alunos[id].imc = imc; 

        printf("Nome: %s", alunos[id].nome);
        printf("IMC: %.2f\n", imc);


        if (imc < 18.5)
            printf("Classificacao: Abaixo do peso\n");
        else if (imc < 25)
            printf("Classificacao: Peso normal\n");
        else if (imc < 30)
            printf("Classificacao: Sobrepeso\n");
        else if (imc < 35)
            printf("Classificacao: Obesidade grau I\n");
        else if (imc < 40)
            printf("Classificacao: Obesidade grau II\n");
        else
            printf("Classificacao: Obesidade grau III (morbida)\n");
    }
    else
    {
        printf("ID invalido ou aluno inativo.\n");
    }

}


void cadastrarTreino(TAluno *alunos, int n)
{
    int id, qtdPorDia;
    char *diasSemana[] = {"Segunda-feira", "Terca-feira", "Quarta-feira", "Quinta-feira", "Sexta-feira", "Sabado", "Domingo"};

    printf("Digite o ID do aluno: ");
    scanf("%d", &id);
    getchar(); 

    if (id >= 0 && id < n && alunos[id].status == 1)
    {
        printf("Quantos exercicios deseja cadastrar por dia da semana? ");
        scanf("%d", &qtdPorDia);
        getchar(); 

        for (int d = 0; d < 7; d++) 
        {
            for (int i = 0; i < qtdPorDia; i++)
            {
                if (alunos[id].quantidadeTreinos >= MAX)
                {
                    printf("Limite de treinos atingido para este aluno.\n");
                    return;
                }

                TTreino *treino = &alunos[id].treinos[alunos[id].quantidadeTreinos];
                snprintf(treino->diaSemana, MAX, "%s\n", diasSemana[d]);

                printf("Digite o nome do exercicio para %s (Exercicio %d): ", diasSemana[d], i + 1);
                fgets(treino->nomeExercicio, MAX - 1, stdin);

                alunos[id].quantidadeTreinos++;
            }
        }

        printf("Todos os treinos foram cadastrados com sucesso!\n");
    }
    else
    {
        printf("Aluno não encontrado ou inativo.\n");
    }


}


void mostrarTreino(TAluno *alunos, int n)
{
    int id;
    char *diasSemana[] = {
        "Segunda-feira\n", "Terca-feira\n", "Quarta-feira\n",
        "Quinta-feira\n", "Sexta-feira\n", "Sabado\n", "Domingo\n"
    };

    printf("Digite o ID do aluno: ");
    scanf("%d", &id);
    getchar(); 

    if (id >= 0 && id < n && alunos[id].status == 1)
    {
        if (alunos[id].quantidadeTreinos == 0)
        {
            printf("Nenhum treino cadastrado para este aluno.\n");
            return;
        }

        printf("\nTreinos do aluno %s:\n", alunos[id].nome);

        for (int d = 0; d < 7; d++)
        {
            int encontrou = 0;
            for (int i = 0; i < alunos[id].quantidadeTreinos; i++)
            {
                if (strcmp(alunos[id].treinos[i].diaSemana, diasSemana[d]) == 0)
                {
                    if (!encontrou)
                    {
                        printf("\n%s", diasSemana[d]); 
                        encontrou = 1;
                    }
                    printf(" - %s", alunos[id].treinos[i].nomeExercicio);
                }
            }
        }
    }
    else
    {
        printf("Aluno nao encontrado ou inativo.\n");
    }

}

void atualizarTreino(TAluno *alunos, int n)
{
    int id, qtdPorDia;
    char *diasSemana[] = {"Segunda-feira", "Terca-feira", "Quarta-feira", "Quinta-feira", "Sexta-feira", "Sabado", "Domingo"};

    printf("Digite o ID do aluno para atualizar os treinos: ");
    scanf("%d", &id);
    getchar(); 

    if (id >= 0 && id < n && alunos[id].status == 1)
    {

        alunos[id].quantidadeTreinos = 0;
        printf("Todos os treinos anteriores foram removidos.\n");

        printf("Quantos exercicios deseja cadastrar por dia da semana? ");
        scanf("%d", &qtdPorDia);
        getchar(); 

        for (int d = 0; d < 7; d++) 
        {
            for (int i = 0; i < qtdPorDia; i++)
            {
                if (alunos[id].quantidadeTreinos >= MAX)
                {
                    printf("Limite de treinos atingido para este aluno.\n");
                    return;
                }

                TTreino *treino = &alunos[id].treinos[alunos[id].quantidadeTreinos];
                snprintf(treino->diaSemana, MAX, "%s\n", diasSemana[d]);

                printf("Digite o nome do exercicio para %s (Exercicio %d): ", diasSemana[d], i + 1);
                fgets(treino->nomeExercicio, MAX - 1, stdin);

                alunos[id].quantidadeTreinos++;
            }
        }

        printf("Treinos atualizados com sucesso!\n");
    }
    else
    {
        printf("Aluno não encontrado ou inativo.\n");
    }

}

int main()
{
    TAluno *alunos = NULL; 
    int n = 0, op, capacidade = 2;

    alunos = (TAluno *)malloc(capacidade * sizeof(TAluno));
    if (alunos == NULL)
    {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }

    do
    {
        imprimeMenu();
        scanf("%d", &op);
        getchar(); 

        switch (op)
        {
        case 1:
            if (n >= capacidade)
            {
                capacidade *= 2; 
                alunos = (TAluno *)realloc(alunos, capacidade * sizeof(TAluno));
                if (alunos == NULL)
                {
                    printf("Erro ao alocar memoria!\n");
                    return 1;
                }
            }
            cadastraPessoa(alunos, n);
            n++;
            break;

        case 2:
            mostrarPessoas(alunos, n);
            break;

        case 3:
            pesquisaNome(alunos, n);
            break;

        case 4:
            removeId(alunos, n);
            break;

        case 5:
            atualizarId(alunos, n);
            break;

        case 6:
            calcularImc(alunos, n);
            break;

        case 7:
            cadastrarTreino(alunos, n);
            break;

        case 8:
            mostrarTreino(alunos, n);
            break;

        case 9:
            atualizarTreino(alunos, n);
            break;

        case 10:
            break;

        default:
            printf("Opcao Invalida\n");
        }
    } while (op != 10);

    free(alunos);
    return 0;
}
