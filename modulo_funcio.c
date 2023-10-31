// modulo_funcio.c - se trata de uma versão auterada de um modulo feito, com uso do ChatGpt, da openai.

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <locale.h>
#include "modulo_funcio.h"
#define tamanho_max 100 
funcionario funcionarios[tamanho_max]; 
int num_funcionarios = 0;

void menu_funcio(void){
  int mudar;
  printf("\n████████████████████████████████████████████████████████████████████████████\n");
  printf("████████████████████████████████████████████████████████████████████████████\n");
  printf("█████████████████████████████<Menu Funcionarios>████████████████████████████\n");
  printf("████████████████████████████████████████████████████████████████████████████\n");
  printf("████████████████████████████████████████████████████████████████████████████\n\n");
  printf("               ██████████████████████████████████████████████\n");
  printf("              ████████████████████████████████████████████████\n");
  printf("             █████ 1-Cadastrar                            █████\n");
  printf("            █████  2-Listar Funcionarios                   █████\n");
  printf("            █████  3-Editar Registro de livro              █████\n");
  printf("             █████ 0-Retornar para o menu principal       █████\n");
  printf("              ████████████████████████████████████████████████\n");
  printf("               ██████████████████████████████████████████████\n\n");
  scanf("%d", &mudar);
  switch (mudar) {

   case 1:
    cadastrar_funcionario(funcionarios, &num_funcionarios);
    break;

   case 2:
    listar_funcionarios(funcionarios, &num_funcionarios);
    break;

   case 3:
    editar_funcionario(funcionarios, &num_funcionarios);
    break;

   case 0:
    printf("Programa finalizado.\n");
    break;
    
   default:
    printf("Opção inválida. Tente novamente.\n");
  }
}

void cadastrar_funcionario(funcionario *funcionarios, int *num_funcionarios) {
    if (*num_funcionarios < 100) {
        printf("Digite o nome do funcionário: ");
        scanf("%s", funcionarios[*num_funcionarios].nome);

        printf("Digite o salário do funcionário: ");
        scanf("%f", &funcionarios[*num_funcionarios].salario);

        printf("Digite o telefone do funcionário: ");
        scanf("%s", &funcionarios[*num_funcionarios].telefone);

        printf("Digite o endereço do funcionário: ");
        scanf("%s", &funcionarios[*num_funcionarios].endereco);

        printf("Digite o CPF do funcionário: ");
        scanf("%s", &funcionarios[*num_funcionarios].cpf);

        (*num_funcionarios)++;
    } else {
        printf("Limite máximo de funcionários atingido.\n");
    }
}

void listar_funcionarios(const funcionario *funcionarios, int *num_funcionarios) {
    printf("Lista de Funcionários:\n");
    for (int i = 0; i < *num_funcionarios; i++) {
        printf("Nome: %s\n", funcionarios[i].nome);
        printf("Salário: %.2f\n", funcionarios[i].salario);
        printf("Telefone: %sf\n", funcionarios[i].telefone);
        printf("Endereço: %s\n", funcionarios[i].endereco);
        printf("CPF: %s\n", funcionarios[i].cpf);
        printf("\n");
    }
}

void editar_funcionario(funcionario *funcionarios, int *num_funcionarios) {
    char codigo[max_cpf];
    int mudar;
    char confir;
    int num_funcion = *num_funcionarios;
    printf("Digite o cpf do funcionário ao qual deseja pesquisar: ");
    scanf("%s", codigo);
    int indice = -1;
    for (int i = 0; i < num_funcion; i++) {
        if (strcmp(funcionarios[i].cpf, codigo) == 0) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        printf("Funcionário não encontrado.\n");
        return;
    }
    printf("Informações atuais do funcionário:\n");
    printf("Nome: %s\n", funcionarios[indice].nome);
    printf("Salário: %.2f\n", funcionarios[indice].salario);
    printf("Telefone: %s\n", funcionarios[indice].telefone);
    printf("Endereço: %s\n", funcionarios[indice].endereco);

  printf("\n████████████████████████████████████████████████████████████████████████████\n");
  printf("████████████████████████████████████████████████████████████████████████████\n");
  printf("█████████████████████████████<Editor de cliente>████████████████████████████\n");
  printf("████████████████████████████████████████████████████████████████████████████\n");
  printf("████████████████████████████████████████████████████████████████████████████\n\n");
  printf("               ██████████████████████████████████████████████\n");
  printf("              ████████████████████████████████████████████████\n");
  printf("             █████ 1-Mudar Nome do Funcionario            █████\n");
  printf("            █████  2-Mudar Salário do Funcionario          █████\n");
  printf("            █████  3-Mudar Endereço do Funcionario         █████\n");
  printf("            █████  4-Mudar Telefone do Funcionario         █████\n");
  printf("            █████  4-Mudar CPF do Funcionario              █████\n");
  printf("            █████  5-Deletar Registro do Funcionario       █████\n");
  printf("             █████ 0-Retornar para o menu principal       █████\n");
  printf("              ████████████████████████████████████████████████\n");
  printf("               ██████████████████████████████████████████████\n\n");
  scanf("%d", &mudar);
  switch (mudar) {

   case 1:
    printf("Nome: ");
    scanf("%s", funcionarios[indice].nome);
    break;

   case 2:
    printf("Salário: ");
    scanf("%s", funcionarios[indice].salario);
    break;

   case 3:
    printf("Endereço: ");
    scanf("%s", funcionarios[indice].endereco);
    break;

   case 4:
    printf("Telefone: ");
    scanf("%s", funcionarios[indice].telefone);
    break;

   case 5:
    printf("CPF: ");
    scanf("%s", funcionarios[indice].cpf);
    break;

   case 6:
    printf("Tem certeza que deseja deletar o registro desse cliente? Digite 0, para cancelar.");
    scanf("%s", &confir);
    if (confir != 0)
     for (int i = indice; i < (*num_funcionarios - 1); i++) {
      funcionarios[i] = funcionarios[i + 1];
     }
    (num_funcionarios)--;
    printf("Cliente deletado com sucesso.\n");

   case 0:
    printf("Programa finalizado.\n");
    break;
    
   default:
    printf("Opção inválida. Tente novamente.\n");
  }
}