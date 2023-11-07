// modulo_cliente.c - Se treta de uma versão  alterada de um ou mais codigos feitos pelo ChatGPT (Openai).

#include <stdio.h>
#include <locale.h>
#include "modulo_cliente.h"
#define tamanho_max 100
cliente clientes[tamanho_max]; 
int num_clientes = 0;

void menu_cliente(void){
    int mudar;
  int novo_local;
  printf("\n████████████████████████████████████████████████████████████████████████████\n");
  printf("████████████████████████████████████████████████████████████████████████████\n");
  printf("█████████████████████████████<Menu Cliente>████████████████████████████\n");
  printf("████████████████████████████████████████████████████████████████████████████\n");
  printf("████████████████████████████████████████████████████████████████████████████\n\n");
  printf("               ██████████████████████████████████████████████\n");
  printf("              ████████████████████████████████████████████████\n");
  printf("             █████ 1-Cadastrar                            █████\n");
  printf("            █████  2-Listar Clientes                       █████\n");
  printf("            █████  3-Editar registro de cliente            █████\n");
  printf("             █████ 0-Retornar para o menu principal       █████\n");
  printf("              ████████████████████████████████████████████████\n");
  printf("               ██████████████████████████████████████████████\n\n");
  scanf("%d", &mudar);
  switch (mudar) {

   case 1:
    cadastrar_cliente(clientes, &num_clientes);
    break;

   case 2:
    listar_clientes(clientes, &num_clientes);
    break;

   case 3:
    editar_cliente(clientes, &num_clientes);
    break;

   case 0:
    printf("Programa finalizado.\n");
    break;
    
   default:
    printf("Opção inválida. Tente novamente.\n");
  }
}

#include <stdio.h>

#define tamanho_max 100

typedef struct {
    char nome[max_nome];
    char endereco[max_nome];
    char telefone[max_nome];
    char cpf[max_nome];
    int id;
    int  ativ;
} cliente;

void cadastrar_cliente(cliente *clientes, int *num_clientes) {
    if (*num_clientes < tamanho_max) {
        FILE *arquivo = fopen("clientes.txt", "a"); // Abra o arquivo em modo de escrita (append).

        if (arquivo != NULL) {
            printf("Digite o nome do cliente: ");
            scanf("%s", clientes[*num_clientes].nome);

            printf("Digite o endereço do cliente: ");
            scanf("%s", clientes[*num_clientes].endereco);

            printf("Digite o telefone do cliente: ");
            scanf("%s", clientes[*num_clientes].telefone);

            clientes[*num_clientes].ativ = 1; // Adicione automaticamente a atividade.

            // Salve os detalhes do cliente no arquivo.
            fprintf(arquivo, "Nome: %s\nEndereço: %s\nTelefone: %s\nAtividade: %d\n\n",
                    clientes[*num_clientes].nome, clientes[*num_clientes].endereco,
                    clientes[*num_clientes].telefone, clientes[*num_clientes].ativ);

            (*num_clientes)++;
            fclose(arquivo);
        } else {
            printf("Erro ao abrir o arquivo.\n");
        }
    } else {
        printf("Limite máximo de clientes atingido.\n");
    }
}

int main() {
    cliente clientes[tamanho_max];
    int num_clientes = 0;

    cadastrar_cliente(clientes, &num_clientes);

    return 0;
}

void listar_clientes() {
    FILE *arquivo;
    arquivo = fopen("clientes.txt", "r"); // Abre o arquivo em modo de leitura

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    printf("Lista de Clientes:\n");
    
    char linha[100]; // Suponha que cada linha do arquivo tenha no máximo 100 caracteres
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        printf("%s", linha);
    }

    fclose(arquivo); // Fecha o arquivo
}

