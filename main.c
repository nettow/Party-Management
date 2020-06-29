#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "structs.h"
#include "functions.h"

void main()
{
    setlocale(LC_ALL, "portuguese");
    int option;

    FILE *clientes;
    FILE *funcionarios;


    if ((clientes = fopen("clientes.txt", "r+b")) == NULL)
    {
        printf("Arquivo de clientes não existe, criando ... \n");
        if ((clientes = fopen("clientes.txt", "w+b")) == NULL)
        {
            printf("Erro na criação do arquivo!!");
            exit(1);
        }
    }
    if ((funcionarios = fopen("funcionarios.txt", "r+b")) == NULL)
    {
        printf("Arquivo de funcionarios não existe, criando ... \n");
        if ((funcionarios = fopen("funcionarios.txt", "w+b")) == NULL)
        {
            printf("Erro na criação do arquivo!!");
            exit(1);
        }
    }

    do{
        menu();
        scanf("%d",&option);
        switch(option){
        case 1:
            system("cls");
            cadastraCliente(clientes);
        break;
        case 2:
            system("cls");
            cadastraFuncionario(funcionarios);
        break;

        }
        menu();
        scanf("%d",&option);
    }while(option != 9);
}
