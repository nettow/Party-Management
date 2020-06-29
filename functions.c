#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <time.h>
#include "structs.h"

void menu(){
    printf("Bem vindo ao salaão de festa\n");
    printf("1 - Cadastrar cliente\n");
    printf("2 - Cadastrar funcionario\n");
    printf("9 - Sair do programa\n\n");
}

void cadastraCliente(FILE *arquivo)
{
    cliente fulano;

    printf("Digite o nome do cliente :");
    fflush(stdin);
    scanf("%s", &fulano.nome);

    printf("Digite o endereco do cliente :");
    fflush(stdin);
    scanf("%s", &fulano.endereco);

    printf("Digite o telefone do cliente :");
    fflush(stdin);
    scanf("%d", &fulano.telefone);

    printf("Digite a sua data de nascimento :");
    fflush(stdin);
    scanf("%d",&fulano.anoNascimento);

    fulano.codigo = valorAleatorio(600);
    fseek(arquivo, 0, SEEK_SET);
    fread(&fulano, sizeof(fulano), 1, arquivo);

    fwrite(&fulano, sizeof(fulano), 1, arquivo);
    fclose(arquivo);
    fflush(stdin);
    printf("\Dados salvos do cliente %s, seu codigo eh: %d\n\n",fulano.nome,fulano.codigo);
}

void cadastraFuncionario(FILE *arquivo)
{
    funcionario func;

    printf("Digite o nome do funcionario :");
    fflush(stdin);
    scanf("%s", &func.nome);

    printf("Digite o telefone do funcionario :");
    fflush(stdin);
    scanf("%d", &func.telefone);

    printf("Digite o cargo do funcionario :");
    fflush(stdin);
    scanf("%s",&func.cargo);

    printf("Digite o salario do funcionario :");
    fflush(stdin);
    scanf("%f",&func.salario);

    func.codigo = valorAleatorio(1000);
    printf("Digite [1] para funcionario fixo e [2] para temporario :");
    fflush(stdin);
    scanf("%d", &func.fixo);

    fseek(arquivo, 0, SEEK_SET);
    fread(&func, sizeof(func), 1, arquivo);

    fwrite(&func, sizeof(func), 1, arquivo);
    fclose(arquivo);
    fflush(stdin);
    printf("\nFuncionario salvo : %s %s %d %f %d\n", func.nome, func.cargo,func.telefone,func.salario,func.codigo);
}

int valorAleatorio(int maximo){
    srand(time(NULL));
    return rand() % maximo;
}

int codigoExiste(FILE *arquivo, int code){
    cliente fulano;

    fseek(arquivo, 0, SEEK_SET);
    fread(&fulano,sizeof(fulano),1,arquivo);

    while (!feof(arquivo)){
        if (fulano.codigo == code){
            fclose(arquivo);
            return 1;
        }
        fread(&fulano, sizeof(fulano), 1, arquivo);
    }
    fclose(arquivo);
    return 0;

}
