/*  Autor..: Otávio Augusto Zangelmi Costa
    Data...: 08/09/2024
    OB.....: Sistema de cadastro de cliente(s)
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

// Função para posicionar o cursor na tela

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = (short)x;
    coord.Y = (short)y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Registro de dados

typedef struct
{
    int idade;
    float salario;
    char sexo;
} Cadastro;

// limitando os cadastros

Cadastro usuario[5];

int x = 0;

// Função para construir a tela

void tela()
{
    system("cls");

    for (int lin = 1; lin < 25; lin++)
    {
        gotoxy(1, lin);
        printf("|");
        gotoxy(79, lin);
        printf("|");
    }

    gotoxy(1, 1);
    printf("+-----------------------------------------------------------------------------+");
    gotoxy(1, 4);
    printf("+-----------------------------------------------------------------------------+");
    gotoxy(1, 22);
    printf("+-----------------------------------------------------------------------------+");
    gotoxy(1, 24);
    printf("+-----------------------------------------------------------------------------+");

    gotoxy(3, 2);
    printf("UNICV");
    gotoxy(3, 3);
    printf("SISTEMA DE REGISTRO DE CLIENTE");
    gotoxy(60, 2);
    printf("ESTRUTURA DE DADOS");
    gotoxy(61, 3);
    printf("Otavio O Terrivel");
    gotoxy(3, 23);
    printf("MSG: ");
}

// Função para consultar os cadastros

void consultar()
{
    int y;

    tela();
    gotoxy(2, 5);
    printf("Usuarios Cadastrados:\n");

    if (x == 0)
    {
        gotoxy(2, 7);
        printf("Nenhum usuario cadastrado.");
    }
    else
    {
        for (y = 0; y < x; y++)
        {
            gotoxy(2, 7 + y);
            printf("Usuario %d: Idade: %d, Salario: %.2f, Sexo: %c", y + 1, usuario[y].idade, usuario[y].salario, usuario[y].sexo);
        }
    }

    gotoxy(2, 23);
    printf("Pressione qualquer tecla para voltar ao menu...");
    getch();
}

// Função para cadastrar um usuário

void cadastro()
{
    int resp;

    // verificar o limite de cadastros

    if (x >= 5)
    {
        tela();
        gotoxy(7, 23);
        printf("Limite de cadastros atingido.");
        getch();
        return;
    }

    system("color 0A");

    // Coletando dados e aplicando condicoes

    do
    {
        tela();
        gotoxy(26, 10);
        printf("Digite sua idade.......: ");

        gotoxy(26, 12);
        printf("Digite seu salario.....: ");

        gotoxy(26, 14);
        printf("Digite seu sexo (M/F)..: ");

        do
        {
            gotoxy(51, 10);
            scanf("%d", &usuario[x].idade);
            if (usuario[x].idade < 18)
            {
                gotoxy(7, 23);
                printf("Idade invalida. Digite novamente (Minimo 18).");
                getch();
                gotoxy(7, 23);
                printf("                                             ");
                gotoxy(51, 10);
                printf("                          ");
            }
        } while (usuario[x].idade < 18);

        do
        {
            gotoxy(51, 12);
            scanf("%f", &usuario[x].salario);
            if (usuario[x].salario < 2000)
            {
                gotoxy(7, 23);
                printf("Salario invalido. Digite novamente (Minimo 2000).");
                getch();
                gotoxy(7, 23);
                printf("                                                 ");
                gotoxy(51, 12);
                printf("                        ");
            }
        } while (usuario[x].salario < 2000);

        do
        {
            gotoxy(51, 14);
            printf("            ");
            gotoxy(51, 14);
            scanf(" %c", &usuario[x].sexo);
            if (usuario[x].sexo != 'M' && usuario[x].sexo != 'F')
            {
                gotoxy(7, 23);
                printf("Sexo invalido. Digite novamente (Use M ou F).");
                getch();
                gotoxy(7, 23);
                printf("                                             ");
                gotoxy(51, 14);
                printf("                        ");
            }
        } while (usuario[x].sexo != 'M' && usuario[x].sexo != 'F');

        x++;
        gotoxy(7, 23);
        printf("Quer cadastrar outro: 1-Sim, 2-Nao: ");
        scanf("%d", &resp);
        gotoxy(7, 23);
        printf("                                              ");
    } while (resp == 1 && x < 5);
}
int main()
{
    int msg;

    system("color 0A");

    // printar na tela as opções

    do
    {
        tela();
        gotoxy(30, 10);
        printf("1-Cadastro");

        gotoxy(30, 12);
        printf("2-Consultar");

        gotoxy(30, 14);
        printf("3-Finalizar programa");

        gotoxy(3, 23);
        printf("MSG: ");
        scanf("%d", &msg);

        gotoxy(7, 23);
        printf("                   ");

        // switch case para as respostas

        switch (msg)
        {
        case 1:
            cadastro();
            break;
        case 2:
            consultar();
            break;
        case 3:
            break;
        default:
            gotoxy(7, 23);
            printf("Opcao invalida. Tente novamente.");
            getch();
            gotoxy(7, 23);
            printf("                                ");
            break;
        }
    } while (msg != 3);

    return 0;
}