void editar_cliente() {
    FILE *arquivo;
    arquivo = fopen("clientes.txt", "r+"); // Abre o arquivo em modo de leitura e escrita

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    int codigo;
    int mudar;
    char confir;
    printf("Digite o cpf do cliente ao qual deseja pesquisar: ");
    scanf("%d", &codigo);
    
    char linha[100]; // Suponha que cada linha do arquivo tenha no máximo 100 caracteres
    int encontrado = 0;
    long int posicao = ftell(arquivo); // Para controlar a posição do arquivo
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        if (sscanf(linha, "CPF: %d", &codigo) == 1) {
            encontrado = 1;
            break;
        }
        posicao = ftell(arquivo); // Atualiza a posição do arquivo
    }

    if (!encontrado) {
        printf("Cliente não encontrado.\n");
        fclose(arquivo);
        return;
    }

    printf("Informações atuais do cliente:\n");
    printf("%s", linha);

    printf("\n████████████████████████████████████████████████████████████████████████████\n");
    printf("████████████████████████████████████████████████████████████████████████████\n");
    printf("█████████████████████████████<Editor de cliente>████████████████████████████\n");
    printf("████████████████████████████████████████████████████████████████████████████\n");
    printf("████████████████████████████████████████████████████████████████████████████\n\n");
    printf("               ██████████████████████████████████████████████\n");
    printf("              ████████████████████████████████████████████████\n");
    printf("             █████ 1-Mudar Nome do Cliente                █████\n");
    printf("            █████  2-Mudar Endereço do Cliente             █████\n");
    printf("            █████  3-Mudar Numero do Cliente               █████\n");
    printf("            █████  4-Mudar CPF do Cliente                  █████\n");
    printf("            █████  5-Deletar Registro do Cliente           █████\n");
    printf("             █████ 0-Retornar para o menu principal       █████\n");
    printf("              ████████████████████████████████████████████████\n");
    printf("               ██████████████████████████████████████████████\n\n");
    scanf("%d", &mudar);

    char novoValor[100]; // Suponha que cada campo tem no máximo 100 caracteres
    switch (mudar) {
        case 1:
            printf("Nome: ");
            scanf("%s", novoValor);
            sprintf(linha, "Nome: %s\n", novoValor);
            break;
        case 2:
            printf("Endereço: ");
            scanf("%s", novoValor);
            sprintf(linha, "Endereço: %s\n", novoValor);
            break;
        case 3:
            printf("Telefone: ");
            scanf("%s", novoValor);
            sprintf(linha, "Telefone: %s\n", novoValor);
            break;
        case 4:
            printf("Cpf: ");
            scanf("%s", novoValor);
            sprintf(linha, "CPF: %s\n", novoValor);
            break;
        case 5:
            printf("Tem certeza que deseja marcar o cliente como inativo? Digite 0 para cancelar ou 1 para confirmar: ");
            scanf(" %c", &confir);
            if (confir == '1') {
              linha[strlen(linha) - 1] = '0'; // Altera o último caractere para '0' (inativo).
              fseek(arquivo, posicao, SEEK_SET);
              fprintf(arquivo, "%s", linha); // Atualiza o registro no arquivo.
              printf("Cliente marcado como inativo.\n");
    }
    break;
        case 6:
            printf("Tem certeza que deseja deletar o registro deste cliente? Digite 0 para cancelar ou 1 para confirmar: ");
            scanf(" %c", &confir);
            if (confir == '1') {
              char id[100]; // Suponha que cada campo tem no máximo 100 caracteres
              sscanf(linha, "ID: %s", id); // Extrai o ID do cliente
              sprintf(linha, "ID: %s\nAtividade: 0\n", id); // Marca o cliente como inativo
             fseek(arquivo, posicao, SEEK_SET);
             fprintf(arquivo, "%s", linha); // Atualiza o registro no arquivo.
             printf("Cliente deletado com sucesso.\n");
    }
    break;
        case 0:
            printf("Programa finalizado.\n");
            break;
        default:
            printf("Opção inválida. Tente novamente.\n");
    }

    // Fecha o arquivo após as operações
    fclose(arquivo);
}