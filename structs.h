
struct cliente{
    int codigo;
    char nome[100];
    char endereco[200];
    int telefone;
    int diaNascimento;
    int mesNascimento;
    int anoNascimento;
};
typedef struct cliente cliente;


//� FUNCIONARIO = c�digo, nome, telefone, fun��o, salario, tipo (tempor�rio ou fixo)

struct funcionario{
    int codigo;
    char nome[100];
    int telefone;
    char cargo[100];
    float salario;
    int fixo;

};
typedef struct funcionario funcionario;
