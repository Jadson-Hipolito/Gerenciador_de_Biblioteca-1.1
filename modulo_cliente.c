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

void cadastrar_cliente(cliente *clientes, int *num_clientes) {
    if (*num_clientes < tamanho_max) {
        printf("Digite o nome do cliente: ");
        scanf("%s", clientes[*num_clientes].nome);

        printf("Digite o endereço do cliente: ");
        scanf("%s", clientes[*num_clientes].endereco);

        printf("Digite o telefone do cliente: ");
        scanf("%s", clientes[*num_clientes].telefone);

        (num_clientes)++;
    } else {
        printf("Limite máximo de clientes atingido.\n");
    }
}

void listar_clientes(const cliente *clientes, int *num_clientes) {
    printf("Lista de Clientes:\n");
    for (int i = 0; i < *num_clientes; i++) {
        printf("Nome: %s\n", clientes[i].nome);
        printf("Endereço: %s\n", clientes[i].endereco);
        printf("Telefone: %s\n", clientes[i].telefone);
        printf("\n");
    }
}

void editar_cliente(cliente *clientes, int *num_clientes) {
    int codigo;
    int mudar;
    char confir;
    printf("Digite o cpf do cliente ao qual deseja pesquisar: ");
    scanf("%d", &codigo);
    int indice = -1;
    for (int i = 0; i < *num_clientes; i++) {
        if (clientes[i].cpf == codigo) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        printf("Cliente não encontrado.\n");
        return;
    }
    printf("Informações atuais do cliente:\n");
    printf("Nome: %s\n", clientes[indice].nome);
    printf("Endereço: %s\n", clientes[indice].endereco);
    printf("Telefone: %s\n", clientes[indice].telefone);

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
  switch (mudar) {

   case 1:
    printf("Nome: ");
    scanf("%s", clientes[indice].nome);
    break;

   case 2:
    printf("Endereço: ");
    scanf("%s", clientes[indice].endereco);
    break;

   case 3:
    printf("Telefone: ");
    scanf("%s", clientes[indice].telefone);
    break;

   case 4:
    printf("Cpf: ");
    scanf("%s", clientes[indice].cpf);
    break;

   case 5:
    printf("Tem certeza que deseja deletar o registro desse cliente? Digite 0, para cancelar.");
    scanf("%s", &confir);
    if (confir != 0)
     for (int i = indice; i < (*num_clientes - 1); i++) {
      clientes[i] = clientes[i + 1];
     }
    (num_clientes)--;
    printf("Cliente deletado com sucesso.\n");

   case 0:
    printf("Programa finalizado.\n");
    break;
    
   default:
    printf("Opção inválida. Tente novamente.\n");
  }
}