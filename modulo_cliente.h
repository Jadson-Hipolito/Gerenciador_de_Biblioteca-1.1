// modulo_cliente.h - Se treta de uma versão  alterada de um ou mais codigos feitos pelo ChatGPT (Openai).

#ifndef CLIENTE_H
#define CLIENTE_H
#define max_nome 50
#define TAMANHO_MAX_CLIENTES 100

typedef struct {
    char nome[max_nome];
    char endereco[max_nome];
    char telefone[max_nome];
    char cpf[max_nome];
} cliente;

void menu_cliente(void);
void cadastrar_cliente(cliente *clientes, int *num_clientes);
void listar_clientes(const cliente *clientes, int *num_clientes);
void editar_cliente(cliente *clientes, int *num_clientes);
// Outras funções relacionadas aos clientes, se necessário

#endif // CLIENTE_H