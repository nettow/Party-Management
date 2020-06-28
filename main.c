#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


struct cliente
{

    int codigo;
    char nome[100];
    char endereco[200];
    int telefone;
    int diaNascimento;
    int mesNascimento;
    int anoNascimento;

};
typedef struct cliente cliente;

void main()
{
    setlocale(LC_ALL, "portuguese");
    int option;

    FILE *clientes;

    if ((clientes = fopen("clientes.txt", "r+b")) == NULL){
        printf("Arquivo não existe ... criando arquivo!\n");
        if ((clientes = fopen("clientes.txt", "w+b")) == NULL){
            printf("Erro na criação do arquivo!!");
            exit(1);}
    }

    do{

        menu();
        scanf("%d",&option);
        switch(option){
        case 1:
            system("cls");
            cadastraCliente(clientes);
            };
        break;

        scanf("%d",&option);
    }while(option != 9);
}


void menu(){
    printf("Bem vindo ao salaão de festa\n");
    printf("1 - Cadastrar cliente\n");
    printf("9 - Sair do programa\n\n");

}

void cadastraCliente(FILE *arquivo)
{
    cliente fulano;
    printf("Digite o nome do cliente :");
    fflush(stdin);
    scanf("%s", &fulano.nome);


    printf("Digite o codigo do cliente :");
    fflush(stdin);
    scanf("%d", &fulano.codigo);

    printf("Digite o endereco do cliente :");
    fflush(stdin);
    scanf("%s", &fulano.endereco);

    printf("Digite o telefone do cliente :");
    fflush(stdin);
    scanf("%d", &fulano.telefone);

    printf("Digite a sua data de nascimento (ex com espacos: 02 5 2003):");
    fflush(stdin);
    scanf("%d %d %d", &fulano.diaNascimento,&fulano.mesNascimento,&fulano.anoNascimento);

//   if (codigoExiste)
  //      printf("%s não foi cadastrado pois o codigo ja existe);
    //else
    printf("%s cadastrado com sucesso.\n", fulano.nome);
    fseek(arquivo, 0, SEEK_END);
    fwrite(&fulano, sizeof(fulano), 1, arquivo);
    fflush(arquivo);
}